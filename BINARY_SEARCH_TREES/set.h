#include "tnode.h"
class iterator;
template <typename key_type>
class set
{
    tnode<key_type> *H;
    int n;

public:
    class iterator;
    set()
    {
        H = new tnode<key_type>;
        n = 0;
        H->parent = H->left = H->right = H;
        H->is_nill = true;
    }
    void empty() const
    {
        return (H->parent == H);
    }
    int size() const
    {
        return n;
    }

    std::pair<iterator, bool> insert(const key_type &key)
    {
        tnode<key_type> *nn, *temp;
        nn = new tnode<key_type>;
        nn->left = nn->right = nn->parent = H;
        nn->key = key;
        nn->is_nill = false;
        std::pair<iterator, bool> res;
        if (H->parent == H)
        {
            H->left = nn;
            H->right = nn;
            H->parent = nn;
            ++n;
            iterator it;
            it.ptr = nn;
            res.first = it;
            res.second = true;
            return res;
        }

        temp = H->left;
        while (1)
        {
            if (key < temp->key)
            {
                if (temp->left == H)
                {
                    temp->left = nn;
                    nn->parent = temp;
                    ++n;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (key > temp->key)
            {
                if (temp->right == H)
                {
                    temp->right = nn;
                    nn->parent = temp;
                    ++n;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                throw " Duplicate Value ";
            }
        }

        if (key < H->left->key)
        {
            H->left = nn;
        }
        else if (key > H->right->key)
        {
            H->right = nn;
        }
        iterator it;
        it.ptr = nn;
        res.first = it;
        res.second = true;
        return res;
    }

    class iterator
    {
        friend class set;
        tnode<key_type> *ptr;

    public:
        iterator &operator++()
        {
            if (!ptr->right->is_nill)
            {
                ptr = ptr->right;
                while (!ptr->left->is_nill)
                {
                    ptr = ptr->left;
                }
            }
            else if (ptr->parent->left == ptr)
            {
                ptr = ptr->parent;
            }
            else
            {
                while ((ptr != ptr->parent->left) && (!ptr->parent->is_nill))
                {
                    ptr = ptr->parent;
                }
                ptr = ptr->parent;
            }
            return *this;
        }
        key_type &operator*()
        {
            return this->ptr->key;
        }
        bool operator==(const iterator &rhs) const
        {
            return (this->ptr == rhs.ptr);
        }
        bool operator!=(const iterator &rhs) const
        {
            return (this->ptr != rhs.ptr);
        }
        key_type *operator->()
        {
            return &(ptr->key);
        }
    };
    iterator begin()
    {
        iterator it;
        it.ptr = H->left;
        return it;
    }
    iterator end()
    {
        iterator it;
        it.ptr = H;
        return it;
    }
};