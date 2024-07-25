#include<iostream>
using namespace std;

void printArray(int arr[], int n){
  if(n < 0) return;
  cout<<arr[n]<<endl;
  printArray(arr, n-1);
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
  printArray(a, n-1);
  return 0;
}