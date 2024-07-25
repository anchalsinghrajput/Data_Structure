#include<bits/stdc++.h>
using namespace std;

// 1 8 3 2 4 

void partition(vector<int> &arr, int ele)
{
    int idx = -1;
    for(int i = 0; i<arr.size(); i++)
    {
        if(arr[i]<=ele)
            swap(arr[++idx],arr[i]);
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n,0);
    for(int i  = 0 ; i<n; i++)
        cin>>arr[i];
    
    int ele;
    cin>>ele;
    partition(arr,ele);

    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
}