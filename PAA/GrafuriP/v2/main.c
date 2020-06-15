#include <stdio.h>
#include <stdlib.h>
typedef struct TipNod{
  int cheie;
} Nod;
typedef struct TipArc {
    int idx_nod_1, idx_nod_2;
} Arc;
typedef struct Graf {
  int nr_noduri;
  Nod Noduri[256];
  int Arce[256][256];
} Graf;
Nod CreareN(int cheie){
    Nod n;
    n.cheie = cheie;
    return n;
}
Graf *CreareG(){
    Graf *g = (Graf *)malloc(sizeof(Graf));
    return g;
}
Arc CreareA(int n1,int n2){
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
void InsertArc(Graf *g, Arc a,int p){
  g->Arce[a.idx_nod_1][a.idx_nod_2] = g->Arce[a.idx_nod_2][a.idx_nod_1] = p;
}

//Tot ce e mai sus e din problemele mele din laboratorul trecut, copy paste
int CautaMin(int pondere[], int vizitat[], int n)
{
    //pentru a putea compara cu valoarea maxima
    int min = 1024;
    //in pos salvez nodul cu ponderea minima gasit
    int pos;
    int i = 0;
    while(i<n){
        //verific fiecare nod si salvez nodul cu cea mai mica pondere
        if (vizitat[i] == 0 && pondere[i] < min){
            min = pondere[i];
            pos = i;
        }
        i++;
    }
    return pos;
}
void init(int pondere[],int vizitat[],int nr){
    //Pentru a incepe tot timpul cu primul nod
    pondere[0] = 0;
    vizitat[0] = 0;
        // Instantierea tuturor ponderilor ca maxime si tuturor nodurilor ca nevizitate. Daca vizitat = 0 inseamna ca nu a fost vizitat, daca =1 inseamna ca a fost vizitat deja
    int i=1;
    while(i<nr){
        pondere[i] = 1024;
        vizitat[i] = 0;
        i++;
    }
}
int prim(Graf *g){
    int nr = g->nr_noduri;
    //Tabloul in care salvez ponderirile minime ale legaturilor nodurilor
    int pondere[nr];
    //Tabloul in care salvez daca am vizitat un nod sau nu
    int vizitat[nr];
    //Initializarea tablourilor
    init(pondere,vizitat,nr);
    //Parcurgearea pentru fiecare nod a algoritmului
    for (int i = 0; i<nr-1; i++) {
        //caut nodul urmator cu cea mai mica pondere care inca nu a fost vizitat
        int k = CautaMin(pondere, vizitat,nr);
        //il marchez ca vizitat
        vizitat[k] = 1;
        for (int i = 0; i < nr; i++)
            //verific daca exista legatura intre noduri si daca nu a fost vizitat inca
            if(g->Arce[k][i]!=0 && vizitat[i] == 0)
            //caut anume cea mai mica pondere si o salvez in ponderi si nodul il salvez in tabloul cu rezultate grafmin
                if(g->Arce[k][i] < pondere[i]){
                    pondere[i] = g->Arce[k][i];
                }
    }
    //variabila pentru calculul sumei ponderilor
    int rez=0;
    //pentru fiecare nod, in tabloul grafmin eu am salvat nodul urmator din traseul minim, de aia adun toate ponderile pentru ficare nod si vecinul sau urmator
    for(int i = 1;i<nr;i++) rez+=pondere[i];
    return rez;
}
int main()
{
    int a,m;
    scanf("%d %d",&a,&m);
    Graf *g = CreareG();
    Initializare(g);
    Nod n;
    for(int i = 0;i<a;i++){
        n = CreareN(i);
        InsertNod(g,n);
    }
    int m1,m2,m3;
    Arc arc;
    for(int i =0;i<m;i++){
        scanf("%d %d %d",&m1,&m2,&m3);
        arc = CreareA(m1-1,m2-1);
        InsertArc(g,arc,m3);
    }
    printf("\n%d",prim(g));
}
