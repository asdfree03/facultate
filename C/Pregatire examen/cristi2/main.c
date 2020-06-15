#include <stdio.h>
#include <stdlib.h>
void afisare(int n){
int i;
for(i = 31;i>=0;i--) printf("%d",n>>i&1);
printf("\n");
}
void modificare(int n){
    int i;
    for(i = 30;i>=1;i--) if(n>>i &1 && !((n>>i-1)&1) && !((n>>i+1)&1)) {
        n =n| (n>>1) | (n<<1);
    }
    printf("%d\n",n);
    afisare(n);
}
int main()
{
    unsigned int n;
    while(1){
        scanf("%u",&n);
        if(n == 0) break;
        afisare(n);
        modificare(n);
    }
}
