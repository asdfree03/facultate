#include <stdio.h>
#include <stdlib.h>
int sol[50][50];
void afisare(int n){
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++) printf("%d ",sol[i][j]);
        printf("\n");
    }
    printf("\n");
}
int solutie(int n,int k){
    if(n == k) return 1;
    return 0;
}
int valid(int k,int x,int n){
    for(int i =0;i<n;i++) if(sol[k][i]==1 && i!=x) return 0;
    for(int i =0;i<n;i++) if(sol[i][x]==1 && i!=k) return 0;
    for(int i =k+1,j = x+1;i<n,j<n;i++, j++){
        if(sol[i][j]==1) return 0;
    }
    for(int i =k+1,j = x-1;i<n,j>=0;i++, j--){
        if(sol[i][j]==1) return 0;
    }
    return 1;
}
void regine(int n,int k){
    if(solutie(n,k)) afisare(n);
    else{
        for(int i =0;i<n;i++){
            if(valid(k,i,n)){
                sol[k][i] = 1;
                regine(n,k+1);
                sol[k][i]=0;
            }
        }
    }
}
int main()
{
    regine(4,0);
}
