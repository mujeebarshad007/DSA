#pragma once
#include "node.h"
#include <climits>

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

    void push(const T &x)
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
    // ...existing code...
    stack &operator=(const stack &other)
    {
        if (this == &other)
            return *this;

        // clear current stack
        while (!empty())
            pop();

        // if other is empty, done
        if (other.top == nullptr)
        {
            top = nullptr;
            n = 0;
            return *this;
        }

        // copy nodes one-by-one preserving order (head/top stays the same)
        node<T> *src = other.top;
        node<T> *newnode = new node<T>;
        newnode->value = src->value;
        newnode->next = nullptr;
        top = newnode;
        node<T> *tail = newnode;
        src = src->next;
        int count = 1;

        while (src != nullptr)
        {
            node<T> *nn = new node<T>;
            nn->value = src->value;
            nn->next = nullptr;
            tail->next = nn;
            tail = nn;
            src = src->next;
            ++count;
        }

        n = count;
        return *this;
    }
    // ...existing code...
    int get_min()
    {
        int min_value = INT_MAX;

        while (!empty())
        {
            node<T> *temp;
            temp = top;
            if (temp->value < min_value)
            {
                node<T> *temp1;
                min_value = temp->value;
                temp1 = top;
                top = top->next;
                delete temp1;
            }
            top = top->next;
        }

        return min_value;
    }

    // int isbalance(const char *msg)
    // {
    //     for (int i = 0; msg[i] != '\0'; i++)
    //     {
    //         if (msg[i] == '(')
    //         {
    //             push(msg[i]);
    //         }
    //         else
    //         {
    //             if (msg[i] == ')')
    //             {
    //                 if (empty())
    //                 {
    //                     return 0;
    //                 }
    //                 else
    //                 {
    //                     pop();
    //                 }
    //             }
    //         }
    //     }
    //     if (empty())
    //     {
    //         return 1;
    //     }
    //     else
    //     {
    //         return 0;
    //     }
    // } Optional Added
    ~stack()
    {

        while (!empty())
        {
            pop();
        }
    }
};
