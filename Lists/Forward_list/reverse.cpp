#include <iostream>
#include "forward_list.h"

int main()
{
    Forward_list<int> f;
    f.push_front(3);
    f.push_front(2);
    f.push_front(4);
    f.push_front(1);

    Forward_list<int>::iterator it;
    std::cout << " The List 1 is ";
    it = f.begin();

    while (it != f.end())
    {
        std::cout << *it << " ";
        ++it;
    }

    std::cout << std::endl;
    f.reverse();
    std::cout << " The REverse List is ";
    it = f.begin();

    while (it != f.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    return 0;
}