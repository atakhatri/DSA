#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>
using namespace std;
#define max 100

float EvaluatePostfix(char expr[]);

int main()
{
    float value;
    char expr[max];

    cout << "Enter Postfix Expression : ";
    cin >> expr;

    value = EvaluatePostfix(expr);
    cout << "\nEvaluation of the Postfix Expression = " << value;
    return 0;
}

float EvaluatePostfix(char expr[])
{
    stack<float> stk;
    int i = 0;
    float op1, op2, value;

    while (expr[i] != '\0')
    {
        if (isdigit(expr[i]))
        {
            stk.push((float)(expr[i] - '0'));
        }
        else
        {
            op2 = stk.top();
            stk.pop();
            op1 = stk.top();
            stk.pop();

            switch (expr[i])
            {
            case '+':
                value = op1 + op2;
                break;

            case '-':
                value = op1 - op2;
                break;

            case '/':
                value = op1 / op2;
                break;

            case '*':
                value = op1 * op2;
                break;

            case '%':
                value = (int)op1 % (int)op2;
                break;

            default:
                break;
            }
            stk.push(value);
        }
        i++;
    }
    return (stk.top());
}