#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **c;
    void replace(char *cuv1, char *cuv2,int n){
        for(int i = 0;i<n;i++){
                while(1){
        char *p = strstr(c[i],cuv1);
        if(p) strncpy(p,cuv2,strlen(cuv2));
        else break;}
        }
        for(int i = 0;i<n;i++) puts(c[i]);
    }
int main()
{
    int n = 0;
    c= (char **)malloc(20*sizeof(char *));
    char *fraza = (char *)malloc(100*sizeof(char));
    while(1){
        if(fgets(fraza,100,stdin)){
            c[n] = (char *)malloc((strlen(fraza)+1)*sizeof(char));
            strcpy(c[n],fraza);
            n++;
        }
        else break;
    }
    for(int i = 0;i<n;i++) puts(c[i]);
    char cuv1[10],cuv2[10];
    gets(cuv1); gets(cuv2);
    replace(cuv1,cuv2,n);
    free(c);
    free(fraza);
    }
