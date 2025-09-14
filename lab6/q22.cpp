#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>
using namespace std;
#define max 100

int get_type(char);

int main()
{
    char expr[max];
    stack<int> stk;
    int len, value, i, op1, op2, res;

    cout << "Enter Prefix Expression : ";
    cin >> expr;
    len = strlen(expr);

    for (i = len - 1; i >= 0; i--)
    {
        switch (get_type(expr[i]))
        {
        case 0:
            value = expr[i] - '0';
            stk.push(value);
            break;

        case 1:
            op1 = stk.top();
            stk.pop();
            op2 = stk.top();
            stk.pop();
            switch (expr[i])
            {
            case '+':
                res = op1 + op2;
                break;

            case '-':
                res = op1 - op2;
                break;

            case '/':
                res = op1 / op2;
                break;

            case '*':
                res = op1 * op2;
                break;

            case '%':
                res = op1 % op2;
                break;
            }
            stk.push(res);
        }
    }
    cout << "\nResult = " << stk.top();
    return 0;
}

int get_type(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    {
        return 1;
    }
    else
        return 0;
}