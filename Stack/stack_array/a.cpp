#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    stack<int> s;
    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
        s.push(i * 2);
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    while (!q.empty())
    {
        cout << s.top() << " ";
        q.pop();
    }
    return 0;
}