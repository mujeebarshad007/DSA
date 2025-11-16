#include "tnode.h"
template <typename key_type>
class set
{
private:
    tnode<key_type> *H;
    int n;
    tnode<key_type> *successor(tnode<key_type> *ptr)
    {
        tnode<key_type> temp;
        temp = ptr->right;
        while (temp->left != H)
        {
            temp = temp->left;
        }
        return temp;
    }

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
        tnode<key_type> *ptr;
        template <typename U>
        friend class set;

    public:
        iterator()
        {
            ptr = nullptr;
        }

        key_type &operator*()
        {
            return ptr->key;
        }

        bool operator!=(const iterator &other) const
        {
            return ptr != other.ptr;
        }

        key_type *operator->() { return &(ptr->key); }
    };
    iterator begin()
    {
        iterator it;
        if (H->parent == H)
            it.ptr = H;
        else
            it.ptr = H->left;
        return it;
    }

    iterator end()
    {
        iterator it;
        it.ptr = H;
        return it;
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

    iterator erase(iterator pos)
    {
        tnode<key_type> *to_del, *lc, *rc, *succ, *succ_p, *succ_r;
        to_del = pos.ptr;
        // Case 1: Leaf node ko remove kar rahe
        if (to_del == H->parent) // mean hamare pass root node hai bss as a leaf node
        {
            H->parent = H;
            H->left = H;
            H->right = H;
            delete to_del;
        }
        else if (to_del->left == H && to_del->right == H)
        {
            if (to_del->parent->left == to_del)
            {
                to_del->parent->left = H;
            }
            else
                to_del->parent->right = H;
            delete to_del;
        }

        // Case 2: Node ka bss left child hai
        else if (to_del == H->parent && to_del->left != H && to_del->right == H) // matlb root node hai aur uska left hai bss
        {
            to_del->left->parent = H;
            delete to_del;
        }
        else if (to_del->left != H && to_del->right == H)
        {
            lc = to_del->left;
            if (to_del == to_del->parent->left)
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

        // Case 3 only node and have right child
        else if (to_del == H->parent && to_del->right != H && to_del->left == H) // matlb root node hai aur uska right hai bss
        {
            to_del->right->parent = H;
            delete to_del;
        }
        else if (to_del->right != H && to_del->left == H)
        {
            rc = to_del->right;
            if (to_del == to_del->parent->left)
            {
                to_del->parent->left = rc;
            }
            else
            {
                to_del->parent->right = rc;
            }
            rc->parent = to_del->parent;
        }

        // Case 4 Jab dono nodes hote hain delete node k;
        else
        {
            succ = successor(to_del);
            succ_p = succ->parent;
            succ_r = succ->right;
            if (to_del->parent->left = to_del)
            {
                to_del->parent->left = succ;
            }
            else if (to_del->parent->right = to_del)
            {
                to_del->parent->right = succ;
            }

            else if (to_del->left != H)
            {
                to_del->left->parent = succ;
            }
            else if (to_del->right != H)
            {
                to_del->right->parent = succ;
            }
            else if (to_del->right = succ)
            {
                succ_r->parent = succ->parent;
                succ->left = to_del->left;
            }
            else
            {
                succ->parent->left = succ_r;
                if (succ r_ != H)
                {
                    succ_r->parent = succ_p;

                    // remaining links banaye hein
                    succ->parent = to_del->parent;
                    succ->left = to_del->left;
                    succ->right = to_del->right;
                }
                delete to_del;
            }
        }
        --n;
    }
};