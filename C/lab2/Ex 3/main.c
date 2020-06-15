#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
 long long n,k;
 scanf("%lld", &n);
 k=0; long long j;
    for(long long i=1;i<=n;i++){
        j=i;
            while(j!=0){
                k++;
                j=j/10;
            }
        }
    printf("%lld",k);
}
