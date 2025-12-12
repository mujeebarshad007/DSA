#include <iostream>
#include "hash.h"
int main()
{

    unordered_map<int, char> sq;
    sq.insert({1, 'A'});
    sq.insert({2, 'B'});
    sq.insert({3, 'C'});

    // unordered_map<int, char>::iterator it = sq.begin();
    // while (it != sq.end())
    // {
    //     std::cout << it->first << " " << it->second << std::endl;
    //     ++it;
    // }
    unordered_map<int, char>::iterator it2 = sq.begin();
    ++it2;
    sq.erase(it2);

    unordered_map<int, char>::iterator it3 = sq.begin();
    while (it3 != sq.end())
    {
        std::cout << it3->first << " " << it3->second << std::endl;
        ++it3;
    }
    return 0;
}