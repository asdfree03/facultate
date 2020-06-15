#include <stdio.h>
#include <stdlib.h>
int n;int m; int sol[10];
void afisare(int n,int m){
    for(int i = 0;i<n;i++) printf("f(%d) = %d\n",i+1,sol[i]);
    printf("\n");
}
int solutie(int n,int k){
    if(n == k) return 1;
    return 0;
}
int valid(int x,int k){
    for(int i = 0;i<k;i++) if(sol[i]==x) return 0;
    return 1;
}
void back(int n,int m,int k){
    if(solutie(n,k)) afisare(n,m);
    else{
        for(int i = 0;i<m;i++){
            if(valid(i+1,k)){
                sol[k] = i+1;
                back(n,m,k+1);
            }
        }
    }
}
int main()
{
    back(2,3,0);
}
