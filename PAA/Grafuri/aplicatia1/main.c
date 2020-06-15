#include <stdio.h>
#include <stdlib.h>
#define MAX_NR_NODURI 100
int rez1[MAX_NR_NODURI]; int r1; int r2; int ver[MAX_NR_NODURI]; int vr;
int rez2[MAX_NR_NODURI];
typedef struct Coada{
    int size;
    int t[MAX_NR_NODURI];
} Coada;
typedef struct TipNod {
  int cheie;
} Nod;
typedef struct TipArc {
    int idx_nod_1, idx_nod_2;
} Arc;
typedef struct Graf {
  int nr_noduri;
  Nod Noduri[MAX_NR_NODURI];
  int Arce[MAX_NR_NODURI][MAX_NR_NODURI];
} Graf;
  int marc[MAX_NR_NODURI];
Nod crearen(int cheie){
    Nod n;
    n.cheie = cheie;
    return n;
}
Graf *creareg(){
    Graf *g = (Graf *)malloc(sizeof(Graf));
    return g;
}
Coada *crearec(){
    Coada *q = (Coada *)malloc(sizeof(Coada));
    q->size= 0;
    return q;
}
Arc crearea(int n1,int n2){
    Arc a;
    a.idx_nod_1 = n1;
    a.idx_nod_2 = n2;
    return a;
}
void Initializare(Graf *g){
  g->nr_noduri = 0;
}
void InsertNod(Graf *g, Nod n){
  int index_nod = g->nr_noduri;
  g->Noduri[index_nod] = n;
  g->nr_noduri++;
  int i;
  for(i = 0; i < g->nr_noduri; i++){
    g->Arce[index_nod][i] = g->Arce[i][index_nod] = 0;
  }
}
void InsertArc(Graf *g, Arc a){
  g->Arce[a.idx_nod_1][a.idx_nod_2] = g->Arce[a.idx_nod_2][a.idx_nod_1] = 1;
}
void Afiseaza_Arce(Graf *g){
  int i,j;
  for(i = 0; i < g->nr_noduri; i++){
    for(j = 0; j < g->nr_noduri; j++)
      printf("%d ", g->Arce[i][j]);
    printf("\n");
  }
}
void CautaInAdancime(Graf *g, Nod x)
{
    Nod y;
    marc[x.cheie] = 1;
    rez1[r1++] = x.cheie+1;
    for(int i = 0;i<g->nr_noduri;i++){
        if(g->Arce[x.cheie][i]==1){
            y = crearen(i);
            if(marc[y.cheie] == 0)
                CautaInAdancime(g,y);
        }
    }
}
int VID(Coada *Q){
    if(Q->size == 0) return 1;
    return 0;
}
void ADAUGA(Coada *Q, Nod x){
    Q->t[Q->size] = x.cheie;
    Q->size++;
}
Nod SCOATE(Coada *Q){
    Nod n = crearen(Q->t[0]);
    Q->size--;
    for(int i = 0;i<Q->size;i++) Q->t[i] = Q->t[i+1];
    return n;
}
void CautaPrinCuprindere(Graf *g, Nod x)
{
    Coada *Q = crearec();
    Nod y;
    ADAUGA(Q, x);
    while(VID(Q) == 0)
    {
        x = SCOATE(Q);
        rez2[r2++] = x.cheie+1;
        marc[x.cheie] = 1;
        for(int i = 0;i<g->nr_noduri;i++){
            if(g->Arce[x.cheie][i]==1){
                y = crearen(i);
                if(marc[y.cheie] == 0)
                {
                    marc[y.cheie] = 1;
                    ADAUGA(Q, y);
                }
            }
        }
}
}
void clearrez(){
    r1 = 0;
    r2 =0;
    for(int i =0;i<MAX_NR_NODURI;i++){
        rez1[i]= rez2[i] =0;
    }
}
void clear(Graf *g){
    for(int j = 0;j<g->nr_noduri;j++)
        marc[j] = 0;
}
void verifica(Graf *q){
    for(int i = 0;i<MAX_NR_NODURI;i++) ver[i] = 0;
    vr = 0;
    Nod n;
    for(int i = 0;i<q->nr_noduri;i++){
        n = crearen(i);
        clear(q);
        clearrez();
        CautaInAdancime(q,n);
        clear(q);
        CautaPrinCuprindere(q,n);
        int ok = 1, j= 0;
        while(j<q->nr_noduri){
            if(rez1[j]!=rez2[j]) ok = 0;
            j++;
        }
        if(ok) ver[vr++] = i+1;
    }
    for(int i = 0;i<vr;i++) printf("%d ",ver[i]);
}
int main()
{
    int a,m;
    scanf("%d %d",&a,&m);
    Graf *g = creareg();
    Initializare(g);
    Nod n;
    for(int i = 0;i<a;i++){
        n = crearen(i);
        InsertNod(g,n);
    }
    int m1,m2;
    Arc arc;
    for(int i =0;i<m;i++){
        scanf("%d %d",&m1,&m2);
        arc = crearea(m1-1,m2-1);
        InsertArc(g,arc);
    }
    verifica(g);
}
