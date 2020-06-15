#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
int n;int m; int sol[10]; int c;
void afisare(int n,int m,int c){
    for(int i = 0;i<n;i++) printf("%d",sol[i]);
    int64_t aux = 0;
    for(int i = 0;i<n;i++){
        aux*=10;
        aux+=sol[i];
    }
    aux = aux*c;
    printf(" %d",aux);
    printf("\n");
}
int solutie(int n,int k,int c){
    if(n == k){
        int sol2[10]; int64_t aux = 0;
        for(int i = 0;i<n;i++){
        aux*=10;
        aux+=sol[i];
            }
          //  printf("%d ",aux);
        aux = aux*c;
        //printf("%d\n",aux);
        if(aux>=1000000000) return 0;
        for(int i = 0;i<n-1;i++){
            sol2[i] = aux%10;
            aux = aux/10;
        }
        for(int i = 0;i<n;i++) printf("%d ",sol2[i]);
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                if(sol2[i]==sol2[j]) return 0;
            }
        }
        return 1;
    }
    return 0;
}
int valid(int x,int k){
    for(int i = 0;i<k;i++) if(sol[i]==x) return 0;
    return 1;
}
void back(int n,int m,int k,int c){
    if(solutie(n,k,c)) afisare(n,m,c);
    else{
        for(int i = 0;i<m;i++){
            if(valid(i+1,k)){
                sol[k] = i+1;
                back(n,m,k+1,c);
            }
        }
    }
}
int main()
{
    c = 2;
    back(9,9,0,c);
}
