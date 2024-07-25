#include<iostream>
using namespace std;

int firstOccurance(int arr[], int n, int target){
  if(n < 0){
    return -1;
  }
  int idx = firstOccurance(arr, n-1, target);
  if(idx != -1) return idx;
  else if(arr[n] == target) return n;
  else return -1;
}

int main(){
  int n;
  cout<<"Enter the size of array: "<<endl;
  cin>>n;
  int arr[n];
  cout<<"Enter the elements of array: "<<endl;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  cout<<"Enter the element to be searched: "<<endl;
  int x;
  cin>>x;

  cout<<"first occurance index : "<<firstOccurance(arr, n-1, x);
  return 0;
}