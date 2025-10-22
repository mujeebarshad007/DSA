#include <iostream>
#include "forward_list.h"
int main()
{

    Forward_list<int> f;
    f.push_front(10);
    f.push_front(20);
    f.push_front(30);
    f.push_front(40);
    f.push_front(50);

    Forward_list<int>::iterator it;

    it = f.begin();
    ++it;
    it = f.insert_after(it, 90);
    while (it != f.end())
    {
        std ::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    it = f.begin();
    ++it;
    it = f.erase_after(it);

    while (it != f.end())
    {
        std ::cout << *it << " ";
        ++it;
    }
    return 0;
}