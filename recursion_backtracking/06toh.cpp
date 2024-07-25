#include<iostream>
using namespace std;


void toh(int n, char a, char b, char c) {
  if(n == 1){
    cout<<"Move disk "<<n<<" from "<<a<<" to " <<b<<endl;
    return;
  }
  else{
    toh(n-1, 'A', 'C', 'B');
    cout<<"Move disk "<<n<<" from "<<a<<" to " <<b<<endl;
    toh(n-1,'C', 'B', 'A');
  }
}


int main(){
  int n;
  cout<<"Enter number of disk : ";
  cin>>n;
  toh(n, 'A', 'B', 'C');
  return 0;
}