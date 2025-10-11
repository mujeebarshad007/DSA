#pragma once
#include <iostream>
class stack
{

private:
    int SIZE;
    int *DATA;
    int TOP;

public:
    stack(const int s = 10)
    {
        SIZE = s;
        DATA = new int[SIZE];
        TOP = -1;
    }

    ~stack()
    {
        delete[] DATA;
    }

    int top() const
    {
        return DATA[TOP];
    }

    bool empty() const
    {
        return (TOP == -1);
    }

    int size() const
    {
        return TOP + 1;
    }

    void push(const int &val)
    {

        if (TOP < SIZE)
        {

            DATA[++TOP] = val;
        }
        else
        {
            throw " Stack Overflow";
        }
    }

    void pop()
    {
        if (!empty())
        {
            --TOP;
        }
        else
        {
            throw " Stack Underflow";
        }
    }
    void swap(stack &other)
    {
        std::swap(*this, other);
    }
};