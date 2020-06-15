#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Multilista cu pointeri, facem o multilista, lista principala o lista de clase(8b, 9c)
fct de adaugat clase si pointeri catre elevi
- adaugare elev in clasa cu id dat
- afisare clase + elevi din ele
*/
typedef struct clasa{
    char nume[256];
    char id;
    struct elev *elevi;
    struct clasa *next;
}clasa;
typedef struct elev{
    char nume[256];
    struct elev *next;
}elev;
 clasa *create(char nume[],char id){
        clasa *p = (clasa*)malloc(sizeof(clasa));
        p->next = NULL;
        strcpy(p->nume,nume);
        p->id= id;
        p->elevi = NULL;
        return p;
}
elev *ecreate(char nume[]){
        elev *p = (elev*)malloc(sizeof(elev));
        p->next = NULL;
        strcpy(p->nume,nume);
        return p;
}
clasa *addc(clasa *lista,clasa *p){
    if (!lista) lista = p;
    else{
    clasa *aux;
    for(aux = lista;aux->next!=NULL;aux=aux->next);
    aux->next = p;
    }
    return lista;
 }
 void afisare(struct clasa *lista){
    struct clasa *p; struct elev *el;
    for(p=lista;p!=NULL;p=p->next) {
            printf("%s %c\n",p->nume,p->id);
            for(el = p->elevi; el!=NULL;el=el->next) printf("%s\n",el->nume);
    }
    printf("\n");
}
clasa *adde(clasa *lista,char idx,elev *e){
    struct clasa *aux; struct elev *el;
    for(aux = lista;aux->next!=NULL && aux->id!=idx;aux=aux->next);
    if(aux->next==NULL && aux->id != idx) return lista;
    if(!(aux -> elevi)) aux->elevi = e;
    else{
        for(el = aux->elevi; el->next!=NULL;el = el->next);
        el->next = e;
    }
    return lista;
}
int main()
{
    clasa *lista = NULL;
    clasa* nod = create("9D",'a');
    lista = addc(lista,nod);
    nod = create("8D",'b');
    lista = addc(lista,nod);
    elev* node = ecreate("Vitalie");
    lista = adde(lista,'b',node);
    node = ecreate("Banana");
    lista = adde(lista,'b',node);
    node = ecreate("Andrei");
    lista = adde(lista,'e',node);
    afisare(lista);
}
