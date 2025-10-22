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
        this->clear(); // clear function to clear lhs list
        node<T> *rtemp, *nn, *prev;
        rtemp = this->H; // pointing the rtemp to dummy node of rhs
        prev = H;        // pointing the prev to dummy node of lhs
        while (rtemp != nullptr)
        {
            nn = new node<T>;         // create new node in lhs
            nn->value = rtemp->value; // copy value of rhs to lhs
            nn->next = nullptr;       // fill the new made node with null ptr
            prev->next = nn;          // link prev node to next node
            rtemp = rtemp->next;      // link rtemp to next node
            prev = nn;                // move prev pointer to next node bcz always prev should point to prev node to establish link
        }
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

        node<T> *temp = new node<T>; // make new node
        temp->value = val;           // insert value
        temp->next = pos.ptr->next;  // establish link to next node
        pos.ptr->next = temp;        // pos to added node link
        ++n;
        iterator it;
        it.ptr = temp; // assign it.ptr to temp to return it as a iterator
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
};