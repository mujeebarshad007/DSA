template <typename U>
bool operator<(const stack<U> &lhs, const stack<U> &rhs)
{
    // Compare sizes first (optional depending on your logic)
    int minSize = (lhs.size() < rhs.size()) ? lhs.size() : rhs.size();

    // Compare elements one by one
    for (int i = 0; i < minSize; i++)
    {
        if (lhs.DATA[i] < rhs.DATA[i]) // lhs element is smaller
            return true;
        if (lhs.DATA[i] > rhs.DATA[i]) // rhs element is smaller
            return false;
    }

    return lhs.size() < rhs.size();
}
