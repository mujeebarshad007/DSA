#pragma once
#include <forward_list>
#include <stack>
// Directed graph
// Weighted graph
template <typename V, typename E>
class graph
{
private:
    std::forward_list<std::pair<int, E>> *edges;
    V *vertices;
    int g_size;
    int n;
    void grow_graph(int new_size)
    {
    }
    int get_index(const V &v) const
    {
        for (int i = 0; i < n; ++i)
        {
            if (vertices[i] == v)
                return i;
        }
        return -1;
    }

public:
    graph(int S = 100)
    {
        g_size = S;
        n = 0;
        edges = new std::forward_list<std::pair<int, E>>[S];
        vertices = new V[S];
    }
    ~graph()
    {
        delete[] vertices;
        delete[] edges;
    }
    void add_vertex(const V &v)
    {
        vertices[n] = v;
        ++n;
    }
    void add_edge(const V &s, const V &d, const E &w)
    {
        int s_i, d_i;
        s_i = get_index(s);
        d_i = get_index(d);
        if (s_i == -1 || d_i == -1)
            throw("Invalid vertex");
        edges[s_i].push_front({d_i, w});
    }
    void clear()
    {
        /*
        delete[]vertices;
        delete[]edges;
        edges = new forward_list<std::pair<int, E>>[g_size];
        vertices = new V[g_size];
        */

        for (int i = 0; i < n; ++i)
            edges[i].clear();
        n = 0;
    }

    bool is_empty() const
    {
        return n == 0;
    }
    bool is_full() const
    {
        return g_size == n;
    }
    E weight(const V &s, const V &d) const
    {
        int s_i, d_i;
        s_i = get_index(s);
        d_i = get_index(d);
        auto it = edges[s_i].begin();
        while (it != edges[s_i].end())
        {
            if (it->first == d_i)
                return it->second;
            ++it;
        }
        throw("Edge does not exist");
    }
    std::forward_list<V> neighbors(const V &v) const
    {
        int v_i;
        v_i = get_index(v);
        std::forward_list<V> f;
        auto it = edges[v_i].begin();
        while (it != edges[v_i].end())
        {
            f.push_front(vertices[it->first]);
            ++it;
        }
        return f;
    }

    bool search_DFS(const V &source, const V &destination)
    {
        std::stack<V> s;
        bool *marked;
        marked = new bool[n];
        marked = {false};

        int source_index = get_index(source);
        int destination_index = get_index(destination);

        s.push(source_index);

        while (!s.empty())
        {
            int a = s.top();
            s.pop();
            if (a == destination_index)
                return true;

            if (!marked[a])
            {
                marked[a] = true;
            }
            std::forward_list<V> f = neighbors(a);
            while (!f.empty())
            {
                s.push(f.front());
            }
        }
    }
};