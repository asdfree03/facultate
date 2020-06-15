#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t[10][10];
    int n,m;
    scanf("%d",&n);
    m=n;
    for(int i = 0;i<n;i++)
        for(int j=0;j<m;j++) t[i][j] = rand() % 10;

    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ",t[i][j]); printf("\n");}

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) if(i==j){ for(int e = j; e<n-1;e++) t[i][e]=t[i][e+1];}

    }
        m--;
        printf("\n");
     for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ",t[i][j]); printf("\n");}
}
