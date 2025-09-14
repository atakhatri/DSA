#include<iostream>
#include<cstring>
#include<stack>
#include <cctype>
using namespace std;
int top = -1;

int priority(char op)
{
    if (op == '/' || op == '+' || op == '%')
    {
        return 1;
    }
    else if (op == '+' || op == '-')
    {
        return 0;
    }
}

void InfixToPostfix(const char source[], char target[]) {
    stack<char> stk;
    int i = 0, j = 0;
    while (source[i] != '\0') {
        char ch = source[i];
        if (isalnum(ch)) {
            target[j++] = ch;
        } else if (ch == '(') {
            stk.push(ch);
        } else if (ch == ')') {
            while (!stk.empty() && stk.top() != '(') {
                target[j++] = stk.top();
                stk.pop();
            }
            if (stk.empty()) {
                cout << "\nInvalid Expression !!";
                exit(1);
            }
            stk.pop(); // remove '('
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
            while (!stk.empty() && stk.top() != '(' && priority(stk.top()) >= priority(ch)) {
                target[j++] = stk.top();
                stk.pop();
            }
            stk.push(ch);
        } else {
            cout << "\nInvalid Element in Expression !!";
            exit(1);
        }
        i++;
    }
    while (!stk.empty()) {
        if (stk.top() == '(') {
            cout << "\nInvalid Expression !!";
            exit(1);
        }
        target[j++] = stk.top();
        stk.pop();
    }
    target[j] = '\0';
}

int main()
{
    char infix[100],postfix[100];

    cout << "Enter an Expression : ";
    cin >> infix;
    strcpy(postfix, "");

    InfixToPostfix(infix,postfix);
    cout << "\nPostfix of given Expression : ";
    cout << postfix;
    return 0;
}
