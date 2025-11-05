#include "tnode.h"
template <typename key_type>
class set
{
private:
    tnode<key_type> *H;
    int n;

public:
    set()
    {

        H = new tnode<key_type>;
        H->left = H->right = H->parent = H;
        H->is_nill = true;
        n = 0;
    }

    class iterator
    {
    private:
        tnode<key_type> *node;
        tnode<key_type> *H;
        template <typename U>
        friend class set;

    public:
        iterator(tnode<key_type> *n, tnode<key_type> *h)
        {
            node = n;
            H = h;
        }

        key_type &operator*()
        {
            return node->key;
        }

        iterator &operator++()
        {
            if (node->right != H)
            {
                node = node->right;
                while (node->left != H)
                    node = node->left;
            }
            else
            {
                tnode<key_type> *parent = node->parent;
                while (parent != H && node == parent->right)
                {
                    node = parent;
                    parent = parent->parent;
                }
                node = parent;
            }
            return *this;
        }

        bool operator!=(const iterator &other) const
        {
            return node != other.node;
        }
        bool operator==(const iterator &it) const
        {
            return node == it.node;
        }
        key_type *operator->() { return &(node->key); }
    };
    iterator begin()
    {
        return iterator(H->left, H);
    }
    iterator end()
    {
        return iterator(H, H);
    }
    iterator find(const key_type &key)
    {
        tnode<key_type> *temp = H->parent;
        while (temp != H)
        {
            if (key < temp->key)
                temp = temp->left;
            else if (key > temp->key)
                temp = temp->right;
            else
                return iterator(temp, H);
        }
        return end();
    }

    void insert(const key_type &key)
    {
        tnode<key_type> *nn, *temp;
        nn = new tnode<key_type>;
        nn->left = H;
        nn->right = H;
        nn->parent = H;
        nn->key = key;
        nn->is_nill = false;

        if (H->parent == H)
        {
            H->parent = nn;
            H->left = nn;
            H->right = nn;
            nn->parent = H;
            ++n;
            return;
        }
        temp = H->parent;
        while (1)
        {
            if ((key < temp->key))
            {
                if (temp->left != H)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = nn;
                    nn->parent = temp;
                    break;
                }
            }
            else if ((key > temp->key))
            {
                if (temp->right != H)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = nn;
                    nn->parent = temp;
                    break;
                }
            }
            else
            {
                delete nn;
                throw " Duplicate Values";
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
        ++n;
    }
    bool empty() const
    {
        return (H->parent == H);
    }
    int size()
    {
        return n;
    }

    int count(const key_type &key) const // checks if any duplicate is there or not
    {

        tnode<key_type> *temp;
        temp = H->parent;
        while (temp != H)
        {
            if (key < temp->key)
            {
                temp = temp->left;
            }
            else if (key > temp->key)
            {
                temp = temp->right;
            }
            else
            {
                return 1;
            }
        }
        return 0;
    }
    bool contains(const key_type &key) const // checks if any duplicate is there or not
    {

        tnode<key_type> *temp;
        temp = H->parent;
        while (temp != H)
        {
            if (key < temp->key)
            {
                temp = temp->left;
            }
            else if (key > temp->key)
            {
                temp = temp->right;
            }
            else
            {
                return true; // means duplicate is found
            }
        }
        return false; // hamein key nahi mili
    }
};
