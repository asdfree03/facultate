#include <stdio.h>
#include <stdlib.h>
#define tt 4
int a[10];
void insertie(int a[],int n)
{
 int i,j; int o;
       //fanionul pe poziţia a[n]
 for( i=n-2;i>=0;i--)
 {
    a[n]=a[i];
    j=i+1;
    while(a[j]<a[n])
    {
      a[j-1]=a[j]; j++;
    }
    a[j-1]=a[n];
    printf("i=%d\n",i);
     printf("0 1 2 3 4 5 6 7 8 9\n");
     for( o = 0;o<n;o++) printf("%d ",a[o]);
     printf("\n");
 }
 printf("\n");
 for( o = 0;o<n;o++) printf("%d ",a[o]);
}
void sortare_prin_insertie_binara(int a[],int n)
{
    int i,j,stanga,dreapta,m; int temp;
    for( i= 1; i <= n; i ++)
    {
      temp= a[i]; stanga= 0; dreapta= i-1;
      while (stanga<=dreapta)
        {
          m= (stanga+dreapta)/ 2;
          if (a[m]>temp)
              dreapta= m-1;
            else
              stanga= m+1;
        }   /*WHILE*/
      for( j= i-1; j >= stanga; j --) a[j+1]= a[j];
      a[stanga]= temp;

     //  printf("i=%d\n",i);
     //printf("0 1 2 3 4 5 6 7 8 9\n");
     for(int o = 0;o<n;o++) printf("%d ",a[o]);
     printf("\n");
    }   /*FOR*/
}
  void sortare_prin_selectie(int a[], int n)
{
    int i,j,min; int temp;
    for( i= 0; i <= n-2; i ++)
    {
      min= i; temp= a[i];
      for( j= i+1; j < n; j ++)
        if (a[j]<temp)
          {
            min= j; temp= a[j];
          }   /*FOR*/
      a[min]= a[i]; a[i]= temp; /*interschimbarea*/
           printf("i=%d\n",i);
     printf("0 1 2 3 4 5 6 7 8 9\n");
     for(int o = 0;o<n;o++) printf("%d ",a[o]);
     printf("\n");
    }   /*FOR*/
}
void selectie_optimizata(int a[], int n)
{
    int i,j,min; int temp;
    for( i= 0; i <= n-2; i ++)
    {
      min= i; temp = a[i];
      for( j= i+1; j < n; j ++)
        if (a[j]<a[min])   min= j;
      temp= a[min]; a[min]= a[i]; a[i]= temp;
            printf("i=%d\n",i);
     printf("0 1 2 3 4 5 6 7 8 9\n");
     for(int o = 0;o<n;o++) printf("%d ",a[o]);
     printf("\n");
    }   /*FOR*/
}
void bubblesort(int a[], int n)
{
    int i,j; int temp;
    for( i= 0; i < n; i ++)
    {
      for( j= n-1; j>i; j --){
        if (a[j-1]>a[j])
          {
            temp= a[j-1]; a[j-1]= a[j]; a[j]= temp;
          }
      }
                  printf("i=%d\n",i);
     printf("0 1 2 3 4 5 6 7 8 9\n");
     for(int o = 0;o<n;o++) printf("%d ",a[o]);
     printf("\n");
    }
}
void shakersort(int a[], int n)
{
    int j,ultim,sus,jos;
    int temp;
    sus= 1; jos= n-1; ultim= n-1;
    do {
      for( j= jos; j >= sus; j --)
     {
         if (a[j-1]>a[j])
        {
          temp= a[j-1]; a[j-1]= a[j]; a[j]= temp;
          ultim= j;
        }
            printf("j=%d\n",j);
     printf("0 1 2 3 4 5 6 7 8 9\n");
     for(int o = 0;o<n;o++) printf("%d ",a[o]);
     printf("\n");
      }  /*FOR*/
      sus= ultim+1;
      for( j=sus; j <= jos; j ++)
     {
      if (a[j-1]>a[j])
        {
          temp=a[j-1]; a[j-1]=a[j]; a[j]=temp;
          ultim=j;
        }
            printf("j=%d\n",j);
     printf("0 1 2 3 4 5 6 7 8 9\n");
     for(int o = 0;o<n;o++) printf("%d ",a[o]);
     printf("\n");
      }  /*FOR*/
    jos=ultim-1;
  } while (!(sus>jos));
}
void shellsort(int a[], int n)
{
       int i, j,pas;
       int temp;
       unsigned char m;
       int h[tt];

     /*ex. de atribuire directa incrementi pentru un tablou h de 4 elemente*/
       h[0] = 9;
       h[1] = 5;
       h[2] = 3;
       h[3] = 1;
       for (m = 0; m < tt; ++m)
       {
           //for(int o = 0;o<n;o++) printf("%d ",a[o]);
     printf("\n");
              pas = h[m]; printf("pas = %d\n",pas);
              for (i = pas; i < n; ++i)
              {
                    //printf("i = %d\n",i);
                     temp = a[i];
                     for (j = i; j >= pas && a[j - pas]>temp; j = j - pas)
                     {
                           // printf("j = %d ,%d %d\n",j,a[j-pas],temp);
                           a[j] = a[j - pas];
                     }
                     a[j] = temp;
                     for(int o = 0;o<n;o++) printf("%d ",a[o]);
     printf("\n");
              } /*for*/
       } /*for*/
} /*Shellsort*/
void quicksort(int a[], int s, int d) {
       int i = s, j = d;
       int   x = a[(s + d) / 2];
       do {
              while (a[i]<x) i++;
              while (a[j]>x) j--;
              if (i <= j) {
                     int temp = a[i];
                     a[i] = a[j];
                     a[j] = temp;
                     i++;
                     j--;
                     for(int o = 0;o<6;o++) printf("%d ",a[o]);
     printf("\n");
              }
       } while (i <= j);
       printf("\n");
       if (s<j) quicksort(a,s, j);
       if (d>i) quicksort(a,i, d);
}/*quicksort*/
void deplasare(int* s, int *temp, int* d)
//realizeaza glisarea elementului a[s] in pozitia corecta
{
       int i, j;
       int ret = 0;
       i = *s; j = 2 * i; *temp = a[i]; ret = 0;
       while ((j <= *d) && (!ret))
       {
              if (j < *d && a[j] < a[j + 1])
                j = j + 1;

              if ((*temp)<a[j])
              {
                     a[i] = a[j]; i = j; j = 2 * i;
              }
              else
                     ret = 1;
       }   /*while*/
       a[i] = *temp;
}
void heapsort(int a[], int n)
{
       int s, d;
       int temp;
        /*construcţie ansamblu*/
       s = (n / 2) + 1; d = n - 1;
       while (s>0)
       {
              s = s - 1; deplasare(&s, &temp, &d);
             for(int o = 0;o<10;o++) printf("%d ",a[o]);
     printf("\n");
       }   /*while*/
        while (d>0)   /*sortare ansamblu*/
       {
              temp = a[0]; a[0] = a[d]; a[d] = temp;
              d = d - 1; deplasare(&s, &temp, &d);
              for(int o = 0;o<10;o++) printf("%d ",a[o]);
     printf("\n");
       }
       for(int o = 0;o<10;o++) printf("%d ",a[o]);
     printf("\n");
}    /*Heapsort*/
int main()
{
   int  a[] = {35,8,17,10,8,1};
   //a[0] = 5; a[1] = 3; a[2] = 7; a[3] = 1; a[4] = 2; a[5] = 4; a[6] = 9; a[7]=6; a[8]= 8; a[9]= 0;
   // a[0] = 4; a[1] = 10; a[2] = 3; a[3] = 5; a[4] = 1;
    int n = 6;
    printf("\n");
   // printf("5 3 7 1 2 4 9 6 8 0\n");
   // insertie(a,n);
    //sortare_prin_insertie_binara(a,n);
    //sortare_prin_selectie(a,n);
    //selectie_optimizata(a,n);
    //bubblesort(a,n);
    //shakersort(a,n);
   // shellsort(a,n);
    quicksort(a,0,5);
    //heapsort(a,n);
}
