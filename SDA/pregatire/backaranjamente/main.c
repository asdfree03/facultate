#include <stdio.h>
#include <stdlib.h>
int sol[10];
void afisare(int n){
    for(int i = 0;i<n;i++) printf("%d",sol[i]);
    printf("\n");
}
int valid(int x,int k){
    for(int i = 0;i<k;i++) if(sol[i]==x || sol[i]>x) return 0;
    return 1;
}
void back(int k,int n,int p){
    if(k==n)
            afisare(n);
    else{
        for(int i =0;i<p;i++){
            if(valid(i+1,k)){
                sol[k] = i+1;
                back(k+1,n,p);
            }
        }
 }
}
int main()
{
    for(int i = 1;i<4;i++)
    back(0,i,3);
}
