#include<iostream>
#include<string>
using namespace std;

void printPermutation(string str, string ans){
  if(str.length() == 0){
    cout<<ans<<endl;
    return;
  }

  for(int i = 0; i<str.size(); i++){
    char ch = str[i];
    string cstr = str.substr(0, i) + str.substr(i+1, str.length());
    printPermutation(cstr, ans + ch);
  }
}

int main(){
  string str;
  cout<<"Enter a string : ";
  cin>>str;

  printPermutation(str, "");

  return 0;
}