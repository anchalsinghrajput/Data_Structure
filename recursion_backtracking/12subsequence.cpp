#include<bits/stdc++.h>
using namespace std;

vector<string> FindAllSubsequences(string str){

  if(str.size() == 0){
    return {""};
  }
    vector<string> ans = FindAllSubsequences(str.substr(1, str.size()));
    vector<string> result;
    char ch = str[0];
    for(int i = 0; i < ans.size(); i++){
      result.push_back("_"+ans[i]);
      result.push_back(ch + ans[i]);
    }

  return result;
}

int main(){
  
  string str;
  cout<<"Enter a string : ";
  cin>>str;

  vector<string> ans = FindAllSubsequences(str);

  cout<<"All subsequences of "<<str<<" are : "<<endl; 
  for(int i  = 0; i < ans.size(); i++){
    cout<<ans[i]<<endl;
  }

  return 0;
}