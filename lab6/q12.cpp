#include <iostream>
#include <stack>
using namespace std;

int main()
{

    int n, val;
    stack<int> stk;
    cout << "Enter the size of the array : ";
    cin >> n;

    int num[n];
    cout << "Enter values for the array : \n";
    for (int i = 0; i < n; i++)
    {
        cout << "for index " << i << " : ";
        cin >> num[i];
    }

    cout << "\nORIGINAL ARRAY :";
    for (int i = 0; i < n; i++)
    {
        cout << "\nvalue at index " << i << " = " << num[i];
    }

    for (int i = 0; i < n; i++)
    {
        stk.push(num[i]);
    }
    for (int i = 0; i < n; i++)
    {
        val = stk.top();
        stk.pop();
        num[i] = val;
    }

    cout << "\n\nREVERSED ARRAY :";
    for (int i = 0; i < n; i++)
    {
        cout << "\nvalue at index " << i << " = " << num[i];
    }
    return 0;
}