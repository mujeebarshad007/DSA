#include <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

class List
{
private:
    node *head;

public:
    List() : head(nullptr) {}
    int sum()
    {
        int sum = 0;
        node *temp;
        temp = head;
        while (temp != nullptr)
        {

            sum += temp->value;
            temp = temp->next;
        }
        return sum;
    }
    void push(int val)
    {
        node *temp = new node;
        temp->value = val;
        temp->next = nullptr;

        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            node *curr = head;
            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = temp;
        }
    }
    void display()
    {
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~List()
    {
        while (head != nullptr)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    List lst;
    lst.push(1);
    lst.push(2);
    lst.push(3);
    lst.push(4);
    std::cout << " The Sum of ALl the Elements is :" << lst.sum() << std::endl;
    std::cout << " The Elemnets Are :";

    std::cout << std::endl;
}
