#include <iostream>
#include "Stack.h"
int main()
{
    Stack<int> s;

    s.push(4);
    s.push(5);
    s.push(-1);
    s.push(40);

    // std ::cout << "The Size of the Stack is " << s.size() << std::endl;
    // std ::cout << "The TOp of the Stack is " << s.TOP() << std::endl;
    // std ::cout << "The Stack is Given as  " << std::endl;

    // while (!s.empty())
    // {
    //     std::cout << s.TOP() << " ";
    //     s.pop();
    // }
    // std::cout << std::endl;
    // try
    // {
    //     s.pop();
    // }
    // catch (const char *msg)
    // {
    //     std::cout << msg << std::endl;
    // }

    // if (s.empty())
    // {
    //     std::cout << "Yes Its Empty \n";
    // }
    // else
    // {
    //     std::cout << "Not its not empty\n";
    // }

    s.get_min();
    while (!s.empty())
    {
        std::cout << s.TOP() << " ";
        s.pop();
    }
    return 0;
}