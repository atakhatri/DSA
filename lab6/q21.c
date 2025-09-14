#include <stdio.h>
#include <string.h>
#define max 100

int stk[max];
int top = -1;

void Push(int);
int Pop();
int get_type(char);

int main()
{
    char expr[max];
    int len, value, i, op1, op2, res;

    printf("Enter Prefix Expression : ");
    gets(expr);
    len = strlen(expr);

    for (i = len - 1; i >= 0; i--)
    {
        switch (get_type(expr[i]))
        {
        case 0:
            value = expr[i] - '0';
            Push(value);
            break;

        case 1:
            op1 = Pop();
            op2 = Pop();
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
            Push(res);
        }
    }
    printf("\nResult = %d", Pop());

    return 0;
}

void Push(int value)
{
    top++;
    stk[top] = value;
}

int Pop()
{
    return (stk[top--]);
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