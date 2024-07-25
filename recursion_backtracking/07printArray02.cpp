#include<bits/stdc++.h>
using namespace std;

void printArray(int *arr, int i) {
  cout<<" size: " << sizeof(arr) / sizeof(int)<<endl;
  if(i > sizeof(arr) / sizeof(int)) {
    return;
  }
  cout<<arr[i]<<endl;
  printArray(arr, i+1);
}

int main(){
  int n;
  cout<<"Enter the size of array: "<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter the elements of array: "<<endl;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cout<<"array printed with recursion: "<<endl;
  printArray(a, 0);
  // cout<<"array size: "<<sizeof(a) / sizeof(int)<<endl;
  return 0;
}
