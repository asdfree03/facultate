#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **t,n,i,j;
    scanf("%d",&n);
    t = (int **)malloc(n*sizeof(int *));
    for(i  = 0;i<n;i++) t[i] = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        for(j = 0;j<n;j++) scanf("%d",&t[i][j]); printf("Numerele pare cu vecini impari\n");
    for(i=0;i<n;i++){
        for(j = 0;j<n;j++){
            if(t[i][j] % 2 == 0){
                if(i==0){
                    if(j==0) if(t[i][j+1] %2 != 0 && t[i+1][j] %2 != 0) printf("%d ",t[i][j]);
                    else if(j==n-1) if(t[i][j-1] %2 != 0 && t[i+1][j] %2 != 0) printf("%d ",t[i][j]);
                    else {if(t[i][j-1] %2 != 0 && t[i+1][j] %2 != 0 && t[i][j+1] %2 != 0) printf("%d ",t[i][j]);}
                }
                else if(i==n-1){
                    if(j==0) if(t[i][j+1] %2 != 0 && t[i-1][j] %2 != 0) printf("%d ",t[i][j]);
                    else if(j==n-1) if(t[i][j-1] %2 != 0 && t[i-1][j] %2 != 0) printf("%d ",t[i][j]);
                    else {if(t[i][j-1] %2 != 0 && t[i-1][j] %2 != 0 && t[i][j+1] %2 != 0) printf("%d ",t[i][j]); }
                }
                else if(j==0){
                    if(t[i][j+1] %2 != 0 && t[i-1][j] %2 != 0 && t[i+1][j] %2 != 0) printf("%d ",t[i][j]);
                }
                else if(j==n-1){
                    if(t[i][j-1] %2 != 0 && t[i-1][j] %2 != 0 && t[i+1][j] %2 != 0) printf("%d ",t[i][j]);
                }
                else{
                    if(t[i][j-1] %2 != 0 && t[i+1][j] %2 != 0 && t[i][j+1] %2 != 0 && t[i-1][j] %2 != 0) printf("%d ",t[i][j]);
                }
            }
        }
    }
}
