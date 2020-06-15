#include <stdio.h>
#include <stdlib.h>
typedef struct eroare{
        int cod;
        int prioritate;
        struct eroare *next;
 }eroare;
 eroare *create(int cod,int prioritate){
        eroare *p = (eroare*)malloc(sizeof(eroare));
        p->next = NULL;
        p->cod = cod;
        p->prioritate= prioritate;
        return p;
}
eroare *adaugai(eroare *lista,eroare *p){
    if (!lista) lista = p;
    else p->next = lista;
    lista = p;
    return lista;
 }
eroare *adaugasf(eroare *lista,eroare *p){
    if (!lista) lista = p;
    eroare *aux;
    for(aux = lista;aux->next!=NULL;aux=aux->next);
    aux->next = p;
    return lista;
 }
 eroare *adaugamid(eroare *lista,eroare *p){
    if (!lista) lista = p;
    else{
    eroare *aux;
    for(aux = lista;aux->prioritate==0 && aux->next != NULL;aux = aux->next);
    if(aux->next==NULL){
            aux->next = p;}
    else{
        for(aux;aux->next->cod < p->cod && aux->next->prioritate!= 7 && aux->next!=NULL;aux = aux->next);
        if(aux->next==NULL){ aux->next = p;}
        else{
        p->next = aux->next;
        aux->next = p;
        }
    }
    }
    return lista;
 }
  eroare *add(eroare *lista,eroare *p){
    if(p->prioritate==0) lista = adaugai(lista,p);
    else if(p->prioritate==7) lista = adaugasf(lista,p);
    else lista = adaugamid(lista,p);
 }
 void afisare(struct eroare *lista){
    struct eroare *p;
    for(p=lista;p!=NULL;p=p->next) printf("%d %d\n",p->cod,p->prioritate);
    printf("\n");
}
int main()
{
    eroare* lista = NULL;
    eroare* nod = create(1,0);
    lista = add(lista,nod);
    nod = create(4,0);
    lista = add(lista,nod);
    nod = create(2,3);
    lista = add(lista,nod);
    nod = create(2,7);
    lista = add(lista,nod);
    nod = create(5,3);
    lista = add(lista,nod);
     nod = create(9,4);
    lista = add(lista,nod);
    afisare(lista);
}
