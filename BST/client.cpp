#include <iostream>
#include "set1.h"

int main()
{
    set<int> s;

    s.insert_r(10);
    s.insert_r(5);
    s.insert_r(15);
    s.insert_r(12);

    std::cout << "Elements in set (c-order): ";
    set<int>::iterator it = s.begin();

    while (it != s.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";
    // set<int>::reverse_iterator r_it;
    // r_it = s.r_begin();
    // while (r_it != s.r_end())

    // {
    //     std::cout << *r_it << " ";
    //     ++r_it;
    // }
    // std ::cout << std::endl;
    return 0;
}
