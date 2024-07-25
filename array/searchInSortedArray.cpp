#include<bits/stdc++.h>
using namespace std;

int search(vector<int>&arr, int target)
{
    int low = 0;
    int high = arr.size()-1;
    
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[0] <= arr[mid]) 
        {
            if(target >= arr[0] && target > arr[mid]) 
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        else if(arr[mid] <= arr[high])
        {
            if(target > arr[mid] && target <= arr[high])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
    }
    
    return -1;
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
    
    int q;
    cin>>q;

    vector<int> ans;
    for(int i = 0; i<q; i++)
    {
        int target;
        cin>>target;
        int res = search(arr,target);
        ans.push_back(res);
    }
    
    for(int i = 0; i<ans.size(); i++)
        cout<<ans[i]<<endl;
}