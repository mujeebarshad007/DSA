#include <iostream>
#include "list.h"

int main()
{
    list<int> l;
    try
    {
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        l.push_back(2);
        l.push_back(5);
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }
    list<int> g;
    try
    {
        g.push_back(9);
        g.push_back(8);
        g.push_back(7);
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }

    list<int>::iterator it;
    list<int>::iterator it2;
    // std::cout << " THe List 1 is : ";
    // it = l.begin();
    // while (it != l.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    // std::cout << std::endl;

    // std::cout << " THe List 2 is : ";
    // it2 = g.begin();
    // while (it2 != g.end())
    // {
    //     std::cout << *it2 << " ";
    //     ++it2;
    // }
    // std::cout << std::endl;
    // it = l.begin();
    // ++it;
    // ++it;
    // l.insert(it, 20);
    // it = l.begin();
    // std::cout << std::endl;

    // ++it;
    // l.erase(it);
    // it = l.begin();
    // while (it != l.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }

    // l.remove(2);
    // std::cout << " THe List 1 is : ";
    // it = l.begin();
    // while (it != l.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }

    // it = l.begin();
    // ++it;
    // ++it;
    // l.splice(it, g);
    // it = l.begin();
    // while (it != l.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }

    it = l.begin();
    it2 = g.begin();

    l.swap(g);
    it = l.begin();
    while (it != l.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    // list<int>::reverse_iterator r_it;
    // r_it = l.r_begin();
    // while (r_it != l.r_end())

    // {
    //     std::cout << *r_it << " ";
    //     ++r_it;
    // }
    // std ::cout << std::endl;
    return 0;
}