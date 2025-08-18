#include <stdio.h>
#include <stdlib.h> // Header File for malloc(),calloc(),realloc()

struct node // Structure for the nodes we create
{
    int data;
    struct node *next;
};

struct node *head = NULL;           // Head pointer which indicates first node
struct node *CreateNode(int value); // function to create a new node, NOTE : this func. won't be called directly by the users but by the other functions

void InsertAtBeg(int value);                  // function to insert a new node at the beginning of the LL
void InsertAtEnd(int value);                  // function to insert a new node at the end of the LL
void InsertAfterNode(int value, int after);   // function to insert a new node after a given node in the LL
void InsertBeforeNode(int value, int before); // function to insert a new node before a given node in the LL
void InsertAtPos(int value, int pos);         // function to insert a new node at given position in the LL

void DeleteFromBeg();            // function to delete a node from the beginning of the LL
void DeleteFromEnd();            // function to delete a node from the end of the LL
void DeleteAfterNode(int after); // function to delete a node after a given node in the LL
void DeleteByVal(int value);     // function to delete a specific node in the LL

void Search(int value); // function to Search an element from the LL
void Display();         // function to display the LL

int main()
{
    int choice = 0, value, key;
    while (choice != 12)
    {
        printf("\n\n************ MAIN MENU (C) ************");

        printf("\n1 : Add a node at Beginning");
        printf("\n2 : Add a node at the End");
        printf("\n3 : Add a node after a Node");
        printf("\n4 : Add a node before a node");
        printf("\n5 : Add a node at position");

        printf("\n6 : Delete a node from the Beginning");
        printf("\n7 : Delete a node from the End");
        printf("\n8 : Delete a node after a node");
        printf("\n9 : Delete a node by value");

        printf("\n10: Search an element");
        printf("\n11: Display the Linked List");
        printf("\n12: END the Operation !!!");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // calling InsertAtBeg(value) function to add a node in the Beginning of the LL
            printf("Enter Value to Add : ");
            scanf("%d", &value);
            InsertAtBeg(value);
            break;

        case 2: // calling InsertAtEnd(value) function to add a node in the End of the LL
            printf("Enter Value to Add : ");
            scanf("%d", &value);
            InsertAtEnd(value);
            break;

        case 3: // calling InsertAfterNode(value,key) function to add a node after a node in the LL
            printf("Enter Value to Add : ");
            scanf("%d", &value);
            printf("Enter the Value of node coming before the new node : ");
            scanf("%d", &key);
            InsertAfterNode(value, key);
            break;

        case 4: // calling InsertBeforeNode(value,key) function to add a node before a node in the LL
            printf("Enter Value to Add : ");
            scanf("%d", &value);
            printf("Enter the Value of node coming after the new node : ");
            scanf("%d", &key);
            InsertBeforeNode(value, key);
            break;

        case 5: // calling InsertAtPos(value,key) function to add a node on given postion in the LL
            printf("Enter Value to Add : ");
            scanf("%d", &value);
            printf("Enter the postion at-which it is to be added : ");
            scanf("%d", &key);
            InsertAtPos(value, key);
            break;

        case 6: // calling DeleteFromBeg() function to delete a node from the Beginning of the LL
            DeleteFromBeg();
            break;

        case 7: // calling DeleteFromEnd() function to delete a node from the End of the LL
            DeleteFromEnd();
            break;

        case 8: // calling DeleteAfterNode(key) function to delete a node after a given node
            printf("Enter the value of node coming before the node : ");
            scanf("%d", &key);
            DeleteAfterNode(key);
            break;

        case 9: // calling DeleteByVal(value) function to delete a node by its value
            printf("Enter the value of node you want to delete : ");
            scanf("%d", &value);
            DeleteByVal(value);
            break;

        case 10: // calling Search(value) function to search for an element
            printf("Enter the value you want to search : ");
            scanf("%d", &value);
            Search(value);
            break;

        case 11: // calling Display() function to Display the LL
            Display();
            break;

        case 12: // exiting from the program
            printf("\nExit !!!");
            break;

        default:
            printf("\nInvalid option. Try again.");
            break;
        }
    }
    return 0;
}

struct node *CreateNode(int value) // Creating a new node NOTE : this function won't be called directly by the user
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void InsertAtBeg(int value) // Inserting at beginning
{
    struct node *new_node = CreateNode(value);
    new_node->next = head;
    head = new_node;
    printf("\nNode Added at the beginning.");
}

void InsertAtEnd(int value) // Inserting at end
{
    if (head == NULL)
    {
        InsertAtBeg(value);
    }
    else
    {
        struct node *new_node = CreateNode(value);
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        printf("\nNode Added at the end.");
    }
}

void InsertAfterNode(int value, int after) // inserting after a node
{
    if (head == NULL)
    {
        InsertAtBeg(value);
    }
    else
    {
        struct node *new_node = CreateNode(value);
        struct node *ptr = head;
        while (ptr != NULL && ptr->data != after)
        {
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
        printf("\nNode Added after the Node having value %d.", after);
    }
}

void InsertBeforeNode(int value, int before) // inserting before a node
{
    struct node *new_node = CreateNode(value);
    if (head == NULL)
    {
        InsertAtBeg(value);
    }
    else if (head->data == before)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL && ptr->next->data != before)
        {
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
        printf("\nNode Added before the Node having value %d.", before);
    }
}

void InsertAtPos(int value, int pos) // inserting at position
{
    if (pos == 0)
    {
        InsertAtBeg(value);
        return;
    }
    struct node *new_node = CreateNode(value);
    struct node *ptr = head;
    for (int i = 0; i < pos - 2 && ptr != NULL; i++)
    {
        if (ptr == NULL)
        {
            printf("\nInvalid Position !!");
            return;
        }
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    printf("\nNode Added at position %d.", pos);
}

void DeleteFromBeg() // Deleting from the Beginning
{
    if (head == NULL)
    {
        printf("\nEmpty List !!!");
        return;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    printf("\nNode Deleted from the Beginning.");
}

void DeleteFromEnd() // Deleting from the End
{
    if (head == NULL)
    {
        printf("\nEmpty List !!!");
        return;
    }
    struct node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    printf("\nNode Deleted from the End.");
}

void DeleteAfterNode(int after) // Deleting after a node
{
    struct node *ptr = head;
    while (ptr != NULL && ptr->data != after)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL || ptr->next == NULL)
    {
        printf("\nValue not found !!\nTry again !!!");
        return;
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    printf("\nNode deleted after the node having value %d.", after);
}

void DeleteByVal(int value) // deleting by value
{
    if (head == NULL)
    {
        printf("\nEmpty List !!!");
        return;
    }
    struct node *ptr = head;
    while (ptr->next != NULL && ptr->next->data != value)
    {
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        printf("\nNode with value %d not found in the LL !! ", value);
        return;
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    printf("\nNode with value %d deleted from the LL.", value);
}

void Search(int value) // Searching for an element
{
    struct node *ptr = head;
    int pos = 1;
    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            printf("\n%d found at node having position %d\n", ptr->data, pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    printf("\nNode with value %d not found in the LL !\n", value);
}

void Display() // Displaying the list
{
    int count = 0; // counting total nodes
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("\nLinked List: ");
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        count++; // increasing count by one
        ptr = ptr->next;
    }
    printf("END\n");
    printf("Total number of nodes : %d", count);
}