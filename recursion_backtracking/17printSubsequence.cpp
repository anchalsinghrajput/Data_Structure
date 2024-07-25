#include<iostream>
#include<string>

void printSubsequence(std::string str, std::string ans){
  if(str.size() == 0){
    std::cout<<ans<<std::endl;
    return;
  }
  std::string rstr = str.substr(1, str.length());
  char ch = str[0];
  printSubsequence(rstr, ans+ch);
  printSubsequence(rstr, ans);
}

int main(){
  std::string str;
  std::cout<<"Enter the string : ";
  std::cin>>str;

  printSubsequence(str, "");
  return 0;
}
