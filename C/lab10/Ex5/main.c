#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char cuv[100];
int gata = 0;
while(!gata){
    gets(cuv);
    if(strcmp(cuv,"GATA") == 0) {gata = 1; break;}
    if(cuv[0]>='A' && cuv[0]<='Z') printf("Incepe cu majuscula");
    else printf("Nu incepe cu majuscula");
    printf("\n");
}
}
