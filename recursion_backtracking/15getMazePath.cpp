#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

vector<string> getMazePath(int n, int m, int i, int j){
    if(i > n || j > m){
        return vector<string> ();
    }

    if( i == n && j == m){
        vector<string> result;
        result.push_back("");
        return result;
    }

    vector<string> verticalPath =  getMazePath(n, m, i+1, j);
    vector<string> horizontalPath = getMazePath(n, m, i, j+1);

    vector<string> result;

    for(auto str: verticalPath){
        result.push_back("v" + str);
    }

     for(auto str: horizontalPath){
        result.push_back("h" + str);
    }
    cnt++;
    return result;
}

int main(){
    int n, m;
    cout<<"Enter n, m : ";
    cin>>n>>m;

    vector<string> ans = getMazePath(n, m, 0, 0);

    cout<<"All paths are : "<<endl;
    for(auto num : ans){
        cout<<num<<endl;
    }

    cout<<"No of operation : "<<cnt<<endl;
    return 0;
}