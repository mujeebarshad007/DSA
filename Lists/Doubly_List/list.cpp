#include <iostream>
#include "list.h"
int main()
{
    list<int> l;
    try
    {
        l.push_front(1);
        l.push_front(2);
        l.push_front(3);
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }
    list<int>::iterator it;
    // it = l.begin();
    // while (it != l.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    list<int>::reverse_iterator r_it;
    r_it = l.r_begin();
    while (r_it != l.r_end())

    {
        std::cout << *r_it << " ";
        ++r_it;
    }
    std ::cout << std::endl;
    return 0;
}