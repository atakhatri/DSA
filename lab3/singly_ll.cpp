#include <iostream>
using namespace std;

struct node // Structure for the nodes we create
{
    int data;
    struct node *next;
};

struct node *head = nullptr;                  // Head pointer which indicates first node
struct node *CreateNode(int value);           // function to create a new node, NOTE : this fun. won't be called directly by the users but by the other functions
void InsertAtBeg(int value);                  // function to insert a new node at the beginning of the LL
void InsertAtEnd(int value);                  // function to insert a new node at the end of the LL
void InsertAfterNode(int value, int after);   // function to insert a new node after a given node in the LL
void InsertBeforeNode(int value, int before); // function to insert a new node before a given node in the LL
void DeleteFromBeg();                         // function to delete a node from the beginning of the LL
void DeleteFromEnd();                         // function to delete a node from the end of the LL
void Display();                               // function to display the created LL

int main()
{
    int choice = 0, value, after, before;
    while (choice != 8)
    {
        cout << "\n\n************ MAIN MENU (CPP) ************";
        cout << "\n1 : Add a node at Beginning";
        cout << "\n2 : Add a node at the End";
        cout << "\n3 : Add a node after a Node";
        cout << "\n4: Add a node before a node";
        cout << "\n5 : Delete a node from the Beginning";
        cout << "\n6 : Delete a node from the End";
        cout << "\n7 : Display the Linked List";
        cout << "\n8 : END the Operation !!!";
        cout << "\n\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1: // calling InsertAtBeg(value) function to add a node in the Beginning of the LL
            cout << "Enter Value to Add : ";
            cin >> value;
            InsertAtBeg(value);
            cout << "\nNode Added at the Beginning.";
            break;

        case 2: // calling InsertAtEnd(value) function to add a node in the End of the LL
            cout << "Enter Value to Add : ";
            cin >> value;
            InsertAtEnd(value);
            cout << "\nNode Added at the End.";
            break;

        case 3: // calling InsertAfterNode(value,after) function to add a node after a node in the LL
            cout << "Enter Value to Add : ";
            cin >> value;
            cout << "Enter the Value of node coming before the new node : ";
            cin >> after;
            InsertAfterNode(value, after);
            cout << "\nNode Added after the node having value " << after << ".";
            break;

        case 4: // calling InsertBeforeNode(value,before) function to add a node before a node in the LL
            cout << "Enter Value to Add : ";
            cin >> value;
            cout << "Enter the Value of node coming after the new node : ";
            cin >> before;
            InsertBeforeNode(value, before);
            cout << "\nNode Added before the node having value " << before << ".";
            break;

        case 5: // calling DeleteFromBeg() function to delete a node from the Beginning of the LL
            DeleteFromBeg();
            cout << "\nNode Deleted from the Beginning.";
            break;

        case 6: // calling DeleteFromEnd() function to delete a node from the End of the LL
            DeleteFromEnd();
            cout << "\nNode Deleted from the End.";
            break;

        case 7: // calling Display() function to Display the created LL
            cout << "\nLinked List : ";
            Display();
            break;

        case 8: // exiting from the program
            cout << "\nExit !!!";
            break;

        default:
            cout << "\nInvalid option, Try again.";
            break;
        }
    }
    return 0;
}

struct node *CreateNode(int value) // Creating a new node NOTE : this function won't be called directly by the user
{
    struct node *newNode = new node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void InsertAtBeg(int value) // Inserting at beginning
{
    struct node *new_node = CreateNode(value);
    new_node->next = head;
    head = new_node;
}

void InsertAtEnd(int value) // Inserting at end
{
    struct node *new_node = CreateNode(value);

    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

void InsertAfterNode(int value, int after)
{
    struct node *new_node = CreateNode(value);
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        struct node *ptr = head;
        while (ptr != nullptr && ptr->data != after)
        {
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

void InsertBeforeNode(int value, int before)
{
    struct node *new_node = CreateNode(value);
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != nullptr && ptr->next->data != before)
        {
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

void DeleteFromBeg() // Deleting from the Beginning
{
    if (head == nullptr)
    {
        cout << "\nEmpty List !!!";
        return;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
}

void DeleteFromEnd() // Deleting from the End
{
    if (head == nullptr)
    {
        cout << "\nEmpty List !!!";
        return;
    }
    struct node *ptr = head;
    while (ptr->next->next != nullptr)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = nullptr;
}

void Display() // Displaying the list
{
    int count = 0; // counting total nodes in the LL
    struct node *ptr = head;
    if (ptr == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }
    while (ptr != nullptr)
    {
        cout << ptr->data << " -> ";
        count++; // increasing count by one
        ptr = ptr->next;
    }
    cout << "END !!\n";
    cout << "Total number of nodes : " << count;
}
