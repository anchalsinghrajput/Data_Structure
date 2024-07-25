//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    // brute force
    // int maxDistance(int arr[], int n)
    // {
    //     int ans = 0;
    //     for(int i = 0; i<n; i++)
    //     {
    //         int curdis = 0;
    //         for(int j = n-1; j>=0; j--)
    //         {
    //             if(arr[i] == arr[j])
    //             {
    //                 curdis = j-i;
    //                 break;
    //             }
    //         }
    //         if(curdis>ans)
    //             ans = curdis;
    //     }
    //     return ans;
    // }
    
    // === using hashmap
    int maxDistance(int arr[], int n)
    {
        int maxi = 0;
        unordered_map<int, int> map;
        for(int i = 0; i<n; i++)
        {
            if(map.find(arr[i]) == map.end())
            {
                map[arr[i]] = i;
            }
            
            maxi = max(maxi, i-map[arr[i]]);
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends