#include <stdio.h>
#include <stdlib.h>

int main()
{
 int i, j, n, m, *t; int count = 0;
 scanf("%d",&n);
 scanf("%d",&m);
 t = (int *)malloc(n*m*sizeof(int));
 for(i = 0;i<n;i++)
    for(j = 0;j<m;j++) scanf("%d",&t[i*n+j]);
 for(i = 0;i<n;i++){
    for(j = 0;j<m;j++) {
        if(i==0 && j==0 && t[i*n+j]%2==0 && t[i*n+j+1]%2!=0 && t[(i+1)*n+j]%2!=0) count++;
        else if(i==0 && j==m-1 && t[i*n+j]%2==0 && t[i*n+j-1]%2!=0 && t[(i+1)*n+j]%2!=0) count++;
        else if (i==n-1 && j ==0 && t[i*n+j]%2==0 && t[i*n+j+1]%2!=0 && t[(i-1)*n+j]%2!=0) count++;
        else if(i==n-1 && j==m-1 && t[i*n+j]%2==0 && t[i*n+j-1]%2!=0 && t[(i-1)*n+j]%2!=0) count++;
        else if(i==0 && t[i*n+j]%2==0 && t[i*n+j-1]%2!=0 && t[i*n+j+1]%2!=0 && t[(i+1)*n+j]%2!=0) count++;
        else if (i==n-1 && t[i*n+j]%2==0 && t[i*n+j-1]%2!=0 && t[i*n+j+1]%2!=0 && t[(i-1)*n+j]%2!=0) count++;
        else if (j==0 && t[i*n+j]%2==0 && t[i*n+j+1]%2!=0 && t[(i+1)*n+j]%2!=0 && t[(i-1)*n+j]%2!=0) count++;
        else if (j==m-1 && t[i*n+j]%2==0 && t[i*n+j-1]%2!=0 && t[(i+1)*n+j]%2!=0 && t[(i-1)*n+j]%2!=0) count++;
        else if (t[i*n+j]%2==0 && t[i*n+j-1]%2!=0 && t[i*n+j+1]%2!=0 && t[(i+1)*n+j]%2!=0 && t[(i-1)*n+j]%2!=0) count++;
    }
 }
     printf("\n%d",count);
}
