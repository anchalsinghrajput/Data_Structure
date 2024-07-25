#include<iostream>
#include<vector>
using namespace std;
int partition(int arr,)

int select(vector<int> arr, int idx)
{

}

int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i<n; i++)
        cin>>arr[i];
    
    //find the 4th (idx) smallest number
    int idx;
    cin>>idx;

    int ans = select(arr,idx);
    cout<<ans;
}