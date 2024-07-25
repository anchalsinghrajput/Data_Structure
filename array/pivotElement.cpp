#include<bits/stdc++.h>

using namespace std;

void printarr(vector<int> arr)
{
    for(int i = 0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    countsort(n,arr);

    printarr(arr);
}