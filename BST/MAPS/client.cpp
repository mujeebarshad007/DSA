#include <iostream>
#include "map.h"

int main()
{

    map<int, std::string> m;

    m.insert({1, "Mujeeb"});
    m.insert({3, "Niko"});
    m.insert({2, "Dangling"});
    m.insert({4, "Ptr"});
    std::cout << "Size: " << m.size() << std::endl;

    try
    {
        std::cout << "Key 3: " << m.at(3) << std::endl;
        std::cout << "Key 5: " << m.at(5) << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }

    m[5] = "ALi";
    std::cout << "Key 5 is  " << m.at(5) << std::endl;

    map<int, std::string>::iterator it;
    it = m.begin();

    while (it != m.end())
    {

        std::cout << it->first << " => " << it->second << std::endl;
        ++it;
    }
    // value ko erase karna
    map<int, std::string>::iterator eraseIt;
    eraseIt = m.find(2);
    if (eraseIt != m.end())
    {
        m.erase(eraseIt);
    }

    std::cout << "After erasing key 2:" << std::endl;
    it = m.begin();
    while (it != m.end())
    {
        std::cout << it->first << " => " << it->second << std::endl;
        ++it;
    }

    return 0;
}
