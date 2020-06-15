#include <stdio.h>
#include <stdlib.h>

int main()
{
 char s[100];
 fgets(s,100,stdin);
int cuv=0;
 for(int i = 0;i<strlen(s);i++) if(s[i]==' ') cuv++;
 printf("\nSunt %d cuvinte", cuv+1);
}
