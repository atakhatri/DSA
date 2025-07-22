#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {12,34,35,96,88,44,22},el,i,flag = 0;

    cout<<"what element you want to find? : ";
    cin>>el;

    for(i = 0;i < 10;i++)
    {
        if (el == arr[i])
        {
            cout<<"element "<<el<<" was found at index "<<i<<endl;
            flag++;
        }
    }

    if(flag == 0)
    {
        cout<<"\nelement was not available in given array !!\n";
    }

    return 0;
}