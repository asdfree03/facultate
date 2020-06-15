#include <stdio.h>
#include <stdlib.h>
void afisare(unsigned int n){
for(int i = 31;i>=0;i--) printf("%d",n>>i&1);
printf("\n");
}
int main()
{
    unsigned int n; int gata = 0;
    while(!gata){
        scanf("%d",&n);
        afisare(n);
        if(n==0) break;
        if((n>>1) & 1 && (n>>3) &1 && (n>>5) &1) {
            n = n | 1<<2 | 1<<7 | 1<<8;
        }
        else n = n | 1<<1 | 1<<3 | 1<<5;
        afisare(n);
    }
}
