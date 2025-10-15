#include <iostream>
#include "header.h"
int main()
{
    forward_list<int> f;

    f.push_front(1);
    f.push_front(2);
    f.push_front(2);
    f.push_front(2);
    f.push_front(3);
    f.push_front(2);
    f.push_front(4);
    f.push_front(4);
    f.push_front(5);
    f.push_front(3);

    std::cout << "\n";
    f.Resize(2);
    while (!f.empty())
    {
        std::cout << f.front() << " ";
        f.pop_front();
    }
    return 0;
}