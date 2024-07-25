#include<bits/stdc++.h>
using namespace std;

vector<string> getKeyboardCode(string code, vector<string>&codes){
  if(code.size() == 0){
    vector<string> ans;
    ans.push_back("");
    return ans;
  }

  char ch = code[0];
  string str = code.substr(1, code.size() - 1);
  vector<string> ans = getKeyboardCode(str, codes);
  vector<string> result;

  int idx = (int)ch - 48;
  string cstr = codes[idx];
  for(int i = 0; i < cstr.size(); i++) {
    for(int j = 0; j < ans.size(); j++) {
      result.push_back(cstr[i] + ans[j]);
    }
  }
  return result;
}

int main(){
  vector<string> codes = {",;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
  string code;
  cout<<"Enter a number of codes : ";
  cin>>code;

  vector<string> result = getKeyboardCode(code, codes);
  for(int i=0; i<result.size(); i++){
    cout<<result[i]<<endl;
  }
  return 0;
}