#include "stak.h"
int main()
{
    stack s(2);
    try
    {
        s.push(1);
        s.push(2);
        s.push(3);
    }
    catch (char *msg)
    {
        std::cout << msg << std::endl;
    }

    std ::cout << "The Top ELement Of this Stack is " << s.top() << std::endl;
    std ::cout << "The Size Of this Stack is " << s.size() << std::endl;

    try
    {

        s.pop();
    }
    catch (char *msg)
    {
        std::cout << msg << std::endl;
    }

    return 0;
}