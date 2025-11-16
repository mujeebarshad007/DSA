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
        l.push_back(5);
        l.push_back(6);
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }

    list<int>::iterator it;
    it = l.begin();
    ++it;
    ++it;
    // while (it != l.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    l.insert(it, 20);
    it = l.begin();

    while (it != l.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    ++it;

    l.erase(it);
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