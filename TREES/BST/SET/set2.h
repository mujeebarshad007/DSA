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

    // AVL BALANCING FUNCTIONS
    int Node_Height(mnode<key_type, T> *ptr) // making it to just return node height
    {
        int hl, hr;
        if (ptr && ptr->left) // means k if node exists && node ka left exist
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
            return hl + 1; // adding 1 because always height will be +1
        }
        return hr + 1;
    }

    int Balance_Node(mnode<key_type, T> *ptr)
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

        return hl - hr; // returning height difference for balancing
    }

    // LL Rotation
    mnode<key_type, T> *LL_Rotation(mnode<key_type, T> *ptr)
    {
        mnode<key_type, T> *ptr_l = ptr->left;
        mnode<key_type, T> *ptr_left_r = ptr_l->right;

        ptr_l->right = ptr;
        ptr->left = ptr_left_r;

        // Update parent pointers
        ptr_l->parent = ptr->parent;
        ptr->parent = ptr_l;
        if (ptr_left_r != H)
            ptr_left_r->parent = ptr;

        // updating ptr->parents children
        if (ptr_l->parent != H)
        {
            if (ptr_l->parent->left == ptr)
                ptr_l->parent->left = ptr_l;
            else
                ptr_l->parent->right = ptr_l;
        }
        else
            H->parent = ptr_l; // make ptr_r root if ptr was root

        // update heights
        ptr->height = Node_Height(ptr);
        ptr_l->height = Node_Height(ptr_l);

        return ptr_l;
    }

    // RR Rotation (Right-Right)
    mnode<key_type, T> *RR_Rotation(mnode<key_type, T> *ptr)
    {
        mnode<key_type, T> *ptr_r = ptr->right;
        mnode<key_type, T> *ptr_right_l = ptr_r->left;

        ptr_r->left = ptr;
        ptr->right = ptr_right_l;

        // Update parent pointers
        ptr_r->parent = ptr->parent;
        ptr->parent = ptr_r;
        if (ptr_right_l != H)
            ptr_right_l->parent = ptr;

        // updating ptr->parents children
        if (ptr_r->parent != H)
        {
            if (ptr_r->parent->left == ptr)
                ptr_r->parent->left = ptr_r;
            else
                ptr_r->parent->right = ptr_r;
        }
        else
            H->parent = ptr_r; // make ptr_r root if ptr was root

        // update heights
        ptr->height = Node_Height(ptr);
        ptr_r->height = Node_Height(ptr_r);

        return ptr_r;
    }

    // LR Rotation (Left-Right)
    mnode<key_type, T> *LR_Rotation(mnode<key_type, T> *ptr)
    {

        mnode<key_type, T> *ptr_l;
        mnode<key_type, T> *ptr_l_r;

        ptr_l = ptr->left;
        ptr_l_r = ptr_l->right;

        // rotation performing and updating parent of childs of third node
        ptr_l->right = ptr_l_r->left;
        if (ptr_l_r->left != H)
            ptr_l_r->left->parent = ptr_l;
        ptr->left = ptr_l_r->right;
        if (ptr_l_r->right != H)
            ptr_l_r->right->parent = ptr;

        // main rotation
        ptr_l_r->left = ptr_l;
        ptr_l_r->right = ptr;

        // updating parents
        ptr_l_r->parent = ptr->parent;
        ptr_l->parent = ptr_l_r;
        ptr->parent = ptr_l_r;

        // updating ptr->parents children
        if (ptr_l_r->parent != H)
        {
            if (ptr_l_r->parent->left == ptr)
                ptr_l_r->parent->left = ptr_l_r;
            else
                ptr_l_r->parent->right = ptr_l_r;
        }
        else
            H->parent = ptr_l_r; // make ptr_l_r root if ptr was root

        // Updating heights again
        ptr_l->height = Node_Height(ptr_l);
        ptr->height = Node_Height(ptr);
        ptr_l_r->height = Node_Height(ptr_l_r);

        return ptr_l_r;
    }

    // RL Rotation (Right-Left)
    mnode<key_type, T> *RL_Rotation(mnode<key_type, T> *ptr)
    {
        mnode<key_type, T> *ptr_r = ptr->right;
        mnode<key_type, T> *ptr_r_l = ptr_r->left;

        // move subtrees
        ptr_r->left = ptr_r_l->right;
        if (ptr_r_l->right != H)
            ptr_r_l->right->parent = ptr_r;

        ptr->right = ptr_r_l->left;
        if (ptr_r_l->left != H)
            ptr_r_l->left->parent = ptr;

        // rotation
        ptr_r_l->left = ptr;
        ptr_r_l->right = ptr_r;

        // updating parents
        ptr_r_l->parent = ptr->parent;
        ptr->parent = ptr_r_l;
        ptr_r->parent = ptr_r_l;
        // updating ptr->parents children
        if (ptr_r_l->parent != H)
        {
            if (ptr_r_l->parent->left == ptr)
                ptr_r_l->parent->left = ptr_r_l;
            else
                ptr_r_l->parent->right = ptr_r_l;
        }
        else
            H->parent = ptr_r_l; // make ptr_r_l root if ptr was root

        ptr->height = Node_Height(ptr);
        ptr_r->height = Node_Height(ptr_r);
        ptr_r_l->height = Node_Height(ptr_r_l);

        return ptr_r_l;
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

        ++n;
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

        // updating  minimum and maximum value again
        if (H->parent == H)
        {
            H->left = H;
            H->right = H;
            return end();
        }
        // minimum
        mnode<key_type, T> *temp = H->parent;
        while (temp->left != H)
            temp = temp->left;
        H->left = temp;
        // maximum
        mnode<key_type, T> *temp2 = H->parent;
        while (temp2->right != H)
            temp2 = temp2->right;
        H->right = temp2;

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
        tnode<key_type> *to_del, *lc, *rc, *succ, *succ_p, *succ_r;
        tnode<key_type> *next;
        next = pos.ptr;
        ++next;
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
        // AVL BALANCING OF ERASE
        while (rebalance != H)
        {
            rebalance->height = Node_Height(rebalance);
            int bf = Balance_Node(rebalance);

            if (bf > 1)
            {
                if (Balance_Node(rebalance->left) >= 0)
                    rebalance = LL_Rotation(rebalance);
                else
                    rebalance = LR_Rotation(rebalance);
            }
            else if (bf < -1)
            {
                if (Balance_Node(rebalance->right) <= 0)
                    rebalance = RR_Rotation(rebalance);
                else
                    rebalance = RL_Rotation(rebalance);
            }

            rebalance = rebalance->parent;
        }

        // updating  minimum and maximum value again
        if (H->parent == H)
        {
            H->left = H;
            H->right = H;
            return end();
        }
        // minimum
        mnode<key_type, T> *temp = H->parent;
        while (temp->left != H)
            temp = temp->left;
        H->left = temp;
        // maximum
        mnode<key_type, T> *temp2 = H->parent;
        while (temp2->right != H)
            temp2 = temp2->right;
        H->right = temp2;

        return next;
    }
};
