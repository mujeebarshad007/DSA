#include <iostream>
#include "list.h"
int main()
{
    list<int> l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    list<int>::iterator it;
    it = l.begin();
    while (it != l.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    return 0;
}