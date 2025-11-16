#include <iostream>
#include "forward_list.h"

int main()
{
    Forward_list<int> f;
    f.push_front(8);
    f.push_front(5);
    f.push_front(2);
    f.push_front(1);
    Forward_list<int> f2;
    f2.push_front(9);
    f2.push_front(6);
    f2.push_front(4);
    f2.push_front(3);

    Forward_list<int>::iterator it;
    std::cout << " The List 1 is ";
    it = f.begin();

    while (it != f.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    std::cout << " The List 2 is ";
    it = f2.begin();

    while (it != f.end())
    {
        std::cout << *it << " ";
        ++it;
    }

    return 0;
}