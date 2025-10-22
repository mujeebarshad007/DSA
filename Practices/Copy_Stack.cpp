#include <iostream>
#include <stack>
void copy(std::stack<int> &A, std::stack<int> &B)
{
    int a = 0;

    std::stack<int> temp;
    while (!B.empty())
    {
        B.pop();
    }
    while (!A.empty())
    {

        a = A.top();
        temp.push(a);
        A.pop();
    }

    int b = 0;
    while (!temp.empty())
    {
        b = temp.top();
        A.push(b);
        B.push(b);
        temp.pop();
    }
}
int main()
{

    std ::stack<int> A;
    std ::stack<int> B;

    A.push(1);
    A.push(2);
    A.push(3);
    A.push(4);

    B.push(5);
    B.push(6);
    B.push(7);
    B.push(3);

    copy(A, B);
    while (!A.empty())
    {
        std ::cout << A.top() << " ";
        A.pop();
    }
    std::cout << std::endl;
    while (!B.empty())
    {
        std ::cout << B.top() << " ";
        B.pop();
    }

    return 0;
}