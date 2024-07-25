#include<iostream>
using namespace std;

int printMaxArray(int arr[], int n){
  if(n < 0) return -1;
  int maxi = printMaxArray(arr, n-1);
  if(arr[n] > maxi) return arr[n];
  else return maxi;
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
  cout<<"Max element of array : "<<endl;
  cout<<printMaxArray(arr,n-1);
  return 0;
}