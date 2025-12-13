#include <iostream>
#include "map.h"

int main()
{
    map<int, std::string> m;

    // Insert some key-value pairs
    m.insert({1, "Mujeeb"});
    m.insert({3, "Niko"});
    m.insert({2, "Dangling"});
    m.insert({4, "Ptr"});

    std::cout << "Size: " << m.size() << std::endl;

    std::cout << "\nAll elements in map:" << std::endl;
    map<int, std::string>::iterator it;
    it = m.begin();
    while (it != m.end())
    {
        std::cout << it->first << " => " << it->second << std::endl;
        ++it;
    }
    m[2] = "Ali"; // inserts key 5 if missing
    std::cout << "Key 2 is: " << m[2] << std::endl;

    // Check contains / find
    if (m.contains(3))
        std::cout << "\nKey 3 exists in the map." << std::endl;

    if (!m.contains(6))
        std::cout << "Key 6 does NOT exist in the map." << std::endl;

    return 0;
}
