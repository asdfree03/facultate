#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct masina{
    char nr_inm[8];
}masina;
typedef struct parc{
    int id;
    int n;
    struct parc *next;
    struct masina masini[5];
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
parc *adaugam(parc *lista,int id, char nr_inm[]){
    parc *p;
    for(p = lista;p->next!=NULL && p->id != id;p = p->next);
    if(p->id == id){
            p->n++;
        strcpy(p->masini[p->n].nr_inm,nr_inm);
    }
    return lista;
}
parc *stergep(parc *lista,int id){
    parc *p; parc *temp; parc *prev;
    if(lista->id == id){
                for(int j = 0;j<lista->n;j++) lista->masini[j] =lista->masini[j+1];
                lista->n--;
        return lista;
    }
    for(p = lista;p->next != NULL && p->id != id;prev = p, p = p->next);
        temp = p;
    if(temp->id == id){
                for(int j = 0;j<p->n;j++) p->masini[j] = p->masini[j+1];
                p->n--;
    }
    return lista;
}
void afisare(parc *lista){
    parc *p;
    for(p = lista; p!=NULL;p = p->next){
        printf("%d\n",p->id);
        for(int i = 0;i<=p->n;i++) printf("%s\n",p->masini[i].nr_inm);
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
 lista = adaugam(lista,0,"123");
 lista = adaugam(lista,0,"456");
 lista = adaugam(lista,2,"456");
 lista = adaugam(lista,2,"956");
 lista = adaugam(lista,2,"156");
 afisare(lista);
 lista = stergep(lista,2);
 afisare(lista);
}
