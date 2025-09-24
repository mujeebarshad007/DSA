#pragma once
#include <iostream>
using namespace std;
inline void c_print()
{
    cout << " \nConstructor is called\n";
}
inline void d_print()
{
    cout << " \nDestructor is called\n";
}
class stack
{

private:
    int *DATA;
    int SIZE;
    int TOP;

public:
    stack(int s = 10)
    {
        SIZE = s;
        TOP = -1;
        DATA = new int[SIZE];
        c_print();
    }

    ~stack()
    {
        delete[] DATA;
        d_print();
    }

    void push(int value)
    {

        DATA[++TOP] = value;
    }
    void pop()

    {

        TOP--;
    }
    bool empty()

    {
        if (TOP == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int top()

    {
        return DATA[TOP];
    }
    int size()

    {
        return TOP + 1;
    }
    // stack s_swap(stack &obj)
    // {
    //     while (!empty())
    //     {
    //         TOP = 0;
    //         swap(this->DATA[TOP] = obj.DATA[TOP]);
    //         TOP++;
    //     }
    // }

    void swap(stack &other)
    {
        std::swap(DATA, other.DATA);
        std::swap(SIZE, other.SIZE);
        std::swap(TOP, other.TOP);
    }
};
