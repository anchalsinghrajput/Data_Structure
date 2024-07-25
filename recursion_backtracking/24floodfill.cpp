#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printPath(int r, int c, int i, int j, vector < vector < int >> maze, string ans, vector<vector<int>> visited)
{
    if(i == r-1 && j == c-1)
    {
        cout<<ans<<endl;
        return;
    }
    if(i<0 || i==r || j==c || j<0 || maze[i][j] == 1 || visited[i][j] ==  true)
        return;
    
    visited[i][j] = true;
    //top
    printPath(r,c,i-1,j,maze,ans+'t',visited);
    //left
    printPath(r,c,i,j-1,maze,ans+'l',visited);
    //down
    printPath(r,c,i+1,j,maze,ans+'d',visited);
    //right
    printPath(r,c,i,j+1,maze,ans+'r',visited);
    

    visited[i][j] = false;

}
void floodfill(vector < vector < int >> maze) {

    int r = maze.size();
    int c = maze[0].size();
    vector<vector<int>> visited(r,vector<int>(c,false));
    printPath(r,c,0,0,maze,"",visited);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    floodfill(arr);
}