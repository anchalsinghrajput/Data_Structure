// We are given an array of size N ; we are told to pick up any 2 numbers from the array such that their digit sum is equal ; if their digit sum is equal ; calculate their sum ; question is saying to find the maximum possible sum 

#include<bits/stdc++.h>
using namespace std;
int maxiSum(int  n, vector<int>& arr)
{
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i<n; i++)
    {
        int digitCount  = 0;
        int digit = arr[i];
        while(digit > 0)
        {
            digitCount += digit % 10;
            digit /= 10;
        }
        mp[digitCount].push_back(arr[i]);
    }

    int maxi = -1;
    for(auto x : mp)
    {
        // cout<<"size: "<<x.second.size()<<endl;
        if(x.second.size() <= 1) continue;
        int ans = 0;
        sort(x.second.begin(), x.second.end());
        int size = x.second.size() - 1;
        ans = x.second[size] + x.second[size-1];
        if(maxi < ans) maxi = ans;
    }

    return maxi;
}

// int maxiSum (int n , vector<int> & arr)
// {
//     unordered_map<int,int> mp;
//     int maxi = -1;

//     for(int i = 0; i<n; i++)
//     {
//         int curdigit = arr[i];
//         int digitsum = 0;
//         while(curdigit>0)
//         {
//             digitsum += curdigit % 10;
//             curdigit /= 10;
//         }
//         if(mp.find(digitsum) != mp.end())
//         {
//             int ans = mp[digitsum] + arr[i];
//             if(ans > maxi) maxi = ans;
//             if(arr[i] > mp[digitsum]) mp[digitsum] = arr[i];
//         }
//         else
//         {
//             mp[digitsum] = arr[i];
//         }
//     }
//     return maxi;
// }
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<maxiSum(n, arr);
}