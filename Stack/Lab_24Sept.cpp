#include "stack.h"
int main()
{

    stack stk;
    stack stk1;

    stk.push(1);
    stk.push(2);
    cout << " The Top Value of first object is :" << stk.top() << endl;
    stk1.push(5);
    stk1.push(6);
    cout << " The Top Value of first object is :" << stk1.top() << endl;
    cout << endl;
    cout << " After Swapping The FIles are " << endl;
    stk.swap(stk1);
    cout << endl;
    cout << " The Top Value of first object is :" << stk.top() << endl;
    cout << "The Top Value of second object is :" << stk1.top() << endl;
    cout << endl;
    stk.pop();
    stk1.pop();
    cout << " The Pop Function is called" << endl;
    cout << endl;
    cout << " The Top Value of first object is :" << stk.top() << endl;
    cout << "The Top Value of second object is :" << stk1.top() << endl;
    return 0;
}