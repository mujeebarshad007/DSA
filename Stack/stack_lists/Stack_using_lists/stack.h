#pragma once
#include "node.h"
#include <climits>

template <typename T>
class Stack
{
private:
    node<T> *top;
    int n;

public:
    Stack() // TODO DESTRUCTOR MAKE
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

    stack &operator=(const stack &other)
    {

        while (!empty())
            pop();

        if (other.top == nullptr)
        {
            top = nullptr;

            return *this;
        }

        top = new node;
        top->val = other.top->val;
        node *current_this;
        node *c_other;
        current_this = top;
        c_other = other.top->link;
        while (c_other != nullptr)
        {
            node *temp = new node;
            temp->val = c_other->val;
            temp->link = nullptr;
            current_this->link = temp;
            current_this = temp;
            c_other = c_other->link;
        }
        return *this;
    }
    T get_min()
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
    ~Stack()
    {

        while (!empty())
        {
            pop();
        }
    }
};
