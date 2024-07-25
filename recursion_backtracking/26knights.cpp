#include<bits/stdc++.h>
using namespace std;
int num = 0;
void knight(int n,vector<vector<int>> board, int s, int e, int count)
{
    if(s<0 || e< 0 || s>=n || e>=n || board[s][e]>0)
        return;
    else if(count == (n*n))
    {
        num++;
        board[s][e] = count;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        board[s][e] = 0;
        return;
    }
    board[s][e] = count;
    knight(n,board,s-2,e+1,count+1);
    knight(n,board,s-1,e+2,count+1);
    knight(n,board,s+1,e+2,count+1);
    knight(n,board,s+2,e+1,count+1);
    knight(n,board,s+2,e-1,count+1);
    knight(n,board,s+1,e-2,count+1);
    knight(n,board,s-1,e-2,count+1);
    knight(n,board,s-2,e-1,count+1);
    board[s][e] = 0;
}
int main()
{
    int n,s,e;
    cin>>n>>s>>e;
    vector<vector<int>> board(n,vector<int>(n,0));
    knight(n,board,s,e,1);
    cout<<num;
}