#include <iostream>
#include "graph.h"
int main()
{
<<<<<<< HEAD
    graph<char, int> g;
    g.add_vertex('A');
    g.add_vertex('B');
    g.add_vertex('C');
    g.add_vertex('D');

    g.add_edge('A', 'C', 2);
    g.add_edge('B', 'D', 3);
    g.add_edge('C', 'B', 5);
    g.add_edge('D', 'B', 6);
    g.add_edge('D', 'A', 1);

    std::cout << g.weight('A', 'C') << std::endl;
    std::forward_list<char> neighbors;
    neighbors = g.neighbors('D');
    auto it = neighbors.begin();
    std::cout << "Neighbors of D: ";
    while (it != neighbors.end())
    {
        std::cout << *it << " ";
        ++it;
    }
}
=======

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

void bfs(const V &start)
{
    bool *visited = new bool[n]{false};
    std::queue<int> q;

    int start_index = get_index(start);
    visited[start_index] = true;
    q.push(start_index);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        std::cout << vertices[v] << " ";

        auto it = edges[v].begin();
        while (it != edges[v].end())
        {
            if (!visited[it->first])
            {
                visited[it->first] = true;
                q.push(it->first);
            }
            ++it;
        }
    }
    delete[] visited;
}

void dfs(const V &start)
{
    bool *visited = new bool[n]{false};
    std::stack<int> st;

    int start_index = get_index(start);
    st.push(start_index);

    while (!st.empty())
    {
        int v = st.top();
        st.pop();

        if (!visited[v])
        {
            visited[v] = true;
            std::cout << vertices[v] << " ";

            auto it = edges[v].begin();
            while (it != edges[v].end())
            {
                if (!visited[it->first])
                    st.push(it->first);
                ++it;
            }
        }
    }
    delete[] visited;
}
};
>>>>>>> ceba8344bf1534e5e6ef8ec3115a4e7da8ff13fb
