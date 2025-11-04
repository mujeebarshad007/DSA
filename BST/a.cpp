tnode *nn, *temp;

// Create new node
nn = new tnode;
nn->left = H;
nn->right = H;
nn->parent = H;
nn->key = key;
isnill = false;

// If tree is empty
if (H->parent == H)
{
    H->parent = nn; // root
    H->left = nn;   // smallest
    H->right = nn;  // largest
    nn->parent = H;
    ++n;
    return;
}

temp = H->parent; // start from root

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
        delete nn;
        throw "Duplicate key not allowed";
    }
}

// update min & max
if (key < H->left->key)
    H->left = nn;
if (key > H->right->key)
    H->right = nn;

++n;
