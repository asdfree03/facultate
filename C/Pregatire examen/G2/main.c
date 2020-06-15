#include <stdio.h>
#include <stdlib.h>
int n;
float suml(float **t,int l){
    int sumlin = 0;
     for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++) {
            if(i==l) sumlin+= t[i][j];
        }
        return sumlin;
}
float sumc(float **t,int c){
    int sumlin=0;
     for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++) {
            if(j==c) sumlin+= t[i][j];
        }
        return sumlin;
}
int main()
{
    float **t,*v;
    int l,c;
    scanf("%d",&n);
    t = (float **)malloc(n * sizeof(float *));
    for (int i = 0;i<n;i++) t[i] = (float *)malloc(n*sizeof(float));
    for(int i = 0;i<n;i++)
        for(int j = 0 ;j<n;j++) scanf("%f",&t[i][j]);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++) printf("%.2f ",t[i][j]);
        printf("\n");
    }
    v = (float *)malloc(n*sizeof(float));
    for(int i = 0;i<n;i++) v[i] = (suml(t,i) - sumc(t,i))*1.0;
    for(int i = 0;i<n;i++) printf("%2.f ",v[i]);
    free(t);
    free(v);
}
