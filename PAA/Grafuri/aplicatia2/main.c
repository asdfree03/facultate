#include <stdio.h>
#include <stdlib.h>
#define MAX_NR_NODURI 30
int cicl = 0; int out[MAX_NR_NODURI]; int lastout[MAX_NR_NODURI];
int o;int lo;
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
void CautaInAdancime(Graf *g, Nod x)
{
    Nod y;
    marc[x.cheie] = 1;
    //printf("%d ",x.cheie+1);
    out[o++] = x.cheie;
    for(int i = 0;i<g->nr_noduri;i++){
        if(g->Arce[x.cheie][i]==1){
            y = crearen(i);
            if(marc[y.cheie] == 0)
                CautaInAdancime(g,y);
        }
    }
}
void CautaCiclu(Graf *g, Nod x,int z,int lv)
{
    Nod y;
    marc[x.cheie] = 1;
    //printf("%d ",x.cheie+1);
    for(int i = 0;i<g->nr_noduri;i++){
        if(g->Arce[x.cheie][i]==1){
            y = crearen(i);
            if(y.cheie == z && lv!= y.cheie && lv!=x.cheie){cicl = 1; return;}
            if(marc[y.cheie] == 0){
                lv = x.cheie;
                CautaCiclu(g,y,z,lv);
            }
        }
    }
}
void clearout(){
    for(int i = 0;i<MAX_NR_NODURI;i++) out[i]=0;
    o=0;
}
void clearlout(){
    for(int i = 0;i<MAX_NR_NODURI;i++) lastout[i]=0;
    lo=0;
}
int ciclic(Graf *g){
    for(int i = 0;i<g->nr_noduri;i++){
            cicl=0;
            clear(g);
            CautaCiclu(g,crearen(i),i,-1);
            if(cicl == 1) return 1;
    }
    return 0;
}
int check(){
    int ok;
 for(int i = 0;i<o;i++){
         ok = 0;
    for(int j = 0;j<o;j++){
        if(out[i]==lastout[j]) ok = 1;
    }
    if(ok==0) return 0;
 }
 return 1;
}
void transf(){
    for(int i = 0;i<lo;i++) lastout[i] = -1;
    for(int i = 0;i<o;i++) lastout[i] = out[i];
    clearout();
}
void clear(Graf *g){
    for(int j = 0;j<g->nr_noduri;j++)
        marc[j] = 0;
}
void conexe(Graf *g){
     int cate = 0;
    for(int i = 0 ;i<g->nr_noduri;i++){
        clear(g);
        CautaInAdancime(g,crearen(i));
        if(!check()) cate++;
        transf();
    }
    printf("%d ",cate);
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
    conexe(g);
    printf("%d",ciclic(g));
}
