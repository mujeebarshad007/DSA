#include <iostream>
#include "Unordered_map.h"

int main()
{
    unordered_map<int, std::string> map;

    // Insertion of elements

    map.insert({1, "Mujeeb"});
    map.insert({1, "Ahsan"});
    map.insert({1, "Khizar"});

    std::cout << " Size Of Hash_MAP After insetion is : " << map.size() << std::endl;

    // operator [] use

    std::cout << " Key 1 : " << map[1] << std::endl;
    std::cout << " Key 2 : " << map[2] << std::endl;

    // update of element using []
    map[2] = "Umais";
    std::cout << " Key 2 After update is : " << map[2] << std::endl;

    try
    {
        std::cout << " KEY 3 : " << map.at(3) << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }

    // Count and contains
    std::cout << "Count key 2: " << map.count(2) << std::endl;
    std::cout << "Contains key 4: " << map.contains(4) << std::endl;

    // Erase element
    unordered_map<int, std::string>::iterator it = map.find(2);
    map.erase(it);
    std::cout << "Size after erase key 2: " << map.size() << std::endl;

    // Iterate through map
    std::cout << "Remaining elements:" << std::endl;
    unordered_map<int, std::string>::iterator iter = map.begin();
    while (iter != map.end())
    {
        std::cout << iter->first << " -> " << iter->second << std::endl;
        ++iter;
    }

    // Rehash and reserve
    map.rehash(10);
    std::cout << "Bucket count after rehash: " << map.bucket_count() << std::endl;
    map.reserve(15);
    std::cout << "Bucket count after reserve: " << map.bucket_count() << std::endl;

    // Clear
    map.clear();
    std::cout << "Size after clear: " << map.size() << std::endl;

    return 0;
}
