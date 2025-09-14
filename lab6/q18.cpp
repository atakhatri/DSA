#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>
using namespace std;
#define MAX 100

void ReverseExpr(const char str[], char result[]);
void InfixToPostfix(const char source[], char target[]);
int Priority(char);

char infix[MAX], postfix[MAX], tmp[MAX];

int main()
{
    cout << "Enter an Expression : ";
    cin.getline(infix, MAX);
    ReverseExpr(infix, tmp);
    strcpy(postfix, "");
    InfixToPostfix(tmp, postfix);
    cout << "\nPostfix Representation = " << postfix << endl;
    strcpy(tmp, "");
    ReverseExpr(postfix, tmp);
    cout << "\nPrefix Representation = " << tmp << endl;
    return 0;
}

void ReverseExpr(const char str[], char result[])
{
    int len = strlen(str), i = 0, j = len - 1;
    while (j >= 0)
    {
        if (str[j] == '(')
            result[i] = ')';
        else if (str[j] == ')')
            result[i] = '(';
        else
            result[i] = str[j];
        i++;
        j--;
    }
    result[i] = '\0';
}

void InfixToPostfix(const char source[], char target[])
{
    stack<char> stk;
    int i = 0, j = 0;

    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            stk.push(source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                target[j++] = stk.top();
                stk.pop();
            }
            if (stk.empty())
            {
                cout << "\nIncorrect Expression !!";
                exit(1);
            }
            stk.pop();
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j++] = source[i++];
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' ||
                 source[i] == '/' || source[i] == '%')
        {
            while (!stk.empty() && stk.top() != '(' &&
                   Priority(stk.top()) >= Priority(source[i]))
            {
                target[j++] = stk.top();
                stk.pop();
            }
            stk.push(source[i]);
            i++;
        }
        else
        {
            cout << "\nIncorrect Element in the Expression !!";
            exit(1);
        }
    }

    while (!stk.empty() && stk.top() != '(')
    {
        target[j++] = stk.top();
        stk.pop();
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
