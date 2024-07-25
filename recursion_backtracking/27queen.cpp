#include<bits/stdc++.h>
using namespace std;
bool isqueensafe(vector<vector<int>> chess, int row, int col)
{
    //check vertically
    for(int i =  row-1, j = col; i>=0; i--)
    {
        if(chess[i][j] == 1)
            return false;
    }
    //check diagonally left side
    for(int i = row-1, j = col-1; i>=0 && j>=0; i--,j--)
    {
        if(chess[i][j] == 1)
            return false;
    }

    // check diagonally right side

    for(int i = row-1, j = col+1; i>=0 && j<chess.size(); i--,j++)
    {
        if(chess[i][j] == 1)
            return false;
    }

    return true;
}
void printqueen(int n, vector<vector<int>> chess, string ans, int row)
{
    if(row == n)
    {
        cout<<ans<<"."<<endl;
        return;
    }
    for(int i = 0; i<n; i++)
    {
        if(isqueensafe(chess,row,i) == true)
        {
            chess[row][i] = 1;
            printqueen(n,chess,ans+to_string(row)+to_string(i)+", ",row + 1);
            chess[row][i] = 0;
        }   
    }
}


int main()
{
    int n;
    cin>>n;
    vector<vector<int>> chess (n,vector<int>(n,0));
    printqueen(n,chess,"",0);
}