#include<iostream>
using namespace std;

int count = 0;

int xPowerN(int x, int n){
  if(n == 0) return 1;
  count++;
  return x * xPowerN(x, n - 1);
}

int main(){
  int x, n;
  cout<<"Enter x :"<<endl;
  cin>>x;
  cout<<"Enter n :"<<endl;
  cin>>n;
  cout<<xPowerN(x, n)<<endl;
  cout<<" count  : "<<count<<endl;
  return 0;
}