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
};
