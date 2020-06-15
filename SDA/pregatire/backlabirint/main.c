#include <stdio.h>
#include <stdlib.h>
int sol[8][8] = {
                  {0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 2, 2, 2, 2, 2, 0},
                  {0, 0, 2, 2, 2, 2, 2, 0},
                  {0, 0, 0, 0, 2, 2, 2, 0},
                  {0, 0, 2, 0, 2, 2, 2, 0},
                  {0, 0, 2, 0, 0, 0, 2, 0},
                  {0, 0, 2, 2, 2, 0, 2, 0},
                  {2, 2, 2, 2, 2, 0, 0, 0}
};
int move[8][2] = { {0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };
int counter;
void afisare(int n){
    for(int i = 0 ;i<n;i++){
        for(int j = 0;j<n;j++) printf("%d ",sol[i][j]);
        printf("\n");
    }
    counter++;
    printf("\n\n");
}
int solutie(int px,int py,int fx,int fy){
    if(px == fx && py == fy) return 1;
    else return 0;
}
int check(int nx,int ny,int n){
    if(nx>=0 && nx<n && ny>=0 && ny<n && sol[nx][ny]==0) return 1;
    return 0;
}
void back(int n,int px,int py,int fx,int fy){
    sol[px][py] = 1;
    if(solutie(px,py,fx,fy)) afisare(n);
    else{
        for(int i = 0;i<4;i++){
                int nx = px + move[i][0];
                int ny = py + move[i][1];
                if(check(nx,ny,n)){
                        back(n,nx,ny,fx,fy);
                        sol[nx][ny] = 0;
                }
        }
    }
}
int main()
{
    counter= 0;
    back(8,0,0,7,7);
    printf("%d",counter);
}
