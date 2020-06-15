#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t[100][100],n; int sum = 0; int prod = 1;
    printf("N= "); scanf("%d",&n);
    for(int i=0;i<n;i++)
    for (int j=0;j<n;j++){
        scanf("%d",&t[i][j]);
    }
       for(int i=0;i<n;i++)
    for (int j=0;j<n;j++){
        if(i==j) sum = sum+t[i][j];
        if(i+j==n-1) prod = prod * t[i][j];
    }
    printf("Suma = %d\nProd = %d",sum,prod);
}
