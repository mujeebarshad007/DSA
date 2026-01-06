#include <list>
template <typename K, typename T>
class unordered_map
{
private:
    std::list<std::pair<const K, T>> *table;
    int m, n;
    int hash(const K &key) const
    {
        return (key % m);
    }
    typename std::list<std::pair<const K, T>>::iterator find(std::list<std::pair<const K, T>> &L, const K &key)
    {
        typename std::list<std::pair<const K, T>>::iterator it_list = L.begin();
        while (it_list != L.end())
        {
            if (it_list->first == key)
                return it_list;
            ++it_list;
        }
        return it_list;
    }

public:
    unordered_map(int s = 47)
    {
        m = s;
        n = 0;
        table = new std::list<std::pair<const K, T>>[s];
    }
    class iterator
    {
        int idx;
        typename std::list<std::pair<const K, T>>::iterator it_list;
        unordered_map<K, T> *um;

    public:
        friend class unordered_map;

        iterator &operator++()
        {

            ++it_list;
            if (it_list == um->table[idx].end())
            {
                ++idx;
                while (idx < um->m && um->table[idx].empty())
                {
                    ++idx;
                }
                if (idx < um->m)
                {
                    it_list = um->table[idx].begin();
                }
                else
                {
                    idx = um->m - 1;
                    it_list = um->table[idx].end();
                }
            }
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const iterator &rhs) const
        {
            return (this->idx == rhs.idx && this->it_list == rhs.it_list);
        }

        bool operator!=(const iterator &rhs) const
        {
            return (this->idx != rhs.idx || this->it_list != rhs.it_list);
        }

        const std::pair<const K, T> *operator->() const
        {
            return &(*it_list);
        }
    };

    iterator begin()
    {
        iterator it;
        it.um = this;
        it.idx = 0;
        while (it.idx < m && table[it.idx].empty())
        {
            ++it.idx;
        }
        if (it.idx == m)
        {
            it.idx = m - 1;
        }
        it.it_list = table[it.idx].begin();
        return it;
    }
    iterator end()
    {
        iterator it;
        it.um = this;
        it.idx = m - 1;
        it.it_list = table[it.idx].end();
        return it;
    }

    bool empty() const
    {
        return n == 0;
    }
    iterator erase(iterator pos)
    {
        iterator next = pos;
        ++next;
        table[pos.idx].erase(pos.it_list);
        --n;
        return next;
    }

    unordered_map &operator=(const unordered_map &rhs)
    {
        if (this != &rhs)
        {
            delete[] table;
            m = rhs.m;
            n = rhs.n;
            table = new std::list<std::pair<const K, T>>[m];
            for (int i = 0; i < m; i++)
            {
                table[i] = rhs.table[i];
            }
        }
        return *this;
    }
    int size() const
    {
        return n;
    }

    std::pair<iterator, bool> insert(const std::pair<const K, T> &p)
    {
        K key = p.first;
        int h = hash(p.first);
        int idx = h;
        for (int i = 1; i <= m; ++i)
        {
            if (table[idx].first == -1 && table[idx].first == -2)
            {
                table[idx] = p;
                break;
            }
            else
            {
                idx = (h + i) % m;
            }
        }
    }
    void swap(unordered_map &rhs)
    {

        // map contain main three things
        // table
        // m
        // n

        // if we just swap them the internal stuff also get swapped
        std::list<std::pair<const K, T>> *temp = table;
        table = rhs.table;
        rhs.table = temp;

        int temp2 = m;
        m = rhs.m;
        rhs.m = temp2;

        int temp3 = n;
        n = rhs.n;
        rhs.n = temp3;
    }

    T &at(const K &key)
    {
        int h = hash(key);
        typename std::list<std::pair<const K, T>>::iterator it;
        it = find(table[h], key);
        if (it == table[h].end())
        {
            throw "key not found";
        }
        else
        {
            return it->second;
        }
    }
    T &operator[](const K &key)
    {
        int h = hash(key);
        typename std::list<std::pair<const K, T>>::iterator it;
        it = find(table[h], key);
        if (it == table[h].end())
        {
            table[h].push_back({key, T()});
            ++n;
            return table[h].back().second;
        }
        return it->second;
    }
    int count(const K &key)
    {
        int h = hash(key);
        return (find(table[h], key) != table[h].end());
    }

    iterator find(const K &key)
    {
        int h = hash(key);
        typename std::list<std::pair<const K, T>>::iterator it_list;
        it_list = find(table[h], key);

        iterator it;
        it.um = this;
        it.idx = h;
        it.it_list = it_list;
        return it;
    }

    bool contains(const K &key)
    {
        return count(key) == 1;
    }

    int bucket_count() const
    {
        return m;
    }
    int bucket_size(int idx)
    {
        return table[idx].size();
    }

    int bucket(const K &key)
    {
        return hash(key);
    }

    float load_factor() const
    {
        return (float)n / m;
        // used typecast here
    }
    float max_load_factor() const
    {
        return 1.0;
    }
    void rehash(int new_size_m)
    {
        unordered_map<K, T> temp(new_size_m);
        for (int i = 0; i < m; ++i)
        {
            typename std::list<std::pair<const K, T>>::iterator it;
            it = table[i].begin();
            while (it != table[i].end())
            {
                std::pair<const K, T> p(it->first, it->second);
                temp.insert(p);
                ++it;
            }
        }
        swap(temp);
    }
    void reserve(int count)
    {
        if (count > m)
        {
            rehash(count);
        }
    }
    void clear()
    {
        delete[] table;
        table = new std::list<std::pair<const K, T>>[m];
        n = 0;
    }
    ~unordered_map()
    {
        delete[] table;
    }
};