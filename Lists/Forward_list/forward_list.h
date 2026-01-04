#pragma once
#include "node.h"
template <typename T>
class Forward_list
{
private:
    node<T> *H;
    int n;

public:
    Forward_list()
    {
        H = new node<T>;
        H->next = nullptr;
        n = 0;
    }

    T front() const
    {
        return H->next->value;
    }

    void push_front(const T &val)
    {
        node<T> *temp;
        temp = new node<T>;
        temp->value = val;
        temp->next = H->next;
        H->next = temp;
        ++n;
    }

    void pop_front()
    {

        node<T> *temp;
        temp = H->next;
        H->next = temp->next;
        delete temp;
        n--;
    }

    bool empty() const
    {
        return (H->next == nullptr);
    }

    void clear() const
    {
        while (!empty())
        {
            pop_front();
        }
    }
    class iterator
    {
    private:
        node<T> *ptr;
        template <typename U>
        friend class Forward_list;

    public:
        iterator()
        {
            ptr = nullptr;
        }

        T &operator*() const
        {
            return ptr->value;
        }
        iterator &operator++()
        {
            if (ptr != nullptr)
                ptr = ptr->next;
            return *this;
        }

        iterator &operator++(int)
        {
            iterator temp;
            temp = *this;
            if (ptr != nullptr)
                ptr = ptr->next;
            return temp;
        }

        bool operator!=(const iterator &rhs) const
        {
            return this->ptr != rhs.ptr;
        }
    };

    Forward_list<T> &operator=(const Forward_list<T> &rhs)
    {
        if (this == &rhs)
            return *this;

        this->clear();

        node<T> *rtemp = rhs.H->next;
        node<T> *prev = this->H;

        while (rtemp != nullptr)
        {
            node<T> *nn = new node<T>;
            nn->value = rtemp->value;
            nn->next = nullptr;

            prev->next = nn; // link it
            prev = nn;       // move prev forward
            rtemp = rtemp->next;
        }

        return *this;
    }

    iterator begin() const
    {
        iterator it;
        it.ptr = H->next;
        return it;
    }
    iterator end() const
    {
        iterator it;
        it.ptr = nullptr;
        return it;
    }

    iterator before_begin()
    {
        iterator it;
        it.ptr = H;

        return it;
    }
    iterator insert_after(const iterator &pos, const T &val)
    {

        node<T> *temp = new node<T>;
        temp->value = val;
        temp->next = pos.ptr->next;
        pos.ptr->next = temp;
        ++n;
        iterator it;
        it.ptr = temp;
        return it;
    }

    iterator erase_after(const iterator &pos)
    {

        node<T> *temp = pos.ptr->next;
        pos.ptr->next = temp->next;
        iterator it;
        it.ptr = pos.ptr->next;
        delete temp;

        --n;
        return it;
    }

    void merge(Forward_list &other)
    {
        node<T> *p1, *p2;
        node<T> *temp1, *temp2;

        p1 = this->H;
        p2 = other.H;

        while (p1->next != nullptr && p2->next != nullptr)
        {
            if (p1->next->value > p2->next->value)
            {

                temp1 = p1->next;
                temp2 = p2->next->next;

                p1->next = p2->next;
                p2->next->next = temp1;
                p2->next = temp2;
            }
            else
            {
                p1 = p1->next;
            }
        }

        if (p1->next == nullptr)
            p1->next = p2->next;

        other.H->next = nullptr;
    }
    void splice_after(iterator pos, Forward_list &other)
    {
        node<T> *p1 = pos.ptr;
        node<T> *p2 = other.H;
        if (p2->next == nullptr)
            return;
        node<T> *first = p2->next;
        node<T> *last = first;
        while (last->next != nullptr)
        {
            last = last->next;
        }

        last->next = p1->next;
        p1->next = first;
        p2->next = nullptr;
    }
    void unique()
    {
        node<T> *p1, *p2;
        p1 = H->next;
        while (p1->next != nullptr)
        {
            p2 = p1->next;
            if (p2 == nullptr)
            {
                break;
            }
            if (p1->value == p2->value)
            {
                node<T> *temp;
                temp = p2->next;
                p1->next = p2->next;
                delete p2;
                p2 = temp;
            }
            else
            {
                p1 = p1->next;
            }
        }
    }

    void reverse() // reverse implemented using STL SLiding pointers approach
    {
        node<T> *p, *q, *r;
        r = q = nullptr;
        p = H->next;
        while (p != nullptr)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        H->next = q;
    }

    void Sort()
    {
    }
};
