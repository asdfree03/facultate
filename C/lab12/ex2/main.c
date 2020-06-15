#include <stdio.h>
#include <stdlib.h>

int main()
{
 int n,m,x,**t,aux;
 scanf("%d %d",&n,&m);
 t = (int **)malloc(n*sizeof(int *));
 if(t==NULL) exit(1);
 for(int i = 0;i<n;i++){
    t[i] = (int *)malloc(m*sizeof(int *));
    if(t[i]==NULL) exit(1);
 }
 for(int i=0;i<n;i++)
    for(int j =0;j<m;j++) t[i][j] = rand() %10;
    for(int i=0;i<n;i++){
    for(int j =0;j<m;j++) printf("%d ",t[i][j]);printf("\n");}
    printf("\n");
    scanf("%d",&x);
    printf("\n");

 for(int i =0;i<n;i++){
    aux = t[i][x];
    for(int k = x;k<m-1;k++){
        t[i][k] = t[i][k+1];
    }
    t[i][m-1] = aux;
    }

 for(int i = 0;i<n;i++) t[i] = (int *)realloc(t[i],(m-1)*sizeof(int *));
 m--;
        for(int i=0;i<n;i++){
    for(int j =0;j<m;j++) printf("%d ",t[i][j]);printf("\n");}
    free(t);
}
