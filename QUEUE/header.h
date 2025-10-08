struct node
{
    int value;
    node *link;
};

class queue
{
private:
    node *F;
    node *B;
    int n;

public:
    queue()
    {
        n = 0;
        F = nullptr;
        B = nullptr;
    }

    int front() const
    {
        if (F == nullptr && B == nullptr)
        {
            throw "Queue Underflow";
        }
        else
        {

            return F->value;
        }
    }
    int back() const
    {
        if (F == nullptr && B == nullptr)
        {
            throw "Queue Underflow";
        }
        else
        {

            return B->value;
        }
    }
    void push(int v)
    {

        if (F == nullptr)
        {
            node *temp;
            temp = new node; // TODO Deallocate memory
            temp->value = v;
            F = temp;
            B = temp;
        }
        else
        {
            node *temp;
            temp = new node;
            B->link = temp;
            temp->value = v;
            B = temp;
        }
        n++;
    }

    void pop()
    {
        if (F == nullptr && B == nullptr)
        {
            throw "Queue Underflow";
        }
        else
        {
            node *temp;
            temp = F;
            F = F->link;
            delete temp;
            n--;
        }
        if (F == nullptr)
        {
            B = nullptr;
        }
    }

    int size() const
    {
        if (F == nullptr && B == nullptr)
        {
            throw "Queue Underflow";
        }
        else
        {
            return n;
        }
    }
    bool empty() const
    {
        if (F == nullptr && B == nullptr || n == 0)
        {
            return true;
        }
        else
            return false;
    }
    ~queue()
    {
        while (!empty())
        {
            pop();
        }
    }
};
