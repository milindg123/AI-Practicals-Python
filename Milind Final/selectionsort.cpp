#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<" Enter the Size of the array: \n";
    cin>>n;
    int arr[n];
    cout<<" Enter Elements of the Array: \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int min=0;
    int cnt=0;

    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                int temp=arr[min];
                arr[min]=arr[j];
                arr[j]=temp;
            }

        }
            cnt++;
            cout<<" Pass "<<cnt<<":";
            for(int k=0;k<n;k++)
            {
                cout<<"->";
                cout<<arr[k]<<" ";
            }
            cout<<endl;
    }
    cout<<endl;
    cout<<"Sorted Array is :";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
