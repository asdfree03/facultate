#include <stdio.h>
#include <stdlib.h>

int main()
{
unsigned int mask;
unsigned int n;
scanf("%d",&n);
for(int i = 31; i>=0;i--) printf("%d",n>>i&1);
printf("\n");
if((1<<15) & n){
mask = 1 << 16;
n = (n | mask);
mask = 1 << 17;
n = (n | mask);
mask = 1 << 18;
n = (n | mask);
for(int i = 31; i>=0;i--) printf("%d",n>>i&1);
}
else{
mask = 1 << 14;
n = (n & ~mask);
mask = 1 << 13;
n = (n & ~mask);
mask = 1 << 12;
n = (n & ~mask);
for(int i = 31; i>=0;i--) printf("%d",n>>i&1);
}
}
