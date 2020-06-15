#include <stdio.h>
#include <stdlib.h>
void afisare(unsigned int n){
for(int i = 31;i>=0;i--) printf("%d",n>>i&1);
printf("\n");

}
int main()
{
    unsigned int a,b,c;
    scanf("%u %u",&a,&b);
    afisare(a);afisare(b);
    if(a>b){
        c = a;
        c = (c<<4) | b;
    }
    else{
        c = b;
        c = (c<<4) | a;
    }
    afisare(c);

}
