#pragma once
#include <forward_list>
template <typename V, typename E>
class graph
{

    std::forward_list<std::pair<int, E>> *edges;
    int n;
    int g_size;
    V *vertices;
    int get_index(const V &v)
    {
        for (int i = 0; i < n; ++i)
        {
            if (vertices[i] == v)
            {
                return i;
            }
        }
        return -1;
    }

public:
    graph(int s = 100)
    {
        g_size = s;
        n = 0;
        edges = new std::forward_list<std::pair<int, E>>[s];
        vertices = new V[g_size];
    }

    ~graph()
    {
        delete[] edges;
        delete[] vertices;
    }

    void add_vertex(const V &v)
    {
        vertices[n] = v;
        ++n;
    }

    void add_edge(const V &s, const V &d, const E &w)
    {
        int s_index, d_index;
        s_index = get_index(s);
        d_index = get_index(d);

        edges[s_index].push_front({d_index, w});
    }

    void make_Empty()
    {
        for (int i = 0; i < n; ++i)
        {
            edges[i].clear();
            n = 0;
        }
    }
    bool is_empty() const
    {
        return n == 0;
    }
    bool is_full() const
    {
        return n == g_size;
    }
    E weight(const V &s, const V &d)
    {
        int s_index, d_index;
        s_index = get_index(s);
        d_index = get_index(d);
        auto it = edges[s_index].begin();
        while (it != edges[s_index].end())
        {
            if (it->first == d_index)
            {
                return it->second;
                ++it;
            }
        }
    }

    std::forward_list<V> neighbors(const V &v)
    {
        int v_index;
        v_index = get_index(v);
        std::forward_list<V> f;
        auto it = edges[v_index].begin();
        while (it != edges[v_index].end())
        {
            f.push_front(vertices[it->first]);
            ++it;
        }
        return;
    }
};