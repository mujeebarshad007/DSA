#include "tnode.h"
#include <utility>
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
        if (!ptr || ptr->right == H)
            return H;

        tnode<key_type> *temp;
        temp = ptr->right;
        while (temp->left != H)
        {
            temp = temp->left;
        }
        return temp;
    }

    int Node_Height(tnode<key_type> *ptr)
    {
        int hl, hr;
        if (ptr && ptr->left)
        {
            hl = ptr->left->height;
        }
        else
        {
            hl = 0;
        }
        if (ptr && ptr->right)
        {
            hr = ptr->right->height;
        }
        else
        {
            hr = 0;
        }

        if (hl > hr)
        {
            return hl + 1;
        }
        return hr + 1;
    }
    int Balance_Factor(tnode<key_type> *ptr)
    {
        int hl, hr;
        if (ptr && ptr->left)
        {
            hl = ptr->left->height;
        }
        else
        {
            hl = 0;
        }
        if (ptr && ptr->right)
        {
            hr = ptr->right->height;
        }
        else
        {
            hr = 0;
        }

        return hl - hr;
    }
    tnode<key_type> *LL_Rotation(tnode<key_type> *ptr)
    {
        tnode<key_type> *ptr_l = ptr->left;
        tnode<key_type> *ptr_left_r = ptr_l->right;

        ptr_l->right = ptr;
        ptr->left = ptr_left_r;
        ptr->height = Node_Height(ptr);
        ptr->height = Node_Height(ptr_l);

        if (H->parent == ptr)
        {
            H->parent = ptr_l;
        }
        return ptr_l;
    }
    tnode<key_type> *LR_Rotation(tnode<key_type> *ptr)
    {
        return ptr = NULL;
    }
    tnode<key_type> *RR_Rotation(tnode<key_type> *ptr)
    {
        return ptr = NULL;
    }
    tnode<key_type> *RL_Rotation(tnode<key_type> *ptr)
    {
        return ptr = NULL;
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
        key_type *operator->() const
        {
            return &(ptr->key);
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
        tnode<key_type> *temp = H->right;
        if (temp == H)
        {
            it.ptr = H;
            return it;
        }
        it.ptr = temp;
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

    std::pair<iterator, bool> insert(const key_type &key)
    {
        tnode<key_type> *nn;
        nn = new tnode<key_type>;
        nn->left = nn->right = nn->parent = H;
        nn->key = key;
        nn->height = 1;
        nn->is_nill = false;

        if (H->parent == H) // empty tree
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

        tnode<key_type> *temp = H->parent;
        while (true)
        {
            if (key < temp->key)
            {
                if (temp->left != H)
                    temp = temp->left;
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
                    temp = temp->right;
                else
                {
                    temp->right = nn;
                    nn->parent = temp;
                    break;
                }
            }
            else
            {
                delete nn; // duplicate
                iterator it;
                it.ptr = temp;
                return {it, false};
            }
        }

        if (key < H->left->key)
            H->left = nn;
        if (key > H->right->key)
            H->right = nn;

        // **AVL balancing**: traverse up from parent
        temp = nn->parent;
        while (temp != H)
        {
            temp->height = Node_Height(temp); // update height
            int bf = Balance_Factor(temp);

            if (bf == 2 && Balance_Factor(temp->left) >= 0)
            {
                LL_Rotation(temp);
            }
            else if (bf == 2 && Balance_Factor(temp->left) < 0)
            {
                LR_Rotation(temp);
            }
            else if (bf == -2 && Balance_Factor(temp->right) <= 0)
            {
                RR_Rotation(temp);
            }
            else if (bf == -2 && Balance_Factor(temp->right) > 0)
            {
                RL_Rotation(temp);
            }

            temp = temp->parent; // go up to check for other imbalances
        }

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
        tnode<key_type> *temp = H->parent;
        while (temp->left != H)
            temp = temp->left;
        H->left = temp;
        temp = H->parent;
        while (temp->right != H)
            temp = temp->right;
        H->right = temp;
    }
    iterator erase(iterator pos) // pahle void se kia tha
    {
        iterator ret;
        tnode<key_type> *to_del, *lc, *rc, *succ, *succ_p, *succ_r;
        ret.ptr = successor(to_del);
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
