#include <stdio.h>
#include <stdlib.h>
int x[10],n,a,b,j;
void afisare(){
    int auxa = a;
  for(int i=1;i<=n;i++){
        if(x[i]==0) auxa-= b;
        else auxa+=b;
    printf("%d",auxa);
  }
  printf("\n");
}
int valid(int k){
    int nr1 = 0; int nr0=0;
    for(int i=1;i<=k;i++) if(x[i]==1) nr1++; else nr0++;
    if(nr1==nr0) return 1;
    else return 0;
}

void BackRec1(int k){
    for(int i=0;i<=1;i++){
        x[k]=i;
            if (k==n){if(valid(k)) afisare();}
            else BackRec1(k+1);
     }
}
int main(){
    printf("a = "); scanf("%d",&a);
    printf("b = "); scanf("%d",&b);
    printf("n = "); scanf("%d",&n);
    BackRec1(1);
}
