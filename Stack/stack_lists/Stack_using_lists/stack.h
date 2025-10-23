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

    stack &operator=(const stack &rhs)
    {
        // 1️⃣ Self-assignment check
        if (this == &rhs)
            return *this;

        // 2️⃣ Clear current stack
        while (!empty())
            pop();

        // 3️⃣ If rhs stack is empty
        if (rhs.top == nullptr)
        {
            top = nullptr;
            return *this;
        }

        // 4️⃣ Start copying nodes
        node *rtemp = rhs.top; // pointer to walk through rhs
        node *prev = nullptr;  // track the last created node

        // 5️⃣ Create first node
        top = new node;
        top->val = rtemp->val;
        top->link = nullptr;
        prev = top;
        rtemp = rtemp->link;

        // 6️⃣ Copy rest of nodes
        while (rtemp != nullptr)
        {
            node *nn = new node;
            nn->val = rtemp->val;
            nn->link = nullptr;

            prev->link = nn; // connect new node
            prev = nn;       // move forward
            rtemp = rtemp->link;
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
