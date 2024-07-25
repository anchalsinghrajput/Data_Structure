#include<bits/stdc++.h>
using namespace std;

void printMazePathWithJumps(int n, int m, int i, int j, string ans){
  if(i > n || j > m) return;

  if(i == n && j == m){
    cout<<ans<<endl;
    return;
  }

  // horizontal line
  for(int h = 1; h <= m - i; h++){
    printMazePathWithJumps(n,m, i, j+h, ans + "h" + to_string(h));
  }

  // vertical line
  for(int v = 1; v <= n - j; v++){
    printMazePathWithJumps(n,m, i+v, j, ans + "v" + to_string(v));
  }

  //diagonal 
  for(int d = 1; d <= n-i && d <=m-j; d++){
    printMazePathWithJumps(n,m, i+d, j+d, ans + "d" + to_string(d));
  }
}

int main(){
    int n, m;
    cout<<"Enter n, m : ";
    cin>>n>>m;

    printMazePathWithJumps(n, m, 0, 0, "");

    return 0;
}