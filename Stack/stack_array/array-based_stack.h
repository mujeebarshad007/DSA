#pragma once
#include <iostream>
template <typename T>
class stack
{
private:
    T *DATA;
    int SIZE;
    int TOP;

public:
    template <typename U>
    friend bool operator==(const stack<U> &, const stack<U> &);
    template <typename U>
    friend bool operator<(const stack<U> &, const stack<U> &);

    stack(int s = 60)
    {
        SIZE = s;
        TOP = -1;
        DATA = new T[SIZE];
    }

    ~stack()
    {
        delete[] DATA;
    }

    void push(const T &value)
    {
        if (TOP + 1 == SIZE)
        {
            throw std::overflow_error("Stack overflow");
        }
        DATA[++TOP] = value;
    }

    void pop()
    {
        if (empty())
        {
            throw std::underflow_error("Stack underflow");
        }
        TOP--;
    }

    bool empty() const
    {
        return TOP == -1;
    }

    T top() const
    {
        if (empty())
        {
            throw std::underflow_error("Stack is empty");
        }
        return DATA[TOP];
    }

    int size() const
    {
        return TOP + 1;
    }

    void swap(stack &other)
    {
        std::swap(DATA, other.DATA);
        std::swap(SIZE, other.SIZE);
        std::swap(TOP, other.TOP);
    }
};
template <typename U>
bool operator==(const stack<U> &lhs, const stack<U> &rhs)
{

    if (lhs.size() != rhs.size())
        return false;

    for (int i = 0; i <= lhs.TOP; i++)
    {
        if (lhs.DATA[i] != rhs.DATA[i])
        {
            return false;
        }
    }
    return true;
}
template <typename U>
bool operator<(const stack<U> &lhs, const stack<U> &rhs)
{

    int n;
    if (lhs.size() < rhs.size())
        n = lhs.size();
    else
        n = rhs.size();

    for (int i = 0; i < n; i++)
    {
        if (lhs.DATA[i] < rhs.DATA[i])
            return true;
        else if (lhs.DATA[i] > rhs.DATA[i])
            return false;
    }

    if (lhs.size() < rhs.size())
        return true;
    else
        return false;
}
