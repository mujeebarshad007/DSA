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

    typename std::list<std::pair<const K, T>>::iterator find(const std::list<std::pair<K, T>> &L const K &key)
    {
        typename std::list<std::pair<const K, T>>::iterator it_list;
        it_list = L.begin();
        while (it_list != L.end())
        {
            return it_list;
            ++it_list;
        }
        else
        {
            return it_list;
        }
    }

public:
    class iterator;

    unordered_map(int s = 23)
    {
        m = s;
        n = 0;
        table = new std::list<std::pair<K, T>>[s];
    }

    std::pair<iterator, bool> insert(const std::pair<K, T> &p)

    {
        iterator it;
        int h = hash(p.first);
    }
};