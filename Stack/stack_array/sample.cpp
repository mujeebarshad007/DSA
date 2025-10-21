#include <iostream>
#include "stack.h"
int main()
{
    stack<int> A(10);
    stack<int> B(20);

    A.push(10);
    A.push(12);
    A.push(13);
    A.push(14);
    A.push(15);

    for (int i = 0; i < A.size(); i++)
    {
        B.DATA[i] = A.DATA[i];
    }
    return 0;
}