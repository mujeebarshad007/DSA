#include <iostream>
#include "forward_list.h"

int main()
{
    Forward_list<int> f;
    f.push_front(1);
    f.push_front(7);
    f.push_front(8);
    f.push_front(9);

    Forward_list<int>::iterator it;
    std::cout << " The List 1 is ";
    it = f.begin();

    while (it != f.end())
    {
        std::cout << *it << " ";
        ++it;
    }

    std::cout << std::endl;
    f.delete_greater(5);
    std::cout
        << " The REverse List is ";
    it = f.begin();

    while (it != f.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    return 0;
}