#include<iostream>
using namespace std;

void printMazePath(int n, int m, int i, int j, string ans){
  if(i > n || j > m) return;

  if(i == n && j == m){
    cout<<ans<<endl;
    return;
  }

  printMazePath(n, m, i + 1, j, ans + "V");
  printMazePath(n, m, i, j + 1, ans + "H");

}

int main(){
    int n, m;
    cout<<"Enter n, m : ";
    cin>>n>>m;

    printMazePath(n, m, 0, 0, "");

    return 0;
}