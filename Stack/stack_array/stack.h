#pragma once
#include <iostream>
#include <utility>
template <typename T>
class stack
{

private:
    T *DATA;
    int TOP;
    int SIZE;

public:
    stack(const int s = 10)
    {
        this->SIZE = s;
        this->DATA = new T[SIZE];
        this->TOP = -1;
    }

    ~stack()
    {
        delete[] DATA;
    }

    T top() const
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

    void push(const T &val)
    {

        if (TOP < SIZE - 1)
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

    stack<T> &operator=(const stack<T> &other)
    {
        TOP = other.TOP;
        SIZE = other.SIZE;

        delete[] DATA;
        DATA = new T[SIZE];
        for (int i = 0; i <= TOP; i++)
        {
            DATA[i] = other.DATA[i];
        }
        return *this;
    }

    stack(const stack<T> &other)
    {
        DATA = nullptr;
        operator=(other);
    }
};
