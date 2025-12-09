#include "tnode.h"
template <typename key_type>
class set
{
private:
    tnode<key_type> *H;
    int n;
    tnode<key_type> *insert_rec(tnode<key_type> *ptr, const key_type &key)
    {
        if (ptr->is_nill)
        {
            tnode<key_type> *nn = new tnode<key_type>;
            nn->left = nn->right = nn->parent = H;
            nn->key = key;
            nn->is_nill = false;
            ++n;
            return nn;
        }
        if (key < ptr->key)
        {
            tnode<key_type> *pnn = insert_rec(ptr->left, key);
            pnn->parent = ptr;
            ptr->left = pnn;
        }
        else if (key > ptr->key)
        {
            tnode<key_type> *pnn = insert_rec(ptr->right, key);
            pnn->parent = ptr;
            ptr->right = pnn;
        }
        else
        {
            throw "duplicate value";
        }
        return ptr;
    }
    tnode<key_type> *successor(tnode<key_type> *ptr)
    {
        tnode<key_type> = ptr->right;
        while (->left != H)
        {
            temp = temp->left;
        }
        return;
    }

public:
    set()
    {
        H = new tnode<key_type>;
        n = 0;
        H->left = H->right = H->parent = H;
        H->is_nill = true;
    }
    class iterator
    {
    private:
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
            else if ((ptr->parent->left == ptr))
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

        key_type &operator*() const
        {
            return this->ptr->key;
        }

        bool operator!=(const iterator &rhs) const
        {
            return (this->ptr != rhs.ptr);
        }
        bool operator==(const iterator &rhs) const
        {
            return (this->ptr == rhs.ptr);
        }
    };
    class reverse_iterator
    {
    private:
        tnode<key_type> *ptr;
        friend class set;

    public:
        reverse_iterator &operator++()
        {
            if (!ptr->left->is_nill)
            {
                ptr = ptr->left;
                while (!ptr->right->is_nill)
                {
                    ptr = ptr->right;
                }
            }
            else if ((ptr->parent->right == ptr))
            {
                ptr = ptr->parent;
            }
            else
            {

                while ((ptr != ptr->parent->right) && (!ptr->parent->is_nill))
                {
                    ptr = ptr->parent;
                }
                ptr = ptr->parent;
            }
            return *this;
        }

        key_type &operator*() const
        {
            return this->ptr->key;
        }
        bool operator==(const reverse_iterator &rhs) const
        {
            return (this->ptr == rhs.ptr);
        }
        bool operator!=(const reverse_iterator &rhs) const
        {
            return this->ptr != rhs.ptr;
        }
    };

    reverse_iterator r_begin()
    {
        reverse_iterator it;
        tnode<key_type> * = H->right;
        if (== H)
        {
            it.ptr = H;
            return it;
        }
        it.ptr = ;
        return it;
    }
    reverse_iterator r_end()
    {
        reverse_iterator it;
        it.ptr = H;
        return it;
    }
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

    bool empty() const
    {
        return (H->parent == H);
    }

    int size() const
    {
        return n;
    }

    pair<iterator, bool> insert(const key_type &key)
    {
        tnode<key_type> *nn, *temp;
        nn = new tnode<key_type>;
        nn->left = nn->right = nn->parent = H;
        nn->key = key;
        nn->is_nill = false;

        if (H->parent == H)
        {
            nn->parent = H;
            H->left = nn;
            H->right = nn;
            H->parent = nn;
            ++n;

            iterator it;
            it.ptr = nn;
            return {it, true};
        }

        temp = H->parent;

        while (1)
        {
            if (key < temp->key)
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
            else if (key > temp->key)
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
                iterator it;
                it.ptr = temp;
                return {it, false};
            }
        }

        if (key < H->left->key)
            H->left = nn;
        else if (key > H->right->key)
            H->right = nn;

        ++n;

        iterator it;
        it.ptr = nn;
        return {it, true};
    }

    void insert_r(const key_type &key)
    {

        if (H->parent == H)
        {
            tnode<key_type> *nn = new tnode<key_type>;
            nn->left = nn->right = nn->parent = H;
            nn->key = key;
            nn->is_nill = false;
            H->left = H->right = H->parent = nn;
            ++n;
            return;
        }
        H->parent = insert_rec(H->parent, key);
        tnode<key_type> * = H->parent;
        while (->left != H)
            =->left;
        H->left = ;
        = H->parent;
        while (->right != H)
            =->right;
        H->right = ;
    }
    iterator erase(iterator pos) // pahle void se kia tha
    {
        iterator ret;
        ret.ptr = successor(to_del);
        tnode<key_type> *to_del, *lc, *rc, *succ, *succ_p, *succ_r;
        to_del = pos.ptr;
        // case 1: Delteing Leaf node
        if (to_del->left == H && to_del->right == H)
        {
            if (to_del->parent->left == to_del)
            {
                to_del->parent->left = H;
            }
            else if (to_del->parent->right == to_del)
            {
                to_del->parent->right = H;
            }
            delete to_del;
        }
        // CASE 2: Node Having one Child->Having left only
        else if (to_del->left != H && to_del->right == H)
        {
            lc = to_del->left;
            if (to_del->parent->left == to_del)
            {

                to_del->parent->left = lc;
            }
            else
            {
                to_del->parent->right = lc;
            }
            lc->parent = to_del->parent;
            delete to_del;
        }
        // CASE 3: Node Having one Child-> Having Right Child
        else if (to_del->left == H && to_del->right != H)
        {
            rc = to_del->right;
            if (to_del->parent->left == to_del)
            {

                to_del->parent->left = rc;
            }
            else
            {
                to_del->parent->right = rc;
            }
            rc->parent = to_del->parent;
            delete to_del;
        }
        // CASE 4: NODE HAVING BOTH CHILDS
        else
        {
            succ = successor(to_del);
            succ_p = succ->parent;
            succ_r = succ->right;

            if (to_del->parent->left == to_del)
                to_del->parent->left = succ;
            else
                to_del->parent->right = succ;

            // agar successor direct right child hai to_del ka
            if (succ == to_del->right)
            {
                succ->left = to_del->left;
                if (to_del->left != H)
                    to_del->left->parent = succ;
            }
            else
            {

                succ_p->left = succ_r;
                if (succ_r != H)
                    succ_r->parent = succ_p;

                // Now attach children of to_del to successor
                succ->left = to_del->left;
                succ->right = to_del->right;

                if (to_del->left != H)
                    to_del->left->parent = succ;
                if (to_del->right != H)
                    to_del->right->parent = succ;
            }

            // Finally set successor's parent left
            succ->parent = to_del->parent;

            delete to_del;
            if (to_del == H->parent)
            {

                if (H->parent->is_nill)
                {
                    H->parent = H;
                }
            }
        }
        --n;
        return ret;
    }
};
