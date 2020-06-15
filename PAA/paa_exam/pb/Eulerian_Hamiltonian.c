#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int n,m,A[100][100],P[100],k,G[100];

void citire()
{
    int x,y;
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        fin>>x>>y;
        A[x][y]=A[y][x]=1;
    }
}

int grad(int k)//calculeaza gradul varfului k
{
    int s=0;
    for(int i=1;i<=n;i++)
        if(A[k][i]==1) s++;
    return s;
}

void DF(int s)//parcurge graful din varful s si marcheaza varfurile accesibile
{
    P[s]=1;
    for(int i=1;i<=n;i++)
        if(A[s][i]==1 && P[i]==0)
            DF(i);
}

int conex()//conexitatea grafului
{
    DF(1);
    for(int i=1;i<=n;i++)
        if(P[i]==0) return 0;
    return 1;
}

int euler()//daca este eulerian
{
    if(!conex()) return 0;//conex
    for(int i=1;i<=n;i++)
        if(G[i]%2==1) return 0;//si toate gradele pare
    return 1;
}

void ciclu_eulerian(int k)//construieste un ciclu eulerian
{
    int maxx=0,nmax=0;
    fout<<k<<" "; //afiseaza varful curent
    for(int i=1;i<=n;i++)//cauta varful urmator cu grad maxim
    {
        if(A[k][i]==1)
            if(G[i]>maxx)
            {
                maxx=grad(i);
                nmax=i;
            }
    }
    if(nmax!=0)
        {   A[k][nmax]=A[nmax][k]=0;//sterge mughia
            G[k]--;//scade gradele
            G[nmax]--;
            ciclu_eulerian(nmax);//merge in varful urmator
        }
}

int main()
{
    citire();
    for(int i=1;i<=n;i++) G[i]=grad(i);
    if(euler())
    {
        fout<<"este eulerian\n";
        ciclu_eulerian(1);
    }
    else fout<<"nu este eulerian\n";

    fin.close();
    fout.close();
    return 0;
}

#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");

int a[50][50],x[50],p[50],n,m,gasit;

void citire()
{
    int i,j;
    fin>>n>>m;
    while(fin>>i>>j) a[i][j]=a[j][i]=1;

}

int bun(int k)
{
   if(k>1) if(a[x[k]][x[k-1]]==0) return 0;
   if(k==n) if(a[x[1]][x[n]]==0) return 0;
   return 1;
}

void back(int k)
{
    if(!gasit)
    for(int i=1;i<=n;i++)
      if(!p[i])
      {
          x[k]=i; p[i]=1;
          if(bun(k)) if(k==n) gasit=1;
                     else back(k+1);
          p[i]=0;
      }

}
int main()
{
    citire();
    back(1);
    if(gasit) fout<<"da";
    else fout<<"nu";
    fin.close();
    fout.close();
    return 0;
}

#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int A[50][50],n,m,gasit;
int x[50],p[50];

void back(int k)
{
    if(!gasit)
    {
        for(int i=1;i<=n;i++)
        if(!p[i] && (A[x[k-1]][i] || k==1))
        {
            x[k]=i;
            p[i]=1;
            if(k==n && A[x[n]][x[1]]) gasit=1;
                else back(k+1);
            p[i]=0;
        }
    }
}

int main()
{
    int v1,v2;
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        fin>>v1>>v2;
        A[v1][v2]=1;
    }
    back(1);
    if(gasit) fout<<"da";
    else fout<<"nu";
    fin.close();
    fout.close();
    return 0;
}

#include<fstream.h>
const int max=15000;
int c[20][20],d[20],t[20],p[20],n,m,s;
ifstream f("d.in");
ofstream g("d.out");

void citire()
{ int i,j,x,y,cost;
  f>>n>>m;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      if(i==j) c[i][j]=0;
      else c[i][j]=max;
  for(i=1;i<=m;i++)
    { f>>x>>y>>cost;
      c[x][y]=cost;
    }
}

void dijkstra(int s)
{ int i,j,k,min;
  for(i=1;i<=n;i++)
     { d[i]=c[s][i];
       if(i!=s && d[i]!=max) t[i]=s;
     }
  p[s]=1;
  for(k=1;k<n;k++)
   { min=max;
     for(i=1;i<=n;i++)
       if(!p[i] && d[i]<min) { min=d[i]; j=i;
			     }
     for(i=1;i<=n;i++)
       if(!p[i])
       if(d[i]>d[j]+c[j][i])
	 { d[i]=d[j]+c[j][i];
	   t[i]=j;
	 }
     p[j]=1;
   }
}

void drum(int i)
{ if(t[i]) drum(t[i]);
  g<<i<<" ";
}

void main()
 { citire();
   f>>s;
   dijkstra(s);
   for(int i=1;i<=n;i++)
    if(i!=s)
    {g<<s<<"->"<<i<<": ";
     drum(i);
     g<<"="<<d[i]<<endl;
    }
}
