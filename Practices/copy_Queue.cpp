#include <iostream>
#include "queue.h"
void copy_queue(queue &A, queue &B)
{
    int val, size;
    size = A.size();
    for (int i = 1; i < size; i++)
    {
        val = A.front();
        A.pop();
        if (i % 2 == 0)
        {
            B.push(val);
        }
        else
        {
            A.push(val);
        }
    }
}

int main()
{
    queue A;
    queue B;

    A.push(1);
    A.push(2);
    A.push(3);
    A.push(4);

    copy_queue(A, B);
    while (!B.empty())
    {
        std::cout << B.front() << " ";
        B.pop();
    }
    std::cout << std ::endl;
    return 0;
}