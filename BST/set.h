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
    void insert(const<key_type> &key)
    {
        tnode<key_type> *nn, *temp;
    }
};
// void insert(const key_type &key)
//     {
//         tnode<key_type> *nn = new tnode<key_type>;
//         nn->key = key;
//         nn->left = nn->right = nn->parent = H;
//         nn->is_nill = false;

//         if (H->parent == H)  // tree empty
//         {
//             H->parent = H->left = H->right = nn;
//             nn->parent = H;
//             return;
//         }

//         tnode<key_type> *temp = H->parent;  // start from root
//         while (true)
//         {
//             if (key < temp->key)
//             {
//                 if (temp->left != H)
//                     temp = temp->left;
//                 else
//                 {
//                     temp->left = nn;
//                     nn->parent = temp;
//                     break;
//                 }
//             }
//             else if (key > temp->key)
//             {
//                 if (temp->right != H)
//                     temp = temp->right;
//                 else
//                 {
//                     temp->right = nn;
//                     nn->parent = temp;
//                     break;
//                 }
//             }
//             else
//             {
//                 delete nn;
//                 throw "Duplicate key";
//             }
//         }

//         // update smallest and largest trackers
//         if (key < H->left->key)
//             H->left = nn;
//         if (key > H->right->key)
//             H->right = nn;
//     }