#include <stdio.h>
#include <stdlib.h>

int main()
{
unsigned int a,b; b =16;
scanf("%d",&a);
for(int i = 31; i>=0;i--) printf("%d",a>>i&1); printf("\n");
for(int i = 31; i>=0;i--) printf("%d",16>>i&1);printf("\n");
for(int i = 31; i>=0;i--) printf("%d",(a<<4)>>i&1);printf("\n");
}
