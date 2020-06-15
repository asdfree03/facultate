#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char cuv[100];
int gata = 0;
while(!gata){
    gets(cuv);
    if(strcmp(cuv,"STOP") == 0) {gata = 1; break;}
    if(strchr("aeiouAEIOU", cuv[0])) printf("Incepe cu vocala");
    else printf("Incepe cu consoana");
    printf("\n");
}
}
