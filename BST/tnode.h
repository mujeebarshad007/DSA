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
        key = key_type();
        is_nill = false;
    }
};