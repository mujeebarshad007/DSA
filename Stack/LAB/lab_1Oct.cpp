#include <iostream>
#include "stack.h"
int main()
{
    stack<int> s1, s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    // ------------------------
    s2.push(1);
    s2.push(5);
    s2.push(3);

    if (s1.empty())
    {
        std::cout << " Stack 1 is empty\n";
    }
    if (s2.empty())
    {
        std::cout << " Stack 2 is empty\n";
    }
    else
    {
        if (s1 == s2) // Implemented The comparison Operator ==
        {
            std::cout << " Yes Both Stacks Are Equal \n";
        }
        else
        {
            std::cout << " NO! Both Stacks Are not  Equal\n";
        }

        if (s1 < s2) // Implemented The less than Operator <
        {
            std::cout << " Stack 1 is Smaller then Stack 2 \n";
        }
        else if (s2 < s1)
        {

            std::cout << " Stack 2 is Smaller then Stack 1 \n";
        }
    }
    return 0;
}