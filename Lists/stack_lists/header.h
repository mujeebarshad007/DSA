#pragma once
#include "node.h"

template <typename T>
class stack
{
private:
    node<T> *top;
    int n;

public:
    stack() // TODO DESTRUCTOR MAKE
    {
        top = nullptr;
        n = 0;
    }

    T TOP() const
    {
        return top->value;
    }

    bool empty() const
    {
        return (top == nullptr);
    }

    int size() const
    {
        return n;
    }

    void push(T x)
    {

        node<T> *temp;
        temp = new node<T>;

        temp->value = x;
        temp->next = top;
        top = temp;
        n++;
    }

    void pop()
    {

        if (top == nullptr)
        {
            throw "Stack is Underflow";
        }
        else
        {

            node<T> *temp;
            temp = top;
            top = top->next;
            delete temp;
            n--;
        }
    }

    T isbalance(const char *msg)
    {
        for (int i = 0; msg[i] != '\0'; i++)
        {
            if (msg[i] == '(')
            {
                push(msg[i]);
            }
            else
            {
                if (msg[i] == ')')
                {
                    if (empty())
                    {
                        return 0;
                    }
                    else
                    {
                        pop();
                    }
                }
            }
        }
        if (empty())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    Optional Added ~stack()
    {

        while (!empty())
        {
            pop();
        }
    }
};
