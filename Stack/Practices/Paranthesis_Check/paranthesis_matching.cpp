#include <iostream>
#include "header.h"

int main()
{

    const char *msg = "(a+b)-(a*c)+((a-n)";
    stack<char> s;
    int results = s.isbalance(msg);
    if (results)
    {
        std::cout << " The Stack is Balnaced \n";
    }
    else
    {

        std::cout << " The Stack is not Balnaced \n";
    }
}