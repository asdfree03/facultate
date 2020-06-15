#include <stdio.h>
#include <stdlib.h>
void afisare(unsigned int a){
for(int i = 31;i>=0;i--) printf("%d",a>>i&1);
printf("\n");
}
int main()
{
    unsigned int a,b,c;
    scanf("%d %d",&a,&b);
    c = a^b|~a|~b;
    afisare(a);
    afisare(b);
    afisare(c);
}
