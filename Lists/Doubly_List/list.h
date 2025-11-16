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
    {
        while (H->next != H && H->prev != H)
        {
            pop_front();
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

        iterator operator++(int)
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
    iterator erase(iterator pos)
    {
        dnode<T> *temp;
        temp = pos.ptr;
        if (temp->prev == H) // handling first node issue
        {
            pos.ptr->next->prev = H;
            H->next = temp->next;
        }
        else if (temp->next == H) // handling last node
        {
            pos.ptr->prev->next = H;
            H->prev = pos.ptr->prev;
        }
        else
        {
            pos.ptr->prev->next = temp->next; /// handling any node issue
            pos.ptr->next->prev = temp->prev;
        }
        iterator it;
        it.ptr = temp->next;
        delete temp;
        --n;
        return it;
    }

    void merge(list &other)
    {
        dnode<T> *p1, *p2;
        dnode<T> *temp1, *temp2;

        p1 = this->H;
        p2 = other.H;

        while (p1->next != H && p2->next != H)
        {
            if (p1->next->value > p2->next->value)
            {

                temp1 = p1->next;
                temp2 = p2->next->next;

                p1->nex->prev = p2->next;
                p1->next = p2->next;
                p2->next->next = temp1;
                p2->next->prev = p1;
                p2->next = temp2;
            }
            else
            {
                p1 = p1->next;
            }
        }

        if (p1->next == H)
            p1->next = p2->next;

        other.H->next = H;
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
        return it;
    }
};