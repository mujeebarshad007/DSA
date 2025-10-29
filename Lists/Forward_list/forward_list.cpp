#include <iostream>
#include "forward_list.h"
template <typename T>
void display(Forward_list<T> &lst)
{
    Forward_list<T>::iterator it;
    it = lst.begin();

    while (it != lst.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}
int main()
{
    Forward_list<int> f;
    f.push_front(1);
    f.push_front(2);
    f.push_front(3);
    Forward_list<int>::iterator it;
    it = f.begin();
    display(f);
    it = f.begin();
    it = f.insert_after(it, 90);
    display(f);
    // std::cout << std::endl;
    // it = f.begin();
    // ++it;
    // it = f.erase_after(it);

    return 0;
}