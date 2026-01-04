#include <iostream>
#include "set2.h"
int main()
{
    set<int> s;
    s.insert(50);
    s.insert(30);
    s.insert(70);
    s.insert(20);
    s.insert(40);
    s.insert(60);
    s.insert(80);

    int a;
    a = s.countleaves(s);
    std::cout << a << std::endl;
    return 0;
}