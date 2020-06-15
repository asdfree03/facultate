#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int compare(const void* a, const void* b){
    return strcmp(*(const char**)a, *(const char**)b);
}
int main()
{
    char **c; char **v; int x[100];
    c = (char **)malloc(100*sizeof(char *));
    for(int i = 0;i<10;i++) c[i] = (char *)malloc(100*sizeof(char));
    int n = 0;
    while(1){
        fgets(c[n],100,stdin);
        if(strcmp(c[n],"\n")==0) break;
        n++;
    }
    char *token; int m = 0;
    v = (char **)malloc(100*sizeof(char *));
    int j = 0;
    for(int i = 0;i<n;i++){
        token = strtok(c[i]," ");
        while(token!=NULL){
                for(int o = 0;o<strlen(token);o++) if(strchr("0123456789",token[o])){x[m] = token[o] - '0'; m++;}
            if(!strchr("aeiouAEIOU",token[0])){
                v[j] = (char *)malloc(20*sizeof(char));
                v[j] = token;
                j++;
            }
            token = strtok(NULL," ");
        }
    }
    for(int i = 0;i<j;i++) {
        if(strlen(v[i])>5) for(int e = 0;e<5;e++) printf("%c",v[i][e]);
        else{ for(int e = 0;e <strlen(v[i]);e++) printf("%c",v[i][e]);
        for(int e = 0;e<5-strlen(v[i]);e++) printf("*");
        }
        printf("\n");
    }
    int media = 0;
    printf("\n\n\n\n\n");
    qsort(v, j, sizeof(const char*), compare);
    for(int i = 0;i<j;i++) puts(v[i]);
    for(int i = 0;i<m;i++) media+= x[i];
    printf("%d",media/m);
    for(int i = 0;i<10;i++) free(c[i]);
    for(int i = 0;i<j;i++) free(v[i]);
    free(c);
    free(v);
}
