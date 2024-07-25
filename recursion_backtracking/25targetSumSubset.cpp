#include<iostream>
#include<vector>
#include<string>
using namespace std;
void tss(vector<int>arr, int target,int idx,int sos, vector<int> subset)
{
    if(sos == target)
    {
        for(int i = 0; i<subset.size(); i++)
            cout<<subset[i]<<" ";
        cout<<endl;
        return;
    }
    if(sos>target  || idx == arr.size()) return;
    
    tss(arr,target,idx+1,sos,subset);
    subset.push_back(arr[idx]);
    tss(arr,target,idx+1,arr[idx]+sos,subset);
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    int target;
    cin>>target;
    vector<int> subset;
    tss(arr,target,0,0,subset);
}