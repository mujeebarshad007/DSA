#include <iostream>
#include "set.h"
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    std::pair<set<int>::iterator, bool> p;
    p = s.insert(10);
    set<int>::iterator it;
    it = s.begin();
    while (it != s.end())
    {
        std::cout << *(p.first) << " ";
        ++it;
    }
    std::cout << "\n";
    return 0;
}