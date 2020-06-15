#include <stdio.h>
#include <stdlib.h>
int sol[50][50];
int move[8][2] = {{-2,-1},{-2,1},{2,1},{2,-1},{1,-2},{1,2},{-1,2},{-1,-2}};
void afisare(int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++) printf("%d ",sol[i][j]);
        printf("\n");
    }
    printf("\n");
}
int check(int nx,int ny,int n){
    if((nx>=0) && (nx<n) && (ny>=0) && (ny<n) && (sol[nx][ny]==0)) return 1;
    return 0;
}
int solutie(int px,int py,int fx,int fy,int m){
    if(m!=0) return 0;
    else if(px == fx && py == fy) return 1;
    return 0;
}
void s_cal(int n,int px,int py,int fx,int fy,int m){
    sol[px][py] = m+1;
    if(solutie(px,py,fx,fy,m)) afisare(n);
    else if(m>0){
        for(int g=0;g<8;g++){
            int nx = px+move[g][0];
            int ny = py+move[g][1];
            if(check(nx,ny,n)){
                    s_cal(n,nx,ny,fx,fy,m-1);
                    sol[nx][ny] = 0;
        }
    }
}
}
int main()
{
    s_cal(7,0,0,3,3,4);
}
