#include<bits/stdc++.h>
using namespace std;
const int N= 9;

bool isSafe(int grid[N][N] ,  int row,int col,int num)
{
    for(int i=0;i<N;i++)
    {
        if(grid[row][i] == num)
            return false;
    }
    for(int i=0;i<9;i++)
    {
        if(grid[i][col] == num)
            return false;
    }

    int startRow = row - row % 3,  
            startCol = col - col % 3; 
    
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            if (grid[i + startRow][j +startCol] == num) 
                return false; 

    return true; 
    
}
bool solvesudoko(int grid[N][N],int row,int col)
{
    if(row == N-1 && col == N)
    {
        return true;
    }

    if(col == N){
        row++;
        col=0;
    }

    if(grid[row][col] > 0){
        return solvesudoko(grid,row,col+1);
    }

    for(int i=1;i<=N;i++){
        if(isSafe(grid,row,col,i))
        {
            grid[row][col]=i;

            if(solvesudoko(grid,row,col+1))
                return true;
            grid[row][col]=0;
        }
    }
    return false;
}
int main()
{
    int grid[N][N]= { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; 
    if(solvesudoko(grid,0,0))
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
    else
        cout<<"No Solution";
    return 0;
}