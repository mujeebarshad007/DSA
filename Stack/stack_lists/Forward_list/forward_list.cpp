#include <iostream>
#include "forward_list.h"
int main()
{

    Forward_list<int> f;
    f.push_front(10);
    f.push_front(20);
    f.push_front(30);

    Forward_list<int>::iterator it;
    // it = f.begin();
    // ++it;

    // std::cout << " THe Value of iterator is " << *it << std ::endl;
    // *it = *it + 1;
    // std::cout << " THe Value of iterator is " << *it << std ::endl;

    it = f.insert_after(f.begin(), 90);
    while (it != f.end())
    {
        std ::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    return 0;
}