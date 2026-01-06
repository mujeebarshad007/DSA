#include "dnode.h"
#include "algorithm"
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
        return H->prev->value;
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
        if (!empty())
        {

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
            // }h
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
            bool operator==(const iterator &rhs) const
            {
                return this->ptr == rhs.ptr;
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
        list<T> &operator=(const list<T> &rhs)
        {
            if (this == &rhs)
                return *this;

            while (H->next != H)
            {
                pop_front();
            }

            dnode<T> *p = rhs.H->next;
            while (p != rhs.H)
            {
                push_back(p->value);
                p = p->next;
            }

            return *this;
        }

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

        void merge(list & other)
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

        void splice(iterator pos, list & other)
        {
            if (other.H->next == other.H)
                return;

            dnode<T> *p1 = pos.ptr;
            dnode<T> *first = other.H->next;
            dnode<T> *last = first;

            while (last->next != other.H)
            {
                last = last->next;
            }

            last->next = p1->next;
            if (p1->next != H)
            {
                p1->next->prev = last;
            }

            p1->next = first;
            first->prev = p1;

            other.H->next = other.H;
            other.H->prev = other.H;
        }
        void remove(const T &val)
        {

            if (H->next == H)
            {
                return;
            }
            dnode<T> *temp;
            temp = H->next;
            while (temp != H)
            {
                dnode<T> *temp2;
                temp2 = temp->next;
                if (temp->value == val)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }

                temp = temp2;
            }
        }
        void unique()
        {
            dnode<T> *p1, *p2;
            p1 = H->next;
            while (p1->next != H)
            {
                p2 = p1->next;
                if (p2 == H)
                {
                    break;
                }
                if (p1->value == p2->value)
                {
                    p1->next = p2->next;
                    p2->next->prev = p1;
                    delete p2;
                }
                else
                {
                    p1 = p1->next;
                }
            }
        }

        void resize(int new_n, const T &val = T())
        {
            while (n < new_n)
            {
                dnode<T> *nn = new dnode<T>;
                nn->value = val;
                nn->next = H;
                nn->prev = H->prev;
                H->prev->next = nn;
                H->prev = nn;
                ++n;
            }

            while (n > new_n)
            {
                if (!empty())
                {
                    dnode<T> *temp = H->prev;
                    H->prev = temp->prev;
                    temp->prev->next = H;
                    delete temp;
                    --n;
                }
            }
        }
        void reverse()
        {
            if (empty() || n == 1)
                return;

            dnode<T> *p1 = H->next;
            dnode<T> *p2 = nullptr;

            while (p1 != H)
            {
                p2 = p1->next;
                p1->next = p1->prev;
                p1->prev = p2;
                p1 = p2;
            }

            p2 = H->next;
            H->next = H->prev;
            H->prev = p2;
        }

        void sort()
        {
            if (empty() || n == 1)
                return;

            bool swapped;
            dnode<T> *p1;
            dnode<T> *p2 = H->prev; // end mein jaa rahe

            do
            {
                swapped = false;
                p1 = H->next;

                while (p1->next != H && p1->next != p2->next)
                {
                    if (p1->value > p1->next->value)
                    {

                        T temp = p1->value;
                        p1->value = p1->next->value;
                        p1->next->value = temp;
                        swapped = true;
                    }
                    p1 = p1->next;
                }

                p2 = p2->prev;
            } while (swapped);
        }

        void swap(list & other)
        {
            std::swap(H, other.H);
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

        ~list()
        {
            clear();
            delete H;
        }
    }
};