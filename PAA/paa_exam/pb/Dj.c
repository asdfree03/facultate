#include<fstream.h>
int a[20][20], n, m, k=1;
int viz[20], d[20], tata[20];
const infinit = 10000;

void citiregraf()
{
  int i,x, y, j, c;
  ifstream f ("graf.in");
  f>>n>>m;
  for(i=1; i<=m; i++)
   { f>>x>>y>>c;
    a[x][y]=a[y][x]=c;
   }
  for (i=1; i<=n; i++)
    for(j=1; j<=n; j++)
      if(a[i][j]==0) a[i][j]=infinit;
  f.close();
}

void drum(int i)
{
  if(tata[i]!=0)
    {
      drum(tata[i]);
      cout<<","<<i;
    }
  else cout<<i;
}

void alg_dijkstra()
 {
   int pas, min, k, i;
   for(pas=1; pas<=n-1; pas++)
     {
       min=infinit;
       for(i=1; i<=n; i++)
         if((viz[i]==0) && (d[i]<min))
           { min=d[i]; k=i; }
       viz[k]=1;
       for(i=1; i<=n; i++)
         if((viz[i]==0) && (d[k]+a[k][i]<d[i]))
           { d[i]=d[k]+a[k][i]; tata[i]=k; }
     }
 }

void main()
{ int i, s;
  citiregraf();
  cout<<"dati nodul de start"; cin>>s;

  for(i=1; i<=n; i++)
    {
      viz[i]=0;
      d[i]=a[s][i];
      if(d[i]<infinit)
    tata[i]=s;
      else tata[i]=0;
    }
  viz[s]=1; tata[s]=0; d[s]=0;
  alg_dijkstra();

  for(i=1; i<=n; i++)
    {
      cout<<"drumul minim de la "<<s<<" la "<<i<<" este: ";
      drum(i);
      cout<<endl<<"costul este: "<<d[i]<<endl;
    }

}

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int a[100], m[100][100], n, u[100],x[100],k=0,min=999999,d[10],t[10];

void functie(int a)
{
    int i,x;
    u[a-1]=1;
    for(i=0;i<n;i++)
    {


        if(u[i]==0&&(d[i]>d[a-1]+m[a-1][i]))
        {
            d[i]=d[a-1]+m[a-1][i];
            t[i]=a;
        }
    }
    for(i=0;i<n;i++)
    {
        if(d[i]<min&&u[i]==0)
        {
            min=d[i];
            x=i+1;
        }
    }
    functie(x);


}

int main(){

	int i,j,suma=0;
	FILE *f;
	f = fopen("fisier.txt", "r");
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(f, "%d", &a[i]);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		fscanf(f, "%d", &m[i][j]);
	for (i = 0; i<n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", m[i][j]);
		printf("\n");

	}
	for(i=0;i<n;i++)
        u[i]=0;
	u[0]=1;
	d[0]=0;
	d[0]=9;
	d[0]=1;
	d[0]=3;
	d[0]=9999;
	d[0]=9999;
	d[0]=9;
	d[0]=9999;
	for(i=0;i<n;i++)
    {
        t[i]=1;
    }
    functie(3);
    for(i=0;i<n;i++)
        printf("%d  ",d[i]);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d  ",t[i]);

}
