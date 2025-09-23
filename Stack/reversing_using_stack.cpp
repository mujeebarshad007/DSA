#include <iostream>
#include <stack>
int main()
{
    std::stack<int> stk;
    int n, v;
    std::cout << " Enter The Size of The Stack" << std::endl;
    std::cin >> n;
    std::cout << " Enter The Elements " << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cin >> v;
        stk.push(v);
    }

    std::cout << " The Reverse Of the Elements is " << std::endl;
    while (!stk.empty())
    {
        std::cout << stk.top() << " ";

        stk.pop();
    }
    std::cout << std::endl;
    return 0;
}