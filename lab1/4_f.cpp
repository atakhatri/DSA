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

    cout<<"insert the element to add : ";
    cin>>el;
    cout<<"select where to add the given element : ";
    cin>>pos;
    cout<<endl;

    for (int i = 10; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = el;
    n++;

    cout<<"array after adding new element : \n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}