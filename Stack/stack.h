#pragma once
#include <iostream>
using namespace std;

class Stack
{

private:
    int *DATA;
    int SIZE;
    int TOP;

public:
    Stack(int s = 10)
    {
        SIZE = s;
        TOP = -1;
        DATA = new int[SIZE];
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
};
