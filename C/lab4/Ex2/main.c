#include <stdio.h>
#include <stdlib.h>

int main()
{
int a[10][10];
int n,m;
n=m=3;
for(int i = 0;i<n;i++)
    for(int j = 0; j<m;j++) scanf("%d",&a[i][j]);
for(int i = 0;i<n;i++){
    for(int j = 0; j<m;j++) printf("%d ",a[i][j]);
    printf("\n");
}
printf("\n");
for(int i = 0;i<n;i++){
    for(int j = 0; j<m;j++){
    if(i==n-(j+1)) printf("  ");
    else printf("%d ",a[i][j]);
    }
    printf("\n");
}
}
