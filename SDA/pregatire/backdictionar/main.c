#include <stdio.h>
#include <stdlib.h>
char a[3][3] = {{'G', 'I', 'Z'},
             {'U', 'E', 'K'},
             {'Q', 'S', 'E'}};
char d[4][10] = {"GEEKS", "FOR", "QUIZ", "GO"}; int m;
int move[8][2]={{0,1}, {0,-1}, {1,0}, {-1,0}, {-1,-1}, {1,1}, {-1,1}, {1,-1}};
void afisare(char s[]){
    printf("%s\n",s);
}
int valid(char c,int px,int py){
    if(c == a[px][py]) return 1;
    else return 0;
}
int solution(int n,int k){
    if(n==k) return 1;
    else return 0;
}
int check(int x,int y,int n){
    if(x>=0 && x<n && y>=0 && y<n) return 1;
    return 0;
}
void este(char s[],int n,int k,int px,int py){
    if(solution(n,k)) afisare(s);
    else{
        for(int i = 0;i<8;i++){
            int nx = px+move[i][0];
           int ny = py+move[i][1];
           if(check(nx,ny,m)){
                if(valid(s[k],px,py)){if(valid(s[k+1],nx,ny)) este(s,n,k+1,nx,ny);}
                else este(s,n,k,nx,ny);
            }
        }
}
}
int main()
{
    m = 3;
   este(d[0],5,0,0,0);
}
