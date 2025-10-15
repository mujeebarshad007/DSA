#pragma
#include "node.h"
template <typename T>
class forward_list
{

private:
    node<T> *H;
    int n;

public:
    forward_list()
    {
        H = new node<T>;
        H->link = H;
        n = 0;
    }

    ~forward_list()
    {
        delete H;
    }

    bool empty() const
    {
        return (H->link == H);
    }

    T front() const
    {

        if (!empty())
        {
            return H->link->value;
        }
        else
        {
            throw " Stack Undeflow";
        }
    }

    void push_front(const T &x)
    {
        node<T> *temp;
        temp = new node<T>;
        temp->value = x;
        temp->link = H->link;
        H->link = temp;
        n++;
    }

    void pop_front()
    {
        node<T> *temp;
        temp = H->link;
        H->link = temp->link;
        delete temp;
    }

    T Remove_value(const T &x)
    {
        int count = 0;
        node<T> *temp1;
        node<T> *temp2;
        temp1 = H;       // Prevoius ko Dummy pe Rakha
        temp2 = H->link; // Current ko first node pe rakha
        while (temp2 != H)
        {
            if (temp2->value == x)
            {
                temp1->link = temp2->link; // prevoius ko current se agle se link kardo
                node<T> *delete_c;         // new pointer le lia
                delete_c = temp2;          // us pounter ko current ki memory se point kia

                temp2 = temp2->link; // ab current ko bhi aage link kar dia ;
                delete delete_c;     // delete kardia Delete pointer jo current ki memory ko point kar raha tha
                count++;
                n--;
            }
            else
            {
                temp1 = temp2;       // previous ko age move kardo
                temp2 = temp2->link; // C ko bhi aage link kardete hein
            }
        }
        return count;
    }

    T Unique()
    {
        int count = 0;
        if (empty())
            return count; // agar empty hai to pahle hi zero print kardo

        node<T> *temp1 = H->link;     // pahla pointer ko point karway Front se
        node<T> *temp2 = temp1->link; // dosre pointer ko point karway front k link se;

        while (temp2 != H)
        {
            if (temp1->value == temp2->value) // check condition of unique
            {
                node<T> *D; // deleting pointer lia hai
                D = temp2;
                temp1->link = temp2->link; // temp1 mein temp2 ka link daaala
                temp2 = temp2->link;       // same like temp1 pe hi link hai
                delete D;                  // delte kardo second waala same
                count++;
                --n;
            }
            else
            {
                temp1 = temp2;
                temp2 = temp2->link;
            }
        }
        return count;
    }

    void Resize(const int &x)
    {

        // Did only the removing from back of list part

        if (x <= 0)
        {

            while (!empty())
            {
                pop_front();
                n--;
            }
            return;
        }

        node<T> *temp1 = H->link;
        node<T> *temp2 = H;
        int count = 0;

        while (temp2 != H && count < x) // jab tak hum given wali jagah nai jaate
        {
            temp1 = temp2;
            temp2 = temp2->link;
            count++;
        }

        while (temp2 != H)
        {
            node<T> *D = temp2;
            temp2 = temp2->link;
            delete D;
            n--;
        }
        temp1->link = H;
        n = count;
    }
};
