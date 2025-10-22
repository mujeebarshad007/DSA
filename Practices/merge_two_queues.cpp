#include <iostream>
#include <queue>

int main()
{

    std::queue<int> q1;
    std::queue<int> q2;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);

    q2.push(5);
    q2.push(6);
    q2.push(7);
    q2.push(8);

    int a, b, c, d;

    // merging queues
    std::queue<int> q3;
    std::queue<int> temp1;
    std::queue<int> temp2;

    while (!q1.empty())
    {
        a = q1.front();
        q1.pop();
        q3.push(a);
        temp1.push(a);
    }

    while (!q2.empty())
    {
        b = q2.front();
        q2.pop();
        q3.push(b);
        temp2.push(b);
    }

    while (!temp1.empty())
    {
        c = temp1.front();
        q1.push(c);
        temp1.pop();
    }

    while (!temp2.empty())
    {
        d = temp2.front();
        q2.push(d);
        temp2.pop();
    }
    std::cout << "THE QUEUE 1 IS \n";
    while (!q1.empty())
    {
        std::cout << q1.front() << " ";
        q1.pop();
    }
    std::cout << std::endl;
    std::cout << "THE QUEUE 2 IS \n";
    while (!q2.empty())
    {
        std::cout << q2.front() << " ";
        q2.pop();
    }
    std::cout << std::endl;
    std::cout << "THE QUEUE 3 IS \n";
    while (!q3.empty())
    {
        std::cout << q3.front() << " ";
        q3.pop();
    }
    std::cout << std::endl;
    return 0;
}