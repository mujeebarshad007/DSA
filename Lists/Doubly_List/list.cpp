#include <iostream>
#include "list.h"

int main()
{
    std::cout << "--- Executing Validation Suite ---\n";

    list<int> L, G;

    L.push_front(20);
    L.push_front(10);
    L.push_front(10);
    L.push_front(10);
    L.push_front(30);
    L.push_front(40);
    // G = L;
    std::cout << "Front: " << L.front() << std::endl;
    std::cout << "Back: " << L.back() << std::endl;

    // Print list
    std::cout << "List after pushes: ";
    list<int>::iterator it;
    it = L.begin();
    while (it != L.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // // Pop ops
    // L.pop_front();
    // L.pop_back();

    // std::cout << "After pop_front + pop_back: ";
    // it = L.begin();
    // while (it != L.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    // std::cout << std::endl;

    // // Insert test
    // list<int>::iterator it1 = L.begin();
    // ++it1;
    // L.insert(it1, 99);

    // std::cout << "After insert(99): ";
    // it = L.begin();
    // while (it != L.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    // std::cout << std::endl;

    // // Erase test
    // list<int>::iterator it2 = L.begin();
    // L.erase(it2);

    // std::cout << "After erase(begin): ";
    // it = L.begin();
    // while (it != L.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    // std::cout << std::endl;

    // // Reverse traversal
    // std::cout << "Reverse traversal: ";
    // list<int>::reverse_iterator rit;
    // rit = L.r_begin();
    // while (rit != L.r_end())
    // {
    //     std::cout << *rit << " ";
    //     ++rit;
    // }
    // std::cout << std::endl;

    // // Remove test
    // L.remove(99);

    // std::cout << "After remove(99): ";
    // it = L.begin();
    // while (it != L.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    // std::cout << std::endl;

    // // Splice test
    // list<int> B;
    // B.push_back(111);
    // B.push_back(222);
    // B.push_back(333);

    // list<int>::iterator pos = L.begin();
    // L.splice(pos, B);

    // std::cout << "After splice into L: ";
    // it = L.begin();
    // while (it != L.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    // std::cout << std::endl;

    // std::cout << "B after splice: ";
    // it = B.begin();
    // while (it != B.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    // std::cout << std::endl;

    // // Swap test
    // list<int> C;
    // C.push_back(500);
    // C.push_back(600);

    // std::cout << "Before swap, L: ";
    // it = L.begin();
    // while (it != L.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }

    // std::cout << "\nBefore swap, C: ";
    // it = C.begin();
    // while (it != C.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    // std::cout << std::endl;

    // L.swap(C);

    // std::cout << "After swap, L: ";
    // it = L.begin();
    // while (it != L.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }

    // std::cout << "\nAfter swap, C: ";
    // it = C.begin();
    // while (it != C.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    std::cout << std::endl;

    // unique
    // L.unique();

    // std::cout << "After UNique: ";
    // it = L.begin();
    // while (it != L.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    // std::cout << std::endl;

    // Resize
    // L.sort();
    // it = L.begin();
    // while (it != L.end())
    // {
    //     std::cout << *it << " ";
    //     ++it;
    // }
    // std::cout << std::endl;

    // // Clear test
    // C.clear();
    // std::cout << "C after clear: " << (C.empty() ? "EMPTY" : "NOT EMPTY") << std::endl;

    // std::cout << "--- Validation Suite Completed ---\n";

    return 0;
}
