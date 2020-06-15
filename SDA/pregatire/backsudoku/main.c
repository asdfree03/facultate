#include <stdio.h>
#include <stdlib.h>
#define N 9
int grid[N][N] =     {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
void afisare(int n){
    for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++) printf("%d ",grid[i][j]);
    printf("\n");
    }
    printf("\n\n");
}
int UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return 1;
    return 0;
}
int solutie(int n){
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++) if(grid[i][j]==0) return 0;
    return 1;
}
int valid(int i,int j,int x,int n){
    for(int k = 0;k<n;k++) if(grid[i][k]==x) return 0;
     for(int k = 0;k<n;k++) if(grid[k][j]==x) return 0;
     if(UsedInBox(grid, i - i%3 , j - j%3, x)) return 0;
     return 1;
}
void rezolva(int n,int i,int j){
    if(solutie(n)) afisare(n);
    else{
        if(grid[i][j]==0){
                for(int k = 0;k<n;k++){
                    if(valid(i,j,k+1,n)){
                            grid[i][j] = k+1;
                            if(i==n-1) rezolva(n,0,j+1);
                            else rezolva(n,i+1,j);
                            grid[i][j]=0;
                }
            }
        }
        else{
            if(i==n-1) rezolva(n,0,j+1);
            else rezolva(n,i+1,j);
        }
    }
}
int main()
{
    rezolva(9,0,0);
}
