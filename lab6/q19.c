#include <stdio.h>
#include <ctype.h>
#define max 100

float stk[max];
int top = -1;

void Push(float val);
float Pop();
float EvaluatePostfix(char expr[]);

int main()
{
    float value;
    char expr[max];

    printf("Enter Postfix Expression : ");
    gets(expr);

    value = EvaluatePostfix(expr);
    printf("\nEvaluation of the Postfix Expression = %.2f", value);
    return 0;
}

float EvaluatePostfix(char expr[])
{
    int i = 0;
    float op1, op2, value;
    while (expr[i] != '\0')
    {
        if (isdigit(expr[i]))
        {
            Push((float)(expr[i] - '0'));
        }
        else
        {
            op2 = Pop();
            op1 = Pop();
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
            Push(value);
        }
        i++;
    }
    return (Pop());
}

void Push(float value)
{
    if (top == max - 1)
    {
        printf("\nSTACK OVERFLOW");
    }
    else
    {
        top++;
        stk[top] = value;
    }
}

float Pop()
{
    float value = -1;
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW");
    }
    else
    {
        value = stk[top];
        top--;
    }
    return value;
}