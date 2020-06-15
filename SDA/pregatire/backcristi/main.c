#include <stdio.h>
#include <stdlib.h>
int sol[10];
int acceptabil(unsigned int k)
{
    int cate = 0;
    while(k){
        cate += k & 1;
        k>>=1;
    }
    if(cate%2==0) return 0;
    return 1;
}
int solutie(int k,int n){
if(k==n) return 1;
return 0;
}
void afisare(int n){
    for(int i = 0;i<n;i++)printf("%d ",sol[i]);
}
void back(int n,int k,int i){
    if(solutie(k,n)) afisare(k);
        if(acceptabil(k)){
                sol[i] = k;
                back(n,k+1,i+1);
    }
        else back(n,k+1,i);
}
int main()
{
    back(24,0,0);
}
