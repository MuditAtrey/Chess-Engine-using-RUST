#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class singlylinklist
{
public:
    Node *head;
    singlylinklist()
    {
        head = NULL;
    }
    // insert at first
    void insertAtFirst(int item)
    {
        Node *newNode = new Node(); // data -->address
        newNode->data = item;
        newNode->next = head;
        head = newNode;
        cout << "node insert at first" << endl;
    }
    // Display
    void display()
    {
        if (head == NULL)
        {
            cout << "list is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "-->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    // insert at last
    void insertAtLast(int item)
    {
        Node *newNode = new Node();
        newNode->data = item;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode; // it will treverse list until tem->next is not null.
            cout << "node insert at last" << endl;
        }
    }
    // insert at position
    void insertAtPosition(int item, int pos)
    {
        Node *newNode = new Node();
        newNode->data = item;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos; i++)
            {
                if (temp == NULL)
                {
                    cout << "out of range:" << endl;
                }
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "node insert at position : " << endl;
        }
    }
};
int main()
{
    singlylinklist obj;
    int choice, value, pos;
    do
    {
        cout << "1. insert at first" << endl;
        cout << "2. display" << endl;
        cout << "3. insert at last " << endl;
        cout << "4. insert at position " << endl;
        cout << "enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter value :";
            cin >> value;
            obj.insertAtFirst(value);

            break;
        case 2:
            obj.display();
            break;
        case 3:
            cout << "enter value :";
            cin >> value;
            obj.insertAtLast(value);
            break;
        case 4:
            cout << "enter value :";
            cin >> value;
            cout << "enter position : ";
            cin >> pos;
            obj.insertAtPosition(value, pos);
            break;
        }
    } while (choice != 5);
}