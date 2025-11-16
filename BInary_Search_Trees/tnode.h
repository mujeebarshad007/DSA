#pragma once
template <typename key_type>
struct tnode
{
    key_type *parent;
    key_type *left, *right;
    bool is_nill;
    key_type key;

    tnode()
    {
        left = right = parent = nullptr;
        key = key_type();
        is_nill = false;
    }
};
