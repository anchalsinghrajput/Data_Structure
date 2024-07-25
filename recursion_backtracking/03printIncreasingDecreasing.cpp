#include<iostream>
using namespace std;

void printIncreasingDecreasing(int n){
  if(n==0){
    return;
  }
  cout<<n<<endl;
  printIncreasingDecreasing(n-1);
  cout<<n<<endl;
}

int main(){
  int n;
  cin>>n;
  printIncreasingDecreasing(n);
  return 0;
}