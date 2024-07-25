#include<bits/stdc++.h>
using namespace std;

int findThePair(vector<int> & arr1,vector<int> & arr2){

    
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> arr1(n,0), arr2(m,0);

    for(int i = 0; i<n; i++){
        cin>>arr1[i];
    }

    for(int i = 0; i<m; i++){
        cin>>arr2[i];
    }

    cout<<findThePair(arr1,arr2);
}