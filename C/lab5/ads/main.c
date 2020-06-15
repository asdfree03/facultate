#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
int N,n,M,m; int i,j; int A[100][100],B[100][100];
scanf("%d %d",&N, &M );
scanf("%d %d",&n, &m);
for(i = 0 ;i<N;i++)
    for(j = 0;j<M;j++) scanf("%d",&A[i][j]);
for(i = 0 ;i<n;i++)
    for(j = 0;j<m;j++) scanf("%d",&B[i][j]);
for(i=0;i<N-n;i++)
    for(j=0;j<M-m;j++){
        bool found = true;
        if(A[i][j] == B[0][0])
            for(int r = 0;r<n-1;r++)
                for(int s = 0; s<m-1;s++)
                    if(B[r][s] != A[r+i][s+j]){
                        found = false;
                        break;
                    }
        if(found){
            printf("%d %d",i,j);
            break;
        }
    }
}
