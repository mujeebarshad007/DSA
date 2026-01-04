#pragma once
#include <forward_list>
#include <stack>
#include <queue>
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
        typename std::forward_list<std::pair<int, E>>::iterator it = edges[s_i].begin();
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
        typename std::forward_list<std::pair<int, E>>::iterator it = edges[v_i].begin();
        while (it != edges[v_i].end())
        {
            f.push_front(vertices[it->first]);
            ++it;
        }
        return f;
    }
    bool DFS_SEARCH(const V &s, const V &d)
    {
        std::stack<int> s;

        bool *mark = new bool[n];
        for (int i = 0; i < n; i++)
            mark[i] = false;

        int s_i = get_index(s);
        int d_i = get_index(d);

        mark[s_i] = true;
        s.push(s_i);

        while (!s.empty())
        {
            int a = s.top();
            s.pop();

            if (a == d_i)
            {
                delete[] mark;
                return true;
            }

            typename std::forward_list<std::pair<int, E>>::iterator it = edges[a].begin();

            while (it != edges[a].end())
            {
                int u = it->first;

                if (!mark[u])
                {
                    mark[u] = true;
                    s.push(u);
                }
                ++it;
            }
        }

        delete[] mark;
        return false;
    }
    bool BFS_SEARCH(const V &s, const V &d)
    {
        std::queue<int> q;

        bool *mark = new bool[n];
        for (int i = 0; i < n; i++)
            mark[i] = false;

        int s_i = get_index(s);
        int d_i = get_index(d);

        mark[s_i] = true;
        q.push(s_i);

        while (!q.empty())
        {
            int a = q.front();
            q.pop();

            if (a == d_i)
            {
                delete[] mark;
                return true;
            }

            typename std::forward_list<std::pair<int, E>>::iterator it = edges[a].begin();

            while (it != edges[a].end())
            {
                int u = it->first;

                if (!mark[u])
                {
                    mark[u] = true;
                    q.push(u);
                }
                ++it;
            }
        }

        delete[] mark;
        return false;
    }
};