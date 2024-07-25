#include<iostream>
using namespace std;

void printArray(int arr[], int n){
  if(n < 0) return;
  printArray(arr, n-1);
  cout<<arr[n]<<endl;
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