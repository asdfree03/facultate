#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1 = fopen("prg.txt","r+");
    int n,m, t[100][100];
    int suml,prodc;
    fscanf(f1,"%d %d \n",&n, &m);
    for(int i = 0;i<n;i++){
            suml=0;
        for(int j = 0;j<m;j++){
            fscanf(f1,"%d",&t[i][j]);
            suml += t[i][j];
            printf("%d ",t[i][j]);
        }
        t[i][m] = suml;
        fscanf(f1,"\n");
        printf("\n");
    }
    printf("\n");

int col;
    for(int rand = 0;rand<m;rand++){
            prodc=1;
        for(col = 0;col<n;col++){
                prodc= prodc*t[col][rand];
        }
        t[n][rand] = prodc;
    }
printf("\n");
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++)printf("%d ",t[i][j]);
        printf("\n");
    }
}
