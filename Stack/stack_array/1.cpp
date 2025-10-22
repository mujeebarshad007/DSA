#include "stack.h"
int main()
{
    stack<int> stk1(10);

    stk1.push(1);
    stk1.push(2);
    stk1.push(3);
    stk1.push(4);
    stk1.push(5);

    stack<int> stk2 = stk1; // copy Constructor
    stk2.push(40);
    while (!stk2.empty())
    {
        std::cout << stk2.top() << " ";
        stk2.pop();
    }
    std::cout << std::endl;
    return 0;
}