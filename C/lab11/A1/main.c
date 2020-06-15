#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned int a,b;
    char c;
    scanf("%d %d",&a,&b);
    c = (a<<5)|b;
    printf("%c\n",c);
    printf("%d\n",(c>>5) & 7);
    printf("%d\n",((c<<3)>>3) & 31);
}
