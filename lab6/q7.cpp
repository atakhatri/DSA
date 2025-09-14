#include<iostream>
#include<stack>
#define max 100
using namespace std;


int main()
{
    stack<int> stk;
    int val,choice;
    while(choice != 5)
    {
        cout << "\n****** MAIN MENU || STL || CPP ******";
        cout << "\n1. PUSH";
        cout << "\n2. POP";
        cout << "\n3. TOP";
        cout << "\n4. DISPLAY";
        cout << "\n5. EXIT";

        cout << "\n Enter the choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "\nEnter Number : ";
            cin >> val;
            stk.push(val);
            cout << val << " pushed into the stack";
            break;

        case 2:
            cout << stk.top() << " popped from the stack";
            stk.pop();
            break;

        case 3:
            cout << "top of the stack = " << stk.top();
            break;

        case 4:
            cout << "\nSTACK:\n";
            while(!stk.empty())
            {
                cout << stk.top() << endl;
                stk.pop();
            }
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
