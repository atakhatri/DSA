#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define max 100

char stk[max];
int top = -1;

void ReverseExpr(char str[]);
void push(char);
char pop();
void InfixToPostfix(char source[], char target[]);
int Priority(char);

char infix[max], postfix[max], tmp[max];

int main()
{
    printf("Enter an Expression : ");
    fgets(infix, max, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // remove newline

    ReverseExpr(infix);

    strcpy(postfix, "");
    InfixToPostfix(tmp, postfix);
    printf("\nPostfix Representation = ");
    puts(postfix);

    strcpy(tmp, "");
    ReverseExpr(postfix);
    printf("\nPrefix Representation = ");
    puts(tmp);
    return 0;
}

void ReverseExpr(char str[])
{
    int len = strlen(str), i = 0, j = len - 1;
    while (j >= 0)
    {
        if (str[j] == '(')
            tmp[i] = ')';
        else if (str[j] == ')')
            tmp[i] = '(';
        else
            tmp[i] = str[j];
        i++;
        j--;
    }
    tmp[i] = '\0';
}

void InfixToPostfix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (stk[top] != '('))
            {
                target[j++] = pop();
            }
            if (top == -1)
            {
                printf("\nIncorrect Expression !!");
                exit(1);
            }
            temp = pop();
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j++] = source[i++];
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while ((top != -1) && (stk[top] != '(') && (Priority(stk[top]) >= Priority(source[i])))
            {
                target[j++] = pop();
            }
            push(source[i]);
            i++;
        }
        else
        {
            printf("\nIncorrect Element in the Expression !!");
            exit(1);
        }
    }
    while ((top != -1) && (stk[top] != '('))
    {
        target[j++] = pop();
    }
    target[j] = '\0';
}

int Priority(char op)
{
    if (op == '/' || op == '*' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
    return -1;
}

void push(char val)
{
    if (top == max - 1)
        printf("\n STACK OVERFLOW");
    else
        stk[++top] = val;
}

char pop()
{
    if (top == -1)
    {
        printf("\n STACK UNDERFLOW");
        return ' ';
    }
    return stk[top--];
}
