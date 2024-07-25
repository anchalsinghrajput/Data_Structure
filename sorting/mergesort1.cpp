#include<bits/stdc++.h>
using namespace std;
// 0 1 2 3 4 5
// 1 2 3 4 5 6
// mid = 2


void merge(vector<int> &arr, int l, int mid, int r)
{
    int las = mid-l+1;
    int ras = r-mid;

    vector<int> leftarr(las,0);
    vector<int> rightarr(ras,0);

    
    cout<<"left array : ";
    for(int i = 0; i<las; i++)
    {
        leftarr[i] = arr[l+i];
        cout<<leftarr[i]<<" ";
    }
    cout<<endl;

    cout<<"right array : ";
    for(int i = 0; i<ras; i++)
    {
        rightarr[i] = arr[mid+i+1];
        cout<<rightarr[i]<<" ";
    }
    cout<<endl;

    int i = 0;
    int j = 0;
    int k = l;

    while(i<las && j<ras)
    {
        if(leftarr[i]<rightarr[j])
            arr[k++] = leftarr[i++];
        else
            arr[k++] = rightarr[j++];
    }

    while(i < las)
        arr[k++] = leftarr[i++];
    
    while(j < ras)
        arr[k++] = rightarr[j++];

    cout<<"merged array : ";
    for(int i = l; i<k; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void mergesort(vector<int> &arr, int left, int right)
{
    if(left<right)
    {
        int mid = left+ (right - left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
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

    mergesort(arr,0,n-1);
    
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}



