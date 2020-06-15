#include <stdio.h>
#include <stdlib.h>

int main()
{
unsigned int a,b,c,d,e;
scanf("%d",&a); scanf("%d",&b); scanf("%d",&c); scanf("%d",&d);
e = a<<24 | b << 16 | c<< 8 | d;
for(int i = 31; i>=0;i--) printf("%d",e>>i&1); printf("\n");
for(int i = 31; i>=0;i--) printf("%d",(e>>24)>>i&1); printf("\n");
for(int i = 31; i>=0;i--) printf("%d",((e<<8)>>24)>>i&1); printf("\n");
for(int i = 31; i>=0;i--) printf("%d",((e<<16)>>24)>>i&1); printf("\n");
for(int i = 31; i>=0;i--) printf("%d",((e<<24)>>24)>>i&1); printf("\n");
}
