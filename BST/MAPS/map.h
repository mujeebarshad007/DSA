#include "mnode.h"
template <typename key_type, typename T>
class map
{
private:
    mnode<key_type, T> *H;
    int n;

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
        H = new mnode<key_type, T>;
        n = 0;
        H->left = H->right = H->parent = H;
        H->is_nill = true;
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
        mnode<key_type, T> *temp = H->right;
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

    std::pair<iterator, bool> insert(const std::pair<key_type, T> &data)
    {
        mnode<key_type, T> *nn, *temp;

        nn = new mnode<key_type, T>;
        nn->left = nn->right = nn->parent = H;
        nn->data = data;
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

                temp->data.second = data.second;
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

        iterator it;
        it.ptr = nn;
        return {it, true};
    }

    iterator erase(iterator pos)
    {
        mnode<key_type, T> *to_del, *lc, *rc, *succ, *succ_p, *succ_r;
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

                succ->left = to_del->left;
                succ->right = to_del->right;

                if (to_del->left != H)
                    to_del->left->parent = succ;
                if (to_del->right != H)
                    to_del->right->parent = succ;
            }

            succ->parent = to_del->parent;
            succ->data = to_del->data;
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
        iterator ret;
        ret.ptr = H;
        return ret;
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
};
