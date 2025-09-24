#include "stack.h"
int main()
{
    stack stk(10);
    stk.push(1);
    stk.push(2);
    stk.push(3);

    std::cout << " The Top Element of the Stack is " << stk.top() << std::endl;
    std::cout << " The Size of The Stack is " << stk.size() << std::endl;
    stk.pop();

    std::cout << " The Top Element of the Stack is " << stk.top() << std::endl;
    std::cout << " The Size of The Stack is " << stk.size() << std::endl;

    if (!stk.empty())
    {
        std::cout << "The stack is not Empty" << std::endl;
    }
    else
    {
        std::cout << "The stack is  Empty" << std::endl;
    }
    return 0;
}