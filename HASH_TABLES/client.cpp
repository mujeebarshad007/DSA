#include <iostream>
#include "hash.h"
int main()
{

    unordered_map<int, char> sq;
    sq.insert({1, 'A'});
    sq.insert({2, 'B'});
    sq.insert({3, 'C'});

    unordered_map<int, char>::iterator it = sq.begin();
    while (it != sq.end())
    {
        std::cout << it->first << " " << it->second << std::endl;
        ++it;
    }
    return 0;
}