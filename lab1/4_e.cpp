#include <iostream>
using namespace std;

int main()
{
    int arr[10],n,i,min;

    cout<<"enter the size of the array : ";
    cin>>n;

    for(i = 0;i < n;i++)
    {
        cout<<"enter for index "<<i<<" ";
        cin>>arr[i];

        if(min > arr[i])
        {
            min = arr[i];
        }
    }

    cout<<"smallest element of the array : "<<min;
    return 0;
}