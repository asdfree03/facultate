#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a,*b,*c,m,n;
    int count = 0;
    printf("N = ? M= ?\n");
    scanf("%d %d",&n,&m);
    a = (int *)malloc(n*sizeof(int));
    b = (int *)malloc(m*sizeof(int));
    printf("Elementele vectorului A  = \n");
    for(int i = 0;i<n;i++) scanf("%d",&a[i+n]);
    printf("Elementele vectorului B  = \n");
    for(int i = 0;i<m;i++) scanf("%d",&b[i+m]);
    if(m>=n){
            c = (int *)malloc(m*sizeof(int));
            for(int i = m-1; i>=0;i--) {
                for(int j = n-1;j>=0;j--) if(b[i+m]==a[j+n]) {c[count] = b[i+m]; count++;}
            }
    }
    else {
            c = (int *)malloc(n*sizeof(int));
            for(int i = n-1; i>=0;i--) {
                for(int j = m-1;j>=0;j--) if(a[i+n]==b[j+m]) {c[count] = a[i+n]; count++;}
            }
    }
    for(int i = 0;i<count;i++) printf("%d ",c[i]);
}
