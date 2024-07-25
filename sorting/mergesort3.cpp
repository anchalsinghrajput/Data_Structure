#include<bits/stdc++.h>
using namespace std;

vector<int> mergeTwoSortedArray(vector<int> &A, vector<int> &B)
{
    vector<int> ans;
    int i = 0, j = 0;
    
    while(i<A.size() && j<B.size())
    {
        if(A[i]<B[j])
            ans.push_back(A[i++]);
        else
            ans.push_back(B[j++]);
    }
    while(i<A.size())
        ans.push_back(A[i++]);
    while(j<B.size())
        ans.push_back(B[j++]);

    return ans;
}

vector<int> mergesort(vector<int> &arr, int left, int right)
{
    if(left == right)
    {
        vector<int> arr1;
        arr1.push_back(arr[left]);
        return arr1;
    }
    int mid = left + (right - left)/2;
    vector<int> lsa = mergesort(arr,left,mid);
    vector<int> rsa = mergesort(arr,mid+1,right);
    vector<int> mergedarr = mergeTwoSortedArray(lsa,rsa);
    return mergedarr;
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

    arr = mergesort(arr,0,n-1);
    
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}



