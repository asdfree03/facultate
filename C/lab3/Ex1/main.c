#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char c[500];
    gets(c);
    int k,maxx; char m[500],n[500]; k=0; maxx =0;
    for(int i = 0;i<strlen(c);i++) {
        if(c[i] != 32 && c[i+1]!='\0') {
            m[k++]=c[i];
        }
        else{
            m[k]='\0';
            if(strlen(m)>maxx) {
                strcpy(n,m);
                maxx=strlen(m);
            }
            k=0;
        }
    }
puts(n);
}
