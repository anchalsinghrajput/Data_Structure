#include<iostream>
#include<vector>
using namespace std;

//given an array containing only two elements zeros and ones , segregate 1's and 0's

void swap(vector<int> &arr, int i, int j){
    cout<<"Swapping index " << i << " and index " << j << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void sort01(vector<int>& arr) {
    for(int i = 0, j = 0; i<arr.size(); i++)
    {
        if(arr[i] == 0)
        {
            swap(arr,i,j);
            j++;
        }
    }
    
}


void Display(vector<int>& arr){
    for(int ele : arr){
        cout<< ele << endl;
    }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort01(arr);
  Display(arr);
  return 0;
}