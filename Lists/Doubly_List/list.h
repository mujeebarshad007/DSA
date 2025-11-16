#include "dnode.h"
template <typename T>

class list
{
private:
    dnode<T> *H;
    int n;

public:
    list()
    {
        H = new dnode<T>;
        H->next = H;
        H->prev = H;
        n = 0;
        // Will make A Destructor Also
    }
    int front() const
    {
        return H->next->value;
    }
    int back() const
    {
        return H->next->value;
    }
    bool empty() const
    {
        return (H->next == H && H->prev == H);
    }
    int size() const
    {
        return n;
    }
    void clear()
    { // if (!empty())
        // {

        dnode<T> *nn;
        nn = new dnode<T>;
        nn->value = val;
        nn->next = H->next;
        nn->prev = H;
        H->next = nn;
        nn->next->prev = nn;
        ++n;
        // else
        //     throw "list is Empty";
        S while (!(H->next == H && H->prev == H))
        {
            pop.front();
        }
    }

    void push_front(const T &val)
    {
        // if (!empty())
        // {

        dnode<T> *nn;
        nn = new dnode<T>;
        nn->value = val;
        nn->next = H->next;
        nn->prev = H;
        H->next = nn;
        nn->next->prev = nn;
        ++n;
        // else
        //     throw "list is Empty";
    }

    void push_back(const T &val)
    {
        // if (!empty())
        // {
        dnode<T> *nn;
        nn = new dnode<T>;
        nn->value = val;
        nn->next = H;
        nn->prev = H->prev;
        H->prev = nn;
        nn->prev->next = nn;
        ++n;
        // else
        //     throw "list is Empty";
    }

    void pop_front()
    {
        // if (!empty())
        // {
        dnode<T> *temp;
        temp = H->next;
        H->next = temp->next;
        temp->next->prev = H;
        delete temp;
        --n;
        // }
        // else
        // {
        // throw "list is Empty";
        // }
    }
    void pop_back()
    {

        if (!empty())
        {
            dnode<T> *temp;
            temp = H->prev;
            H->prev = temp->prev;
            temp->prev->next = H;
            delete temp;
            --n;
        }
    }
    class iterator
    {
    private:
        dnode<T> *ptr;
        template <typename U>
        friend class list;

    public:
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
        iterator &operator--()
        {
            if (ptr != nullptr)
                ptr = ptr->prev;
            return *this;
        }

        iterator &operator--(int)
        {
            iterator temp;
            temp = *this;
            if (ptr != nullptr)
                ptr = ptr->prev;
            return temp;
        }

        bool operator!=(const iterator &rhs) const
        {
            return this->ptr != rhs.ptr;
        }
    };
    class reverse_iterator
    {
    private:
        dnode<T> *ptr;
        template <typename U>
        friend class list;

    public:
        T &operator*() const
        {
            return ptr->value;
        }
        reverse_iterator &operator++()
        {
            if (ptr != nullptr)
                ptr = ptr->prev;
            return *this;
        }

        reverse_iterator &operator++(int)
        {
            reverse_iterator temp;
            temp = *this;
            if (ptr != nullptr)
                ptr = ptr->prev;
            return temp;
        }

        bool operator!=(const reverse_iterator &rhs) const
        {
            return this->ptr != rhs.ptr;
        }
    };

    iterator insert(iterator pos, const T &val)
    {
        dnode<T> *nn;
        nn = new dnode<T>;
        nn->value = val;
        nn->next = pos.ptr;
        nn->prev = pos.ptr->prev;
        nn->prev->next = nn;
        nn->next->prev = nn;
        --pos;
        return pos;
    }
    iterator begin()
    {
        iterator it;
        it.ptr = H->next;
        return it;
    }
    iterator end()
    {
        iterator it;
        it.ptr = H;
        return it;
    }
    iterator rbegin()
    {
        iterator it;
        it.ptr = H->prev;
        return it;
    }
    iterator rend()
    {
        reverse_iterator it;
        it.ptr = H->next;
        return it;
    }
    reverse_iterator r_begin()
    {
        reverse_iterator it;
        it.ptr = H->prev;
        return it;
    }
    reverse_iterator r_end()
    {
        reverse_iterator it;
        it.ptr = H;
        sss return it;
    }
    // list<T> &operator=(const list<T> &rhs)
    // {

    // }
};