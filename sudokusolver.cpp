#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define N 9
bool UsedinRow (ll board[N][N], ll row, ll num)
{
    for (ll i=0;i<N;i++)
    {
        if (board[row][i]==num)
        {
            return true;
        }
        
    }
    return false;
}
bool UsedinCol (ll board[N][N], ll col, ll num)
{
    for (ll i = 0; i<N;i++)
    {
        if (board[i][col]==num)
        {
            return true;
        }
    }
    return false;
}
bool UsedinBox (ll board[N][N], ll boxrow, ll boxcol, ll num)
{
    for (ll i=0;i<3;i++)
    {
        for (ll j=0;j<3;j++)
        {
            if (board[i+boxrow][j+boxcol]==num)
            {
                return true;
            }
        }
    }
    return false;
}
bool isSafe (ll board[N][N], ll row, ll col, ll num)
{
    return !UsedinRow(board,row,num) && !UsedinCol(board,col,num) && !UsedinBox(board, row - row%3, col-col%3, num) && board[row][col]==0;
}
void printgrid(ll board[N][N])
{
    for (ll i=0;i<N;i++)
    {
        for(ll j=0;j<N;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
	
}
bool unassigned (ll board[N][N], ll &row, ll &col)
{
    for ( row=0;row<9;row++)
    {
        for ( col=0;col<9;col++)
        {
            if (board[row][col]==0)
            {
                return true;           
             }
        }
    }
    return false;
}
bool solvesudoku(ll board[N][N])
{
    ll row, col;
    if (!unassigned(board, row, col))
    {
        return true;
    }
    for(ll num = 1; num<=9;num++)
    {
        if (isSafe(board,row,col,num))
        {
            board[row][col]=num;
            if (solvesudoku(board))
            {
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
}

int main() {
    ll board[N][N];
    for (ll i=0;i<N;i++)
    {
        for (ll j=0;j<N;j++)
        {
            cin>>board[i][j];
        }
    }
    if (solvesudoku(board)== true)
    {
        printgrid(board);
    }
    else
    {
        cout<< "Sorry but no solution exists"<<endl;
    }

}