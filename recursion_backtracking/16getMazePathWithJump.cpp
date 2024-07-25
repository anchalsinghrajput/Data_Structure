#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

vector<string> getMazePathWithJumps(int n, int m, int i, int j){

    if( i == n && j == m){
        vector<string> result;
        result.push_back("");
        return result;
    }

    vector<string> result;
    //horizontal line
    for(int h = 1; h <= m - j; h++){
       vector<string> horizontalPath = getMazePathWithJumps(n, m, i, j+h);
       for(auto str: horizontalPath){
           result.push_back("h" + to_string(h) + str);
       }
    }

    //vertical line
    for(int v = 1; v <= n - i; v++){
       vector<string> verticalPath = getMazePathWithJumps(n, m, i+v, j);
       for(auto str: verticalPath){
           result.push_back("v" + to_string(v) + str);
       }
    }

    //diagonal line
    for(int d = 1; d <= n - i && d <= m - j; d++){
       vector<string> diagonalPath = getMazePathWithJumps(n, m, i+d, j+d);
       for(auto str: diagonalPath){
           result.push_back("d" + to_string(d) + str);
       }
    }

    cnt++;
    return result;
}

int main(){
    int n, m;
    cout<<"Enter n, m : ";
    cin>>n>>m;

    vector<string> ans = getMazePathWithJumps(n, m, 0, 0);

    cout<<"All paths are : "<<endl;
    for(auto num : ans){
        cout<<num<<endl;
    }

    cout<<"No of operation : "<<cnt<<endl;
    return 0;
}