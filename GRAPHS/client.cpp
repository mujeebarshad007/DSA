#include <iostream>
#include "graph.h"
int main()
{
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