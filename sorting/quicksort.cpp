#include<bits/stdc++.h>
using namespace std;

void printarray(vector<int> arr)
{
    for(int i = 0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int partition(vector<int> &arr, int l, int r, int ele)
{
    int j = l;
    for(int i = l; i<=r; i++)
    {
        if(arr[i]<=ele)
            swap(arr[j++],arr[i]);
    }
    printarray(arr);
    return j-1;
}


void quicksort(vector<int> &arr, int l, int r)
{
    if(l<r)
    {
        int pivot = arr[r];
        int pi = partition(arr,l,r,pivot);
        quicksort(arr,l,pivot-1);
        quicksort(arr,pivot+1,r);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    quicksort(arr,0,n-1);
    
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}