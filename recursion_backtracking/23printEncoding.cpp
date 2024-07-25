#include<bits/stdc++.h>
using namespace std;

void printEncoding(string str, string ans){
  if(str[0] == '0') return;

  if(str.length() == 0) {
    cout<<ans<<endl;
    return;
  }
  
  char firstNum = str[0];
  char alphabet = 96 + stoi(&firstNum);

  string rstr = str.substr(1, str.length());
  printEncoding(rstr, ans+alphabet);

  if(str.size() >= 2){
    string firstTwo = str.substr(0, 2);
    if(stoi(firstTwo) <= 26){
      string remaining = str.substr(2, str.length());
      char getChar = 96 + stoi(firstTwo);
      printEncoding(remaining , ans + getChar);
    }
  }
}

int main(){
  string str;
  cout<<"Enter the number : ";
  cin>>str;
  printEncoding(str, "");
  return 0;
}


