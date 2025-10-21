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
};