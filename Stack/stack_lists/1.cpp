#include <iostream>
#include "header.h"
int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    std ::cout << "The Size of the Stack is " << s.size() << std::endl;
    std ::cout << "The TOp of the Stack is " << s.TOP() << std::endl;
    std ::cout << "The Stack is " << std::endl;

    while (!s.empty())
    {
        std::cout << s.TOP() << " ";
        s.pop();
    }
    std::cout << std::endl;
    try
    {
        s.pop();
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }
    return 0;
}