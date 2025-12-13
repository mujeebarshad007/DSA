#include "mnode.h"
template <typename key_type, typename T>
class map
{
private:
    mnode<key_type, T> *H;
    int n;

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
        mnode<key_type, T> *ptr_l = ptr->left;         // left child
        mnode<key_type, T> *ptr_left_r = ptr_l->right; // left child's right

        ptr_l->right = ptr;     // left child becomes new root
        ptr->left = ptr_left_r; // attach subtree

        // update heights
        ptr->height = Node_Height(ptr);
        ptr_l->height = Node_Height(ptr_l);

        // if root was ptr, update root
        if (H->parent == ptr)
            H->parent = ptr_l;

        return ptr_l;
    }

    // RR Rotation (Right-Right)
    mnode<key_type, T> *RR_Rotation(mnode<key_type, T> *ptr)
    {
        mnode<key_type, T> *ptr_r = ptr->right;        // right child
        mnode<key_type, T> *ptr_right_l = ptr_r->left; // right child's left

        ptr_r->left = ptr;        // right child becomes new root of this subtree
        ptr->right = ptr_right_l; // attach subtree

        // update heights
        ptr->height = Node_Height(ptr);
        ptr_r->height = Node_Height(ptr_r);

        if (H->parent == ptr)
            H->parent = ptr_r;

        return ptr_r;
    }

    // LR Rotation (Left-Right)
    mnode<key_type, T> *LR_Rotation(mnode<key_type, T> *ptr)
    {
        // first rotate left child with RR rotation
        ptr->left = RR_Rotation(ptr->left);

        // then do LL rotation on ptr
        return LL_Rotation(ptr);
    }

    // RL Rotation (Right-Left)
    mnode<key_type, T> *RL_Rotation(mnode<key_type, T> *ptr)
    {
        // first rotate right child with LL rotation
        ptr->right = LL_Rotation(ptr->right);

        // then do RR rotation on ptr
        return RR_Rotation(ptr);
    }

    mnode<key_type, T> *successor(mnode<key_type, T> *ptr)
    {
        mnode<key_type, T> *temp = ptr->right;
        while (temp->left != H)
        {
            temp = temp->left;
        }
        return temp;
    }

public:
    map()
    {
        // TODO destructor make later
        H = new mnode<key_type, T>;
        n = 0;
        H->left = H->right = H->parent = H;
        H->is_nill = true;
    }

    map(const map &other)
    {
        H = new mnode<key_type, T>;
        H->left = H->right = H->parent = H;
        H->is_nill = true;
        n = 0;
        typename map<key_type, T>::iterator it;
        it = other.begin();
        while (it != other.end())
        {
            insert(*it);
            ++it;
        }
    }

    map &operator=(const map &other)
    {
        if (this != &other)
        {
            clear();
            typename map<key_type, T>::iterator it;
            it = other.begin();
            while (it != other.end())
            {
                insert({it->first, it->second});

                ++it;
            }
        }
        return *this;
    }

    void clear()
    {
        iterator it;
        it = begin();
        while (it != end())
        {
            erase(it);
            it = begin();
        }
    }
    class iterator
    {
    private:
        friend class map;
        mnode<key_type, T> *ptr;

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

        std::pair<key_type, T> &operator*() const
        {
            return this->ptr->data;
        }

        std::pair<key_type, T> *operator->() const
        {
            return &(ptr->data);
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
    iterator begin()
    {
        iterator it;
        mnode<key_type, T> *temp = H->parent;
        if (temp == H)
        {
            it.ptr = H;
            return it;
        }
        while (!temp->left->is_nill)
            temp = temp->left;
        it.ptr = temp;
        return it;
    }
    iterator end()
    {
        iterator it;
        it.ptr = H;
        return it;
    }
    iterator find(const key_type &key)
    {
        iterator r;
        r.ptr = H->parent; // start from root

        while (r.ptr != H)
        {
            if (key == r.ptr->data.first)
                break;
            else if (key < r.ptr->data.first)
                r.ptr = r.ptr->left;
            else
                r.ptr = r.ptr->right;
        }

        return r;
    }

    int count(const key_type &key)
    {
        iterator it;
        it = find(key);
        if (it != end())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool contains(const key_type &key)
    {
        return find(key) != end();
        // find(key) will give if value exist ,and end() will tell it doesnot exist
    }
    T &at(const key_type &key)
    {
        iterator it;
        it = find(key);
        if (it == end())
            throw("out of range");
        return it.ptr->data.second;
    }
    T &operator[](const key_type &key)
    {
        std::pair<iterator, bool> res;
        res = insert({key, T()});
        return res.first.ptr->data.second;
    }
    bool empty() const
    {
        return (H->parent == H);
    }

    int size() const
    {
        return n;
    }
    class reverse_iterator
    {
    private:
        mnode<key_type, T> *ptr;
        friend class map;

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

        std::pair<key_type, T> &operator*() const
        {
            return this->ptr->data;
        }

        bool operator==(const reverse_iterator &rhs) const
        {
            return (this->ptr == rhs.ptr);
        }

        std::pair<key_type, T> *operator->() const
        {
            return &(ptr->data);
        }
        bool operator!=(const reverse_iterator &rhs) const
        {
            return this->ptr != rhs.ptr;
        }
    };

    reverse_iterator r_begin()
    {
        reverse_iterator it;
        mnode<key_type, T> *temp = H->parent;
        if (temp == H)
        {
            it.ptr = H;
            return it;
        }
        while (!temp->right->is_nill)
            temp = temp->right;
        it.ptr = temp;
        return it;
    }
    reverse_iterator r_end()
    {
        reverse_iterator it;
        it.ptr = H;
        return it;
    }

    std::pair<iterator, bool> insert(const std::pair<key_type, T> &data)
    {
        mnode<key_type, T> *nn, *temp;

        nn = new mnode<key_type, T>;
        nn->left = nn->right = nn->parent = H;
        nn->data = data;
        nn->is_nill = false;
        nn->height = 1;
        // Agar tree empty hai

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
        // Tree mein insertion

        temp = H->parent;
        while (1)
        {
            if (data.first < temp->data.first)
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
            else if (data.first > temp->data.first)
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
                // duplicate key, update value

                temp->data.second = data.second; // duplicate value handling
                delete nn;
                iterator it;
                it.ptr = temp;
                return {it, false};
            }
        }

        if (data.first < H->left->data.first)
            H->left = nn;
        else if (data.first > H->right->data.first)
            H->right = nn;

        ++n;

        // balancing AVL
        mnode<key_type, T> *current = nn->parent;
        while (current != H)
        {
            current->height = Node_Height(current);
            int bf = Balance_Node(current);

            // LL case
            if (bf > 1 && Balance_Node(current->left) >= 0)
                current = LL_Rotation(current);

            // LR case
            else if (bf > 1 && Balance_Node(current->left) < 0)
                current = LR_Rotation(current);

            // RR case
            else if (bf < -1 && Balance_Node(current->right) <= 0)
                current = RR_Rotation(current);

            // RL case
            else if (bf < -1 && Balance_Node(current->right) > 0)
                current = RL_Rotation(current);

            // update root if needed
            if (current->parent == H)
                H->parent = current;

            current = current->parent;
        }

        // now to fix minimum and maximum value
        //  update H->left (min)
        mnode<key_type, T> *tmp = H->parent;
        while (!tmp->left->is_nill)
            tmp = tmp->left;
        H->left = tmp;

        // update H->right (max)
        tmp = H->parent;
        while (!tmp->right->is_nill)
            tmp = tmp->right;
        H->right = tmp;

        iterator it;
        it.ptr = nn;
        return {it, true};
    }

    iterator erase(iterator pos)
    {
        if (pos.ptr == H)
            return end();

        iterator next = pos; // next iterator for returning next
        ++next;

        mnode<key_type, T> *to_del = pos.ptr;

        // Case 1: leaf
        if (to_del->left == H && to_del->right == H)
        {
            if (to_del->parent == H)
            {
                H->parent = H;
                H->left = H;
                H->right = H;
            }
            else if (to_del->parent->left == to_del)
            {
                to_del->parent->left = H;
            }
            else
            {
                to_del->parent->right = H;
            }
            delete to_del;
        }
        // Case 2: one child (left)
        else if (to_del->left != H && to_del->right == H)
        {
            mnode<key_type, T> *lc = to_del->left;
            if (to_del->parent == H)
            {
                H->parent = lc;
                lc->parent = H;
            }
            else if (to_del->parent->left == to_del)
            {
                to_del->parent->left = lc;
                lc->parent = to_del->parent;
            }
            else
            {
                to_del->parent->right = lc;
                lc->parent = to_del->parent;
            }
            delete to_del;
        }
        // Case 3: one child (right)
        else if (to_del->left == H && to_del->right != H)
        {
            mnode<key_type, T> *rc = to_del->right;
            if (to_del->parent == H)
            {
                H->parent = rc;
                rc->parent = H;
            }
            else if (to_del->parent->left == to_del)
            {
                to_del->parent->left = rc;
                rc->parent = to_del->parent;
            }
            else
            {
                to_del->parent->right = rc;
                rc->parent = to_del->parent;
            }
            delete to_del;
        }
        // Case 4: two children
        else
        {
            mnode<key_type, T> *succ = successor(to_del); // leftmost of right
            to_del->data = succ->data;

            mnode<key_type, T> *succ_p = succ->parent;
            mnode<key_type, T> *succ_r = succ->right;

            if (succ_p->left == succ)
                succ_p->left = (succ_r != H ? succ_r : H);
            else
                succ_p->right = (succ_r != H ? succ_r : H);
            if (succ_r != H)
                succ_r->parent = succ_p;

            delete succ;
        }

        --n;
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

    ~map() // destructor
    {
        clear();
        delete H;
    }
};
