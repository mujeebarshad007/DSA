#include <iostream>
#include "set.h"

int main()
{
    set<int> s;

    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(12);

    std::cout << "Size: " << s.size() << "\n";

    if (!s.empty())
    {
        std::cout << "Set is not empty\n";
    }

    if (s.contains(10))
        std::cout << "Contains 10? Yes\n";
    else
        std::cout << "Contains 10? No\n";

    if (s.contains(7))
        std::cout << "Contains 7? Yes\n";
    else
        std::cout << "Contains 7? No\n";

    // Using count
    std::cout << "Count 15: " << s.count(15) << "\n"; // 1
    std::cout << "Count 8: " << s.count(8) << "\n";   // 0

    // Iterating using iterator
    std::cout << "Elements in set (in-order): ";

    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Using find
    auto it = s.find(12);
    if (it != s.end())
    {
        std::cout << "Found 12 using find: " << *it << "\n";
    }
    else
    {
        std::cout << "12 not found\n";
    }

    // Trying to insert duplicate
    try
    {
        s.insert(10);
    }
    catch (const char *msg)
    {
        std::cout << "Error: " << msg << "\n"; // Should print duplicate error
    }

    return 0;
}
