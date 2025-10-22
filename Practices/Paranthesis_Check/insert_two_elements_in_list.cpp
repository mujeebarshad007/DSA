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
    List()
    {
        head = nullptr;
    }

    void insert(int val1, int val2)
    {
        node *temp1, *temp2, *temp;
        temp1 = new node;
        temp2 = new node;
        temp1->value = val1;
        temp2->value = val2;
        temp1->next = temp2;
        temp2->next = nullptr;

        if (head == nullptr)
        {
            head = temp1;
            return;
        }

        temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = temp1;
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