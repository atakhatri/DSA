#include <iostream> // header file
using namespace std;

class Node // class for the structure of the node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList // class for the functions of the DLL
{
private:
    Node *head; // head pointer
    Node *tail; // tail pointer

public:
    DoublyLinkedList() // value initialized to null
    {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() // freeing the memory
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    void InsertAtBeg(int value) // function to add a node at the beginning of the DLL
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "\nNode added at the beginning.";
    }

    void InsertAtEnd(int value) // function to add a node at the end of the DLL
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "\nNode added at the end.";
    }

    void InsertAfterNode(int value, int after) // function to add a node after a given node in the DLL
    {
        if (head == nullptr)
        {
            InsertAtBeg(value);
            return;
        }
        Node *ptr = head;
        while (ptr != nullptr && ptr->data != after)
        {
            ptr = ptr->next;
        }
        if (ptr == nullptr)
        {
            cout << "\nNode with value " << after << " not found.";
            return;
        }
        Node *newNode = new Node(value);
        newNode->next = ptr->next;
        newNode->prev = ptr;
        if (ptr->next != nullptr)
        {
            ptr->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        ptr->next = newNode;
        cout << "\nNode added after " << after << ".";
    }

    void InsertBeforeNode(int value, int before) // function to add a node before a given node in the DLL
    {
        if (head == nullptr)
        {
            InsertAtBeg(value);
            return;
        }
        if (head->data == before)
        {
            InsertAtBeg(value);
            return;
        }
        Node *ptr = head;
        while (ptr != nullptr && ptr->data != before)
        {
            ptr = ptr->next;
        }
        if (ptr == nullptr)
        {
            cout << "\nNode with value " << before << " not found.";
            return;
        }
        Node *newNode = new Node(value);
        newNode->next = ptr;
        newNode->prev = ptr->prev;
        if (ptr->prev != nullptr)
        {
            ptr->prev->next = newNode;
        }
        ptr->prev = newNode;
        cout << "\nNode added before " << before << ".";
    }

    void InsertAtPos(int value, int pos) // function to add a node at a specific postion in the DLL
    {
        if (pos <= 0)
        {
            cout << "\nInvalid position!";
            return;
        }
        if (pos == 1)
        {
            InsertAtBeg(value);
            return;
        }
        Node *ptr = head;
        for (int i = 1; i < pos - 1 && ptr != nullptr; i++)
        {
            ptr = ptr->next;
        }
        if (ptr == nullptr)
        {
            cout << "\nInvalid position!";
            return;
        }
        Node *newNode = new Node(value);
        newNode->next = ptr->next;
        newNode->prev = ptr;
        if (ptr->next != nullptr)
        {
            ptr->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        ptr->next = newNode;
        cout << "\nNode added at position " << pos << ".";
    }

    void DeleteFromBeg() // function to delete a node from the beginning of the DLL
    {
        if (head == nullptr)
        {
            cout << "\nList is empty.";
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
        cout << "\nNode deleted from beginning.";
    }

    void DeleteFromEnd() // function to delete a node from the end of the DLL
    {
        if (head == nullptr)
        {
            cout << "\nList is empty.";
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        cout << "\nNode deleted from end.";
    }

    void DeleteAtPos(int pos) // function to delete a node from a specific position in the DLL
    {
        if (head == nullptr)
        {
            cout << "\nList is empty.";
            return;
        }
        if (pos <= 0)
        {
            cout << "\nInvalid position!";
            return;
        }
        if (pos == 1)
        {
            DeleteFromBeg();
            return;
        }
        Node *ptr = head;
        for (int i = 1; i < pos && ptr != nullptr; i++)
        {
            ptr = ptr->next;
        }
        if (ptr == nullptr)
        {
            cout << "\nInvalid position!";
            return;
        }
        if (ptr->prev != nullptr)
        {
            ptr->prev->next = ptr->next;
        }
        if (ptr->next != nullptr)
        {
            ptr->next->prev = ptr->prev;
        }
        else
        {
            tail = ptr->prev;
        }
        delete ptr;
        cout << "\nNode deleted from position " << pos << ".";
    }

    void Search(int value) // function to search for an element in the DLL
    {
        Node *ptr = head;
        int pos = 1;
        while (ptr != nullptr)
        {
            if (ptr->data == value)
            {
                cout << "\nNode with value " << value << " found at position " << pos << ".";
                return;
            }
            ptr = ptr->next;
            pos++;
        }
        cout << "\nNode with value " << value << " not found!";
    }

    void Display() // function to display the DLL
    {
        if (head == nullptr)
        {
            cout << "\nList is empty.";
            return;
        }
        Node *ptr = head;
        int count = 0;
        while (ptr != nullptr)
        {
            cout << ptr->data << " <-> ";
            ptr = ptr->next;
            count++;
        }
        cout << "END\nTotal nodes: " << count;
    }

    void DisplayReverse() // function to display the DLL in reverse
    {
        if (tail == nullptr)
        {
            cout << "\nList is empty.";
            return;
        }
        Node *ptr = tail;
        int count = 0;
        while (ptr != nullptr)
        {
            cout << ptr->data << " <-> ";
            ptr = ptr->prev;
            count++;
        }
        cout << "NULL\nTotal nodes: " << count;
    }
};

int main()
{
    DoublyLinkedList dll;
    int choice = 0, value, key;

    while (choice != 12)
    {
        cout << "\n\n************ MAIN MENU | DOUBLY LL | (C++) ************";
        cout << "\n1 : Add a node at Beginning";
        cout << "\n2 : Add a node at the End";
        cout << "\n3 : Add a node after a Node";
        cout << "\n4 : Add a node before a Node";
        cout << "\n5 : Add a node by Position";
        cout << "\n6 : Delete a node from the Beginning";
        cout << "\n7 : Delete a node from the End";
        cout << "\n8 : Delete a node by its Position";
        cout << "\n9 : Search for an element";
        cout << "\n10: Display the Linked List";
        cout << "\n11: Display the Linked List in reverse order";
        cout << "\n12: END the Operation !!!";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value to Add: ";
            cin >> value;
            dll.InsertAtBeg(value);
            break;
        case 2:
            cout << "Enter Value to Add: ";
            cin >> value;
            dll.InsertAtEnd(value);
            break;
        case 3:
            cout << "Enter Value to Add: ";
            cin >> value;
            cout << "Enter the value of node after which to insert: ";
            cin >> key;
            dll.InsertAfterNode(value, key);
            break;
        case 4:
            cout << "Enter Value to Add: ";
            cin >> value;
            cout << "Enter the value of node before which to insert: ";
            cin >> key;
            dll.InsertBeforeNode(value, key);
            break;
        case 5:
            cout << "Enter Value to Add: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> key;
            dll.InsertAtPos(value, key);
            break;
        case 6:
            dll.DeleteFromBeg();
            break;
        case 7:
            dll.DeleteFromEnd();
            break;
        case 8:
            cout << "Enter position to delete: ";
            cin >> key;
            dll.DeleteAtPos(key);
            break;
        case 9:
            cout << "Enter value to search: ";
            cin >> value;
            dll.Search(value);
            break;
        case 10:
            cout << "\nLinked List: ";
            dll.Display();
            break;
        case 11:
            cout << "\nLinked List in reverse order: ";
            dll.DisplayReverse();
            break;
        case 12:
            cout << "\nExit !!!";
            break;
        default:
            cout << "\nInvalid option. Try again.";
        }
    }
    return 0;
}
