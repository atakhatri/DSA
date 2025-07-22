#include <iostream>
using namespace std;

int main()
{
    int arr[10],n,i,max=0;

    cout<<"enter the size of the array : ";
    cin>>n;

    for(i = 0;i < n;i++)
    {
        cout<<"enter for index "<<i<<" ";
        cin>>arr[i];

        if(max < arr[i])
        {
            max = arr[i];
        }
    }

    cout<<"biggest element of the array : "<<max;
    return 0;
}