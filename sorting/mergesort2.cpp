#include<bits/stdc++.h>
using namespace std;
// 0 1 2 3 4 5
// 1 2 3 4 5 6
// mid = 2
vector<int> temp(10);

void merge(vector<int> &arr, int l, int mid, int r)
{
    
    int i = l;
    int j = mid+1;
    int k = l;

    while(i<=mid && j<=r)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    
    while(i <= mid)
        temp[k++] = arr[i++];
    
    while(j <= r)
        temp[k++] = arr[j++];

    for(int i = l; i<k; i++)
    {
        arr[i] = temp[i];
    }
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



