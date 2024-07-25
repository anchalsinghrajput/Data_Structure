#include<bits/stdc++.h>
using namespace std;

int counttt = 0;

vector<string> getStairPath(int n, vector<vector<string>> &memo){

    if(n < 0){
        return vector<string> ();
    }

    if(n == 0){
        vector<string> ans;
        ans.push_back("");
        return ans;
    }

    if(memo[n].size() != 0){
        return memo[n];
    }

    vector<string> pathForOne = getStairPath(n-1, memo);
    vector<string> pathForTwo = getStairPath(n-2, memo);
    vector<string> pathForThree = getStairPath(n-3, memo);

    if(n-1 >= 0) memo[n-1] = pathForOne;
    if(n-2 >= 0) memo[n-2] = pathForTwo;
    if(n-3 >= 0) memo[n-3] = pathForThree;

    vector<string> result;
    
    for(auto str : pathForOne){
        result.push_back("1"+str);
    }

    for(auto str : pathForTwo){
        result.push_back("2"+str);
    }

    for(auto str : pathForThree){
        result.push_back("3"+str);
    }

    counttt++;

    return result;
}

int main(){
    int n;
    cout<<"Enter the source: ";
    cin>>n;

    vector<vector<string>> memo(n + 1, vector<string>());

    vector<string> ans = getStairPath(n, memo);
    cout<<"All paths are : "<<endl;
    for(auto num : ans){
        cout<<num<<endl;
    }

    cout<<"No of operation : "<<counttt<<endl;
    return 0;
}