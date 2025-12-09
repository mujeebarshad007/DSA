#include <list>
#include <utility>

template <typename K, typename T>
class unordered_map
{
public:
    using value_type = std::pair<const K, T>;

private:
    std::list<std::pair<const K, T>> *table;
    int m, n;
    int hash(const K &key) const
    {
        return key % m;
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
    unordered_map(int s = 23)
    {
        m = s;
        n = 0;
        table = new std::list<std::pair<K, T>>[s];
    }

    class iterator
    {
        int idx;
        typename std::list<std::pair<const K, T>>::iterator t_list;
        unordered_map<const K, T> *um;

    public:
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

    std::pair<iterator, bool> insert(const std::pair<K, T> &p)
    {
        int h = hash(p.first);
        typename std::list<std::pair<const K, T>>::iterator it_list;
        it_list = find(table[h], p.first);
        if (it_list == table[h].end())
        {
            table[h].push_back(p);
            it_list = --table[h].end();
            ++n;
            return {iterator(h, it_list, this), true};
        }
        else
        {
            return {iterator(h, it_list, this), false};
        }
    }
};