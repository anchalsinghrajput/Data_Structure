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
void countsort(int n, vector<int> &arr)
{
    int max = INT_MIN, min = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        
        if(arr[i]<min)
            min = arr[i];
    }

    int idx = max - min +1;
    vector<int> freq(idx,0);
    vector<int> ans(arr.size(),0);

    // counting the frequency 
    for(int i = 0; i<10; i++)
    {
        freq[arr[i]-min]++;
    }
    printarr(freq);
    // prefix sum
    for(int i = 1; i<idx; i++)
    {
        freq[i] = freq[i-1] + freq[i];
    }
    printarr(freq);
    // filling the array in relative order 
    for(int i = arr.size()-1; i>= 0; i--)
    {
        int pos = freq[arr[i] - min] - 1;
        ans[pos] = arr[i];
        freq[arr[i] - min]--;
    }
    for(int i = 0; i<arr.size(); i++)
    {
        arr[i] = ans[i];
    }
    
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