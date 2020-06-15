#include <stdio.h>
#include <stdlib.h>
int sol[50][50];
void afisare(int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++) printf("%d ",sol[i][j]);
        printf("\n");
    }
    printf("\n");
}
int solution(int n,int k){
    return (n==k);
}
int check_att(int a,int b,int x, int y){
    if( a == x || b == y) return 1;
    else if(abs(a-x)==abs(b-y)) return 1;
    return 0;
}
int check(int x,int y, int n){
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            if(sol[i][j]==1){
                if(check_att(i,j,x,y)) return 0;
            }
    return 1;
}
void queens(int n,int k){
    if(solution(n,k)) afisare(n);
    else{
        for(int i =0;i<n;i++){
            if(check(i,k,n)){
                    sol[i][k] = 1;
                    queens(n,k+1);
                    sol[i][k] = 0;
        }
    }
}
}
int main(){
    int n;
    printf("N = "); scanf("%d",&n);
    queens(n,0);
}
