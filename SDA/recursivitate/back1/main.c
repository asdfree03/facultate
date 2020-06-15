#include <stdio.h>
#include <stdlib.h>
int x[10], n, nrsol=0; int j;
void afisare(){
  for(int i=1;i<=n;i++) {
        if(i!=1 || x[1]!=0) printf("%d",x[i]);
  }
  printf("\n");
  nrsol++;
}
int Valid(int k){
    for(int i=1;i<=k-1;i++)
        if (x[k]==x[i]) return 0;
    return 1;
}

void BackRec1(int k){
    for(int i=0;i<=9;i++){
        x[k]=i;
        if (Valid(k)){
            if (k==n) afisare();
            else BackRec1(k+1);
        }
     }
}
int main(){

  scanf("%d",&n);
  BackRec1(1);
  printf("Nr solutii = %d",nrsol);
  return 0;
}
