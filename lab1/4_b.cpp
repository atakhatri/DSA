#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {0},n,i,count = 0;

    cout<<"enter the size of the array : ";
    cin>>n;

    for (i = 0; i < n; i++)
    {
        cout<<"input for "<<i<<" : ";
        cin>>arr[i];
        if(arr[i] != 0)
        {
            count++;
        }
    }

    cout<<"\ncount = "<<count;
    
    return 0;
}