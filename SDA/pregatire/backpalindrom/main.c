#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10]; int iter;
int palindrom(char s[],int n,int k){
    iter++;
    if(n==k) return 1;
    if(s[k]!=s[n]) return 0;
    else {
            k++;
            palindrom(s,n-k,k);
    }
}
int main()
{
    strcpy(s,"anaana");
    int n = strlen(s);
    iter = 0;
    if(palindrom(s,n-1,0)) printf("Da");
    else printf("Nu");
}
