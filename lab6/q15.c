#include<stdio.h>
#include<string.h>

#define max 100
char stk[max];
int top = -1;

void Push(char);
char Pop();
void InfixToPostfix(char source[],char target[]);
int priority(char);

int main()
{
    char infix[max],postfix[max];

    printf("Enter an Expression : ");
    gets(infix);
    strcpy(postfix, "");

    InfixToPostfix(infix,postfix);
    printf("\nPostfix of given Expression : ");
    puts(postfix);
    return 0;
}

void InfixToPostfix(char source[],char target[])
{
    int i = 0, j = 0;
    char tmp;
    strcpy(target, "");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            Push(source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (stk[top] != '('))
            {
                target[j] = Pop();
                j++;
            }
            if (top == -1)
            {
                printf("\nInvalid Expression !!");
                exit(1);
            }
            tmp = Pop();
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while ((top != -1) && (stk[top] != '(') && (priority(stk[top]) > priority(source[i])))
            {
                target[j] = Pop();
                j++;
            }
            Push(source[i]);
            i++;
        }
        else
        {
            printf("\n Invalid Element in Expression !!");
            exit(1);
        }
    }
    while ((top != -1) && (stk[top] != '('))
    {
        target[j] = Pop();
        j++;
    }
    target[j] = '\0';
}

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

void Push(char c)
{
    if (top == max)
    {
        printf("\nSTACK OVERFLOW !!");
    }
    else
    {
        top++;
        stk[top] = c;
    }
}

char Pop()
{
    char val = ' ';
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW !!");
    }
    else
    {
        val = stk[top];
        top--;
    }
    return val;
}
