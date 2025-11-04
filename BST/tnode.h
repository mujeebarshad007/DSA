#pragma once

template <typename key_type>
struct tnode
{
    key_type key;
    tnode<key_type> *left, *right, *parent;
    bool is_nill;

    tnode()
    {
        left = right = parent = nullptr;
        key = key_type(); // default initialize key
        is_nill = false;
    }
};
