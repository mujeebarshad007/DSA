#include <iostream>
#include "set1.h"

int main()
{
    set<int> s;

    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(12);
    s.insert(11);
    s.insert(25);

    std::cout << "By using the Forward Iterator iss: \n";
    set<int>::iterator it = s.begin();

    while (it != s.end())
    {
        std::cout << *it << " ";
        ++it;
    }

    set<int>::iterator it2 = s.begin();
    ++it;
    ++it;
    s.erase(it);
    std::cout << "After erase ";
    set<int>::iterator it3 = s.begin();
    while (it3 != s.end())
    {
        std::cout << *it3 << " ";
        ++it3;
    }
    std::cout << "\n";
    // std::cout << "By using The Reverse Iterator is : \n";
    // set<int>::reverse_iterator r_it;
    // r_it = s.r_begin();
    // while (r_it != s.r_end())

    // {
    //     std::cout << *r_it << " ";
    //     ++r_it;
    // }
    std ::cout << std::endl;
    return 0;
}
