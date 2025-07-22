#include <iostream>
using namespace std;

int main()
{
    int arr[10],n,el,i,flag = 0;
    
    cout<<"enter the size of the array : ";
    cin>>n;

    for(i = 0;i < n;i++)
    {
        cout<<"enter element for index "<<i<<" : ";
        cin>>arr[i];
    }

    cout<<"\nTHE ARRAY :\n";
    for (i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"\nwhat element you want to find? : ";
    cin>>el;

    for(i = 0;i < 10;i++)
    {
        if (el == arr[i])
        {
            cout<<"\nelement "<<el<<" was found at index "<<i<<endl;
            flag++;
            if (i == 0)
            {
                cout<<"best case possible !!,as element found at index 0";
            }
            else if(i == n-1)
            {
                cout<<"worst case possible !!,as element was found at last index";
            }
            else
            {
                cout<<"average case !!,as element was found somewhere in between";
            }
            
            
        }
    }

    if(flag == 0)
    {
        cout<<"\nelement was not available in given array !!\n";
    }

    return 0;
}