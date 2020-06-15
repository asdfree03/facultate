#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,t[10][10];
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)
            scanf("%d",&t[i][j]);
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)
            if(i!=n-2 && j!=m-2) printf("%d ",t[i][j]);
    printf("\n");
    }
}
