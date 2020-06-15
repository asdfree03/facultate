#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char **c;
    c = (char **)malloc(10*sizeof(char *));
    char aux[10]; int n =0;
    while(1){
    gets(aux);
    if(strcmp(aux,"STOP")==0) break;
    c[n] = (char *)malloc((strlen(aux)+1)*sizeof(char));
    strcpy(c[n],aux);
    n++;
    }
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(strlen(c[j])>=strlen(c[j+1])){
                strcpy(aux,c[j]);
                strcpy(c[j],c[j+1]);
                strcpy(c[j+1],aux);
            }
        }
        }
                for(int i = 0;i<n-1;i++){
            for(int j = 0;j<n-i-1;j++){
            if(strlen(c[j]) == strlen(c[j+1]) && strcmp(c[j],c[j+1])>0){
                strcpy(aux,c[j]);
                strcpy(c[j],c[j+1]);
                strcpy(c[j+1],aux);
            }
            }
        }
    printf("\n");
    for(int i =0;i<n;i++) puts(c[i]);
    for(int i =0;i<n;i++) free(c[i]);
    free(c);
}
