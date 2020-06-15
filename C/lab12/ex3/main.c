#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **c;
    c = (char **)malloc(5*sizeof(char *));
    for(int i = 0;i<5;i++){
        c[i] = (char *)malloc(10*sizeof(char));
    }
    for(int i = 0;i<5;i++)
        for(int j =0;j<10;j++)
    gets(c[i][j]);
    for(int i = 0;i<5;i++)
    puts(c[i][j]);
    free(c);
    /*
    int *v,n,m;
    int gata = 0;
    n=0; int i =0;
    v = (int *)malloc(n*sizeof(int));
    while(!gata){
        scanf("%d",&m);
        if(m==0) break;
        n++;
        v = (int *)realloc(v,n*sizeof(int));
        v[i] = m;
        i++;
    }
    printf("\n");
    for(int i = n-1;i>=0;i--) printf("%d ",v[i]);
    free(v);*/
}
