#include <iostream>
using namespace std;

int main()
{
    int arr[10],n,i,el,pos;

    cout<<"enter the size of the array = ";
    cin>>n;

    cout<<"\ninsert values into the array :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"enter for index "<<i<<" : ";
        cin>>arr[i];
    }  
    cout<<endl;

    cout<<"ORIGINAL ARRAY :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }  
    cout<<endl;

    cout<<"insert the position from which the element is to be deleted : ";
    cin>>pos;

    for (int i = pos; i < n-1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;   

    cout<<"array after deletion of an element : \n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}