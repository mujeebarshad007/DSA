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

    void insert(int val1, int val2)
    {
        node *temp1 = new node{val1, nullptr};
        node *temp2 = new node{val2, nullptr};

        temp1->next = temp2; // link the pair

        if (head == nullptr)
        {
            head = temp1;
            return;
        }

        // traverse to last node
        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = temp1; // link new pair at end
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
    lst.insert(1, 2);
    lst.insert(3, 4);
    lst.insert(5, 6);
    lst.insert(7, 8);

    lst.display();
}
