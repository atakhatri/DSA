#include <iostream>
using namespace std;

int main()
{
    int arr[10],n,i,lead[10],p = 1;

    cout<<"enter the size of the array : ";
    cin>>n;

    for(i = 0;i < n;i++)
    {
        cout<<"enter for index "<<i<<" ";
        cin>>arr[i];
    }

    cout<<"\nMAIN ARRAY : \n";
    for(i = 0;i < n;i++)
    {
        cout<<arr[i]<<" ";
    }

    lead[0] = arr[n-1];
    for(i = n-1;i > 0;i--)
    {
        if(arr[i] < arr[i-1])
        {
            continue;
        }
        else if(arr[i] > lead[p-1])
        {
            lead[p] = arr[i];
            p++;
        }
    }

    cout<<"\nLEADER ELEMENTS : \n";
    for(i = 0;i < p;i++)
    {
        cout<<lead[i]<<" ";
    }

    return 0;
}
