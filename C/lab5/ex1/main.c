#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t[10][10];
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%d",&t[i][j]);
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++) printf("%d ",t[i][j]); printf("\n");}
    for(int i=0;i<n;i++)
        for(int j = 0;j<n;j++){
        if(j==n-1 && i>0 && i<n-1) printf("%d ",t[i][j]);
    }
}
