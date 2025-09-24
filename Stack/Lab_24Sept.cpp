#include "stack.h"
int main()
{

    stack stk;
    stack stk1;

    stk.push(1);
    stk.push(2);

    stk1.push(5);
    stk1.push(6);

    cout << stk.top() << endl;
    cout << stk1.top() << endl;
    cout << endl;
    stk.swap(stk1);
    cout << stk.top() << endl;
    cout << stk1.top() << endl;
    return 0;
}