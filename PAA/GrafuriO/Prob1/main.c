#include <stdio.h>
#include <stdlib.h>
typedef struct Graf {
  int nr_noduri;
  int Noduri[256];
  int Arce[256][256];
} Graf;
Graf *CreareG(){
    Graf *g = (Graf *)malloc(sizeof(Graf));
    return g;
}
void Initializare(Graf *g,int n){
  g->nr_noduri = n;
}
void Insert(Graf *g, int m1, int m2, int m3){
  g->Arce[m1-1][m2-1] = m3;
}
void init(int pondere[],int vizitat[],int nr){
    pondere[0] = 0;
    vizitat[0] = 0;
    int i=1;
    while(i<nr){
        pondere[i] = 30000;
        vizitat[i] = 0;
        i++;
    }
}
int CautaMin(int pondere[], int vizitat[], int n){
    int min = 30000;
    int pos;
    int i = 0;
    while(i<n){
        if (vizitat[i] == 0 && pondere[i] <= min){
            min = pondere[i];
            pos = i;
        }
        i++;
    }
    return pos;
}
void afisRez(int t[],int n){
    for(int i = 1;i<n;i++){
        if(t[i]==30000) printf("0 ");
        else printf("%d ",t[i]);
    }
}
void dij(Graf *g){
    int nr = g->nr_noduri;
    int pondere[nr];
    int vizitat[nr];
    init(pondere,vizitat,nr);
    for (int i = 0; i < nr - 1; i++) {
        int k = CautaMin(pondere,vizitat,nr);
        vizitat[k] = 1;
        for (int j = 0; j < nr; j++)
            if (g->Arce[k][j] != 0 && vizitat[j]==0){
              if(pondere[j] > pondere[k] + g->Arce[k][j]){
                    pondere[j] = pondere[k] + g->Arce[k][j];
              }
            }
    }
    afisRez(pondere,nr);
}
int main()
{
    int a,m;
    scanf("%d %d",&a,&m);
    Graf *g = CreareG();
    Initializare(g,a);
    int m1,m2,m3;
    for(int i =0;i<m;i++){
        scanf("%d %d %d",&m1,&m2,&m3);
        Insert(g,m1,m2,m3);
    }
    printf("\n");
    dij(g);
}
