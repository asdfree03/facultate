#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a[10], b[10], c[20];
    int k=0;
    for(int i =0; i<10; i++){
        printf("a[%d]= ",i);
        scanf("%f",&a[i]);
        printf("b[%d]= ",i);
        scanf("%f",&b[i]);
        c[k]= a[i];
        c[k+1]=b[i];
        k=k+2;
    }
    int compare (const void * a, const void * b)
{
  float fa = *(const float*) a;
  float fb = *(const float*) b;
  return (fa > fb) - (fa < fb);
}
 qsort (c, 20, sizeof(float), compare);
 for(int i = 0; i<20;i++) printf("%f ",c[i]);
}
