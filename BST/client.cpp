#include <iostream>
#include "tnode.h"
#include "set.h"

int main()
{
    set<int> s; // create a set of integers

    s.insert(5);
    s.insert(2);
    s.insert(1);
    s.insert(6);
    s.insert(11);

    std::cout << "Inserted 5, 2, 1, 6, 11 successfully!" << std::endl;
}
