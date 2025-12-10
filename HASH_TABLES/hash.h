#include <list>
#include <utility>
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

        std::pair<const K, T> *operator->()
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

    std::pair<iterator, bool> insert(const std::pair<const K, T> &p)
    {
        int h = hash(p.first);
        typename std::list<std::pair<const K, T>>::iterator it_list;
        it_list = find(table[h], p.first);
        iterator it;
        it.um = this;
        it.idx = h;

        if (it_list == table[h].end())
        {
            table[h].push_back(p);
            it.it_list = --table[h].end();
            ++n;
            return {it, true};
        }
        else
        {
            it.it_list = it_list;
            return {it, false};
        }
    }
    void clear()
    {
        delete[] table;
    }
};