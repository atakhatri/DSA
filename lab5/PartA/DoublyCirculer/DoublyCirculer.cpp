#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int v) : data(v), next(nullptr), prev(nullptr) {}
};

class DoublyCircular
{
private:
    Node *head; // keep head; tail is head->prev if exists
public:
    DoublyCircular() : head(nullptr) {}
    ~DoublyCircular()
    {
        if (!head)
            return;
        Node *cur = head->next;
        head->prev->next = nullptr; // break circle
        while (cur)
        {
            Node *t = cur;
            cur = cur->next;
            delete t;
        }
        delete head;
    }

    void InsertAtBeg(int v)
    {
        Node *n = new Node(v);
        if (!head)
        {
            head = n;
            n->next = n;
            n->prev = n;
        }
        else
        {
            Node *tail = head->prev;
            n->next = head;
            n->prev = tail;
            tail->next = n;
            head->prev = n;
            head = n;
        }
        cout << "Inserted at beginning.\n";
    }

    void InsertAtEnd(int v)
    {
        if (!head)
        {
            InsertAtBeg(v);
            return;
        }
        Node *n = new Node(v);
        Node *tail = head->prev;
        tail->next = n;
        n->prev = tail;
        n->next = head;
        head->prev = n;
        cout << "Inserted at end.\n";
    }

    void DeleteFromBeg()
    {
        if (!head)
        {
            cout << "Empty\n";
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            cout << "Deleted\n";
            return;
        }
        Node *tail = head->prev;
        Node *nxt = head->next;
        tail->next = nxt;
        nxt->prev = tail;
        delete head;
        head = nxt;
        cout << "Deleted from beginning.\n";
    }

    void DeleteFromEnd()
    {
        if (!head)
        {
            cout << "Empty\n";
            return;
        }
        Node *tail = head->prev;
        if (tail == head)
        {
            delete head;
            head = nullptr;
            cout << "Deleted\n";
            return;
        }
        Node *newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
        delete tail;
        cout << "Deleted from end.\n";
    }

    void DisplayForward()
    {
        if (!head)
        {
            cout << "Empty\n";
            return;
        }
        Node *cur = head;
        cout << "List: ";
        do
        {
            cout << cur->data << " <-> ";
            cur = cur->next;
        } while (cur != head);
        cout << "(back)\n";
    }

    void DisplayBackward()
    {
        if (!head)
        {
            cout << "Empty\n";
            return;
        }
        Node *tail = head->prev;
        Node *cur = tail;
        cout << "Reverse: ";
        do
        {
            cout << cur->data << " <-> ";
            cur = cur->prev;
        } while (cur != tail);
        cout << "(back)\n";
    }
};

int main()
{
    DoublyCircular dll;
    int ch = 0, val;
    while (ch != 0)
    {
        cout << "\n1.InBeg \n2.InEnd \n3.DelBeg \n4.DelEnd \n5.DisplayF \n6.DisplayB \n0.Exit \nChoice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Val: ";
            cin >> val;
            dll.InsertAtBeg(val);
            break;
        case 2:
            cout << "Val: ";
            cin >> val;
            dll.InsertAtEnd(val);
            break;
        case 3:
            dll.DeleteFromBeg();
            break;
        case 4:
            dll.DeleteFromEnd();
            break;
        case 5:
            dll.DisplayForward();
            break;
        case 6:
            dll.DisplayBackward();
            break;
        case 0:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid Choice !!\n";
        }
    }
    return 0;
}
