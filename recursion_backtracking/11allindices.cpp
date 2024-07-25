#include<bits/stdc++.h>
using namespace std;

void FindAllOccurances(int arr[], int n, int target, vector<int>& ans){
  if(n < 0){
    return;
  }
  FindAllOccurances(arr, n-1, target, ans);
  if(arr[n] == target) ans.push_back(n);
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

  vector<int> ans;
  FindAllOccurances(arr, n-1, x, ans);

  cout<<"All indexes are : ";

  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }

  return 0;
}