#include <stdio.h>
#include <stdlib.h>

int main()
{
int *t,*v,n,m;
scanf("%d %d",&n,&m);
t = (int *)malloc(n*sizeof(int));
v = (int *)malloc(m*sizeof(int));
if(v==NULL || t == NULL) exit(1);
printf("\n");
for(int i =0;i<n;i++) scanf("%d",&t[i]);
printf("\n");
for(int i =0;i<m;i++) scanf("%d",&v[i]);
printf("\n");
for(int i = 0;i<n;i++){
        if(t[i]%2!=0){
            v = (int *)realloc(v,(m+1)*sizeof(int));
            v[m] = t[i];
            m++;
            for(int j = i; j<n-1;j++){
                t[j] = t[j+1];
            }
            t = (int *)realloc(t,(n-1) * sizeof(int));
            n--;
        }
    }
for(int i = 0;i<m;i++){
        if(v[i]%2==0){
            t = (int *)realloc(t,(n+1)*sizeof(int));
            t[n] = v[i];
            n++;
            for(int j = i; j<m-1;j++){
                v[j] = v[j+1];
            }
            v = (int *)realloc(v,(m-1) * sizeof(int));
            m--;
        }
    }
printf("\n");
for(int i = 0; i<n;i++) printf("%d ",t[i]); printf("\n");
for(int i = 0;i<m;i++) printf("%d ",v[i]); printf("\n");
free(v);free(t);
}
