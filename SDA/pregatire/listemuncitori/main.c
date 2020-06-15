#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct membru{
    char cod[100];
}membru;
typedef struct echipa{
    int id;
    int dimensiune;
    struct echipa *next;
    struct membru membri[100];
    int varf;
}echipa;
echipa *creare(int id,int dimensiune){
    echipa *p = (echipa *)malloc(sizeof(echipa));
    p->id = id;
    p->dimensiune = dimensiune;
    p->next = NULL;
    p->varf = -1;
    return p;
}
echipa *adaugae(echipa *lista, echipa *e){
    if(lista == NULL) lista = e;
    else{
        echipa *p;
        for(p = lista;p->next!=NULL;p=p->next);
        p->next = e;
    }
    return lista;
}
echipa *adaugam(echipa *lista,int id,char cod[]){
    echipa *p;
    for(p = lista;p->next!=NULL && p->id != id;p = p->next);
    if(p->id == id){
        if(p->varf == p->dimensiune) return lista;
        else{
            p->varf++;
            strcpy(p->membri[p->varf].cod,cod);
        }
    }
    return lista;
}
void afisare(echipa *lista){
    echipa *p;
    for(p = lista;p != NULL; p = p->next){
        printf("%d %d ",p->id,p->dimensiune);
        for(int i = 0;i<p->varf;i++) printf("\n%s",p->membri[i].cod);
        printf("\n\n");
    }
}
int main()
{
   echipa *lista = NULL;
   echipa *e = creare(0,2);
   lista = adaugae(lista,e);
   e = creare(1,1);
   lista = adaugae(lista,e);
   lista = adaugam(lista,0,"asd1");
   lista = adaugam(lista,0,"asd2");
   lista = adaugam(lista,0,"asd3");
   lista = adaugam(lista,1,"asd4");
   lista = adaugam(lista,1,"asd5");
   lista = adaugam(lista,1,"asd6");
   afisare(lista);
}
