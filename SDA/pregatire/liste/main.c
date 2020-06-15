#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct mesaj{
    int id;
    int prioritate;
    char text[255];
    struct mesaj *next;

}mesaj;
typedef struct planificator{
    int prioritate;
    struct mesaj *mesaje;
    struct planificator *next;
}planificator;
mesaj *crearem(int id, int prioritate, char text[]){
    mesaj *p = (mesaj *)malloc(sizeof(mesaj));
    p->id = id;
    p->prioritate = prioritate;
    strcpy(p->text,text);
    p->next = NULL;
    return p;
}
planificator *crearep(int prioritate){
    planificator *p = (planificator *)malloc(sizeof(planificator));
    p->prioritate = prioritate;
    p->mesaje = NULL;
    p->next = NULL;
    return p;
}
planificator *adaugap(planificator *lista,planificator *p){
    if(lista == NULL) lista = p;
    else{
        planificator *q;
        for(q = lista;q->next!=NULL;q=q->next);
        q->next = p;
    }
    return lista;
}
planificator *adaugam(planificator *lista,mesaj *m){
    if(lista == NULL){
            lista = crearep(m->prioritate);
            lista->mesaje = m;
            return lista;
    }
    planificator *q;
    for(q = lista; q->next!=NULL && q->prioritate != m->prioritate;q=q->next);
        if(q->mesaje == NULL) q->mesaje = m;
        else{
        mesaj *k;
        for(k= q->mesaje;k->next!=NULL;k = k->next);
        k->next = m;
        }
        return lista;
}
void deservire(planificator *lista){
    planificator *p;mesaj *m;
    if(lista != NULL){
    for(p = lista;p!= NULL; p=p->next)
    for(m = p->mesaje;m!= NULL; m = m->next)
    printf("%s\n",m->text);
    }
}
void afisarep(planificator *lista){
    planificator *p; mesaj *m;
    for(p =lista; p!=NULL;p = p->next){ printf("%d ",p->prioritate);
        for(m = p->mesaje;m!=NULL;m = m->next) printf("%s\n",m->text);
    }
}
int main()
{
    planificator *lista = NULL;
    planificator *p  = crearep(1);
    lista = adaugap(lista,p);
    mesaj *m = crearem(0,1,"asd");
    lista = adaugam(lista,m);
    m = crearem(0,1,"rav");
    lista = adaugam(lista,m);
    p  = crearep(2);
    lista = adaugap(lista,p);
    m = crearem(0,2,"fds");
    lista = adaugam(lista,m);
    m = crearem(0,2,"fre");
    lista = adaugam(lista,m);
    afisarep(lista);
}
