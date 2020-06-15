#include <stdio.h>
#include <stdlib.h>
int m,n;
void schimbal(int t[100][100],int a, int b){
    int aux[100];
    for(int i = 0;i<m;i++) aux[i] = t[a][i];
    for(int i = 0;i<m;i++) t[a][i] = t[b][i];
    for(int i = 0;i<m;i++) t[b][i] = aux[i];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++) printf("%d ",t[i][j]); printf("\n");}
}
void schimbac(int t[100][100],int a, int b){
    int aux[100];
    for(int i = 0;i<n;i++) aux[i] = t[i][a];
    for(int i = 0;i<n;i++) t[i][a] = t[i][b];
    for(int i = 0;i<n;i++) t[i][b] = aux[i];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++) printf("%d ",t[i][j]); printf("\n");}
}
int main()
{
        int t[100][100];
    int a,b;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&a);
    scanf("%d",&b);
    for(int i = 0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",&t[i][j]);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++) printf("%d ",t[i][j]); printf("\n");}
        printf("\n");
        schimbal(t,a,b); printf("\n");
        schimbac(t,a,b); printf("\n");
}
