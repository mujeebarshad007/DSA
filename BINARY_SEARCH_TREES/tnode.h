#pragma once
template <typename key_type>
struct tnode
{

    tnode<key_type> *parent, *left, *right;
    bool is_nill;
    key_type key;
    tnode()
    {
        left = right = parent = nullptr;
        is_nill = false;
    }
};