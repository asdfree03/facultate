#include <stdio.h>
#include <stdlib.h>
typedef struct masina{
    int nr_inm;
}masina;
typedef struct parc{
    int id;
    int n;
    struct parc *next;
    struct masina masini[100];
}parc;
parc *crearep(int id){
    parc *p = (parc *)malloc(sizeof(parc));
    p->id = id;
    p->next = NULL;
    p->n = -1;
    return p;
}
parc *adaugap(parc *lista, parc *p){
    if(lista == NULL) lista = p;
    else{
        parc *q;
        for(q = lista;q->next!=NULL;q=q->next);
        q->next = p;
    }
    return lista;
}
parc *adaugam(parc *lista,int id, int nr_inm){
    parc *p;
    for(p = lista;p->next!=NULL && p->id != id;p = p->next);
    if(p->id == id){
            p->n++;
        p->masini[p->n].nr_inm = nr_inm;
    }
    return lista;
}
parc *stergep(parc *lista,int id){
    parc *p; parc *temp; parc *prev;
    if(lista->id == id){
        temp = lista;
        lista = lista->next;
        free(temp);
        return lista;
    }
    for(p = lista;p->next != NULL && p->id != id;prev = p, p = p->next);
        temp = p;
    if(temp->id == id){
        prev->next = temp->next;
        free(temp);
    }
    return lista;
}
parc *stergem(parc *lista,int nr_inm){
    parc *p;
    for(p = lista;p->next!=NULL;p = p->next){
        for(int i = 0;i<=p->n;i++){
            if(p->masini[i].nr_inm == nr_inm){
                for(int j = i;j<p->n;j++) p->masini[j] = p->masini[j+1];
                p->n--;
            }
        }
    }
    return lista;
}
parc *transfer(parc *lista,int id,int nr_inm){
    lista = stergem(lista,nr_inm);
    lista = adaugam(lista,id,nr_inm);
    return lista;
}
void sort(parc *p){
    masina aux;
    for(int i = 0;i<p->n;i++)
    for(int j = 0;j<p->n-i;j++){
        if(p->masini[j].nr_inm>p->masini[j+1].nr_inm){
            aux = p->masini[j];
            p->masini[j] = p->masini[j+1];
            p->masini[j+1] = aux;
        }
    }
}
void afisare(parc *lista){
    parc *p;
    for(p = lista; p!=NULL;p = p->next){
        sort(p);
        printf("%d\n",p->id);
        for(int i = 0;i<=p->n;i++) printf("%d\n",p->masini[i].nr_inm);
        printf("\n");
    }
}
int main()
{
 parc *lista = NULL;
 parc *p = crearep(0);
 lista = adaugap(lista, p);
 p = crearep(1);
 lista = adaugap(lista,p);
 p = crearep(2);
 lista = adaugap(lista,p);
 lista = adaugam(lista,0,123);
 lista = adaugam(lista,0,456);
 lista = adaugam(lista,2,456);
 lista = adaugam(lista,2,956);
 lista = adaugam(lista,2,156);
 afisare(lista);
 lista = stergep(lista,1);
 //lista = stergem(lista,123);
 //lista = transfer(lista,2,456);
 afisare(lista);
}
