#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sublista{
    char agentie[20];
    char localitate[20];
    int pret;
}sublista;
typedef struct lista{
    char tara[20];
    struct sublista sub[20];
    int varf;
    struct lista *next;
}lista;
lista *creeazal(char tara[]){
    lista *p;
    p = (lista *)malloc(sizeof(lista));
    strcpy(p->tara,tara);
    p->next = NULL;
    p->varf = -1;
    return p;
}
lista *adaugal(lista *list,lista *p){
    lista *q;
    if(list == NULL) list = p;
    else{
        for(q = list; q->next!=NULL;q=q->next);
        q->next = p;
    }
    return list;
}
lista *adaugas(lista *list,char tara[],char agentie[],char localitate[],int pret){
    if(list == NULL) return;
    lista *q;
    for(q = list;q->next!=NULL && strcmp(q->tara,tara)!=0;q=q->next);
    q->varf++;
    strcpy(q->sub[q->varf].agentie,agentie);
    strcpy(q->sub[q->varf].localitate,localitate);
    q->sub[q->varf].pret = pret;
    return list;
}
void afisare(lista *list){
    lista *q;
    for(q=list;q != NULL; q=q->next){
        printf("%s ",q->tara);
        for(int i=0;i<=q->varf;i++){
            printf("%s %s %d",q->sub[i].agentie,q->sub[i].localitate,q->sub[i].pret);
        }
        printf("\n");
    }
}
int main()
{
    lista *list = NULL;
    lista *p = creeazal("Moldova");
    list = adaugal(list,p);
    p = creeazal("USA");
    list = adaugal(list,p);
    list = adaugas(list,"Moldova","1","Bacioi",12);
    list = adaugas(list,"Moldova","2","Bacioi",13);
    list = adaugas(list,"USA","3","Bacioi",14);
    afisare(list);
}
