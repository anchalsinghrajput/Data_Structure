#include<iostream>
using namespace std;

int count = 0;

int xPowerN(int x, int n){
  if(n == 0) return 1;
  int pow = xPowerN(x, n/2);
  int ans = pow * pow;
  if(n%2 == 1){
    ans = ans * x;
  }
  count++;
  return ans;
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