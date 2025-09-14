#include<iostream>
#define max 100
using namespace std;
int stk[max],tp=-1;

class stack
{
public:
    void push(int tp,int val);
    void pop(int tp);
    void peek(int tp);
    void display(int tp);
};

void push(int val)
    {
        if(tp == max-1)
        {
            cout << "\nSTACK OVERFLOW";
        }
        else
        {
            tp++;
            stk[tp] = val;
            cout << val << " pushed into stack.";
        }
    }
    void pop()
    {
        int val;
        if(tp == -1)
        {
            cout << "\nSTACK UNDERFLOW";
        }
        else
        {
            val = stk[tp];
            tp--;
            cout << val << " popped from the stack.";
        }
    }

    void peek()
    {
        if(tp == -1)
        {
            cout << "STACK UNDERFLOW";
        }
        else
        {
            cout << "\ntop of the stack = " << stk[tp];
        }
    }

    void display()
    {
        int i;
        if(tp == -1)
        {
            cout << "\nSTACK UNDERFLOW";
        }
        else
        {
            cout << "\nSTACK:";
            for(i = tp;i >= 0;i--)
            {
                cout << "\n " << stk[i];
            }
        }
    }

int main()
{
    int val,choice;
    while(choice != 5)
    {
        cout << "\n****** MAIN MENU || ARRAY || CPP ******";
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
