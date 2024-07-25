#include<bits/stdc++.h>
using namespace std;

void printKeyboardCode(string code, vector<string>&codes, string ans){
    if(code.size() == 0){
      cout<<ans<<endl;
      return;
    }
    string rcode = code.substr(1, code.size());
    char ccode = code[0];
    int idx = (int) ccode - 48;
    string cstr = codes[idx];

    for(auto str : cstr){
      printKeyboardCode(rcode, codes, ans + str);
    }
}

int main(){
  vector<string> codes = {",;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
  string code;
  cout<<"Enter a number of codes : ";
  cin>>code;

  printKeyboardCode(code, codes, "");

  return 0;
}