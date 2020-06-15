#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int a[], int s, int d,int n) {
       int i = s, j = d, ci=0 ,cj= 0;
       int   x = a[(s + d) / 2];
       do {
              while (a[i]<x) i++;
              while (a[j]>x) j--;
              if (i <= j) {
                    if(a[i]==x && i != (s+d)/2){ swap(&a[i],&a[s+ci]);
                    ci++;
                   i++;
                    }
                    if(a[j]==x && j != (s+d)/2){ swap(&a[j],&a[s+ci]);
                    ci++;
                    i++;
                    }
                   }
                     swap(&a[i],&a[j]);
                     i++;
                     j--;
       } while (i <= j);
       for(int i = 0;i<n;i++) printf("%d ",a[i]);
    printf("\ni = %d j = %d ci = %d cj = %d\n",i,j,ci,cj);
       for(int e = 0;e<ci;e++) swap(&a[s+e],&a[i-e]);
      for(int i = 0;i<n;i++) printf("%d ",a[i]); printf("\n\n");
      if (s<j-ci) quicksort(a,s, j-ci,n);
      if (d>i) quicksort(a,i, d,n);
}
int main()
{
    int a[] = {1,2,3,2,4},
        n = sizeof(a)/sizeof(int);
        for(int i = 0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    quicksort(a,0,n-1,n);
    for(int i = 0;i<n;i++) printf("%d ",a[i]);printf("\n");
}
