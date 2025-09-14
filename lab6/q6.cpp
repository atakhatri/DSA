#include<iostream>
#include<stdlib.h>
using namespace std;

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL;
void push(int val);
void pop();
void peek();
void display();

int main()
{
    int val,choice;
    while(choice != 5)
    {
        cout << "\n****** MAIN MENU || ARRAY || LL || CPP ******";
        cout << "\n1. PUSH";
        cout << "\n2. POP";
        cout << "\n3. PEEK";
        cout << "\n4. DISPLAY";
        cout << "\n5. EXIT";

        cout << "\n Enter the choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "\nEnter Number : ";
            cin >> val;
            push(val);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "\nEXIt FROM PROGRAM !!\n";
            break;

        default:
            cout << "\nINVALID CHOICE !!\nTRY AGAIN.\n";
            break;
        }
    }
    return 0;
}

void push(int val)
{
    struct stack *NewNode = new stack();
    NewNode -> data = val;
    if(top == NULL)
    {
        NewNode -> next = NULL;
        top = NewNode;
    }
    else
    {
        NewNode -> next = top;
        top = NewNode;
    }
    cout << top -> data << " pushed into the stack";
}

void pop()
{
    struct stack *ptr = top;
    if(ptr == NULL)
    {
        cout << "\nSTACK UNDERFLOW";
    }
    else
    {
        top = top -> next;
        cout <<endl << ptr -> data << " popped from the stack.";
        free(ptr);
    }
}

void peek()
{
    if(top == NULL)
    {
        cout << "\nSTACK UNDERFLOW";
    }
    else
    {
        cout << "\ntop of the stack = " << top -> data;
    }
}

void display()
{
    struct stack *ptr = top;
    if(ptr == NULL)
    {
        cout << "\nSTACK UNDERFLOW";
    }
    else
    {
        while(ptr != NULL)
        {
            cout << endl << ptr -> data;
            ptr = ptr -> next;
        }
    }
}
