#include <stdio.h>
#include <stdlib.h>
struct Nod {
    int cheie;
    struct Nod *stang, *drept;
};
struct Nod *radacina,*r2;
struct Nod *adauga(int cheie,struct Nod *r){
    if(r == NULL){
        struct Nod *aux = (struct Nod*)malloc(sizeof(struct Nod));
        aux->cheie = cheie;
        aux->stang = NULL;
        aux->drept = NULL;
        r = aux;
    }
    else{
        if(r->cheie>cheie) r->stang = adauga(cheie,r->stang);
        else r->drept = adauga(cheie,r->drept);
    }
    return r;
}
void postordine(struct Nod *r){
    if(r != NULL){
        postordine(r->stang);
        postordine(r->drept);
        printf("%d ",r->cheie);
    }
}
void inordine(struct Nod *r){
    if(r != NULL){
        inordine(r->stang);
        printf("%d ",r->cheie);
        inordine(r->drept);
    }
}

void preordine(struct Nod *r){
    if(r != NULL){
        printf("%d ",r->cheie);
        preordine(r->stang);
        preordine(r->drept);
    }
}
int intre(struct Nod *r,int count,int k1,int k2){
    if(r != NULL){
        if(r->cheie>k1 && r->cheie<k2) count++;
        count = intre(r->stang,count,k1,k2);
        count = intre(r->drept,count,k1,k2);
    }
    return count;
}
int cauta(int cheie){
    struct Nod *p = radacina;
    while(p!=NULL){
        if(p->cheie == cheie) return 1;
        if(p->cheie>cheie) p = p->stang;
        else p = p->drept;
    }
    return 0;
}
struct Nod *suprima(int cheie,struct Nod *r){
    if(r == NULL) return r;
    if(r->cheie>cheie) r->stang = suprima(cheie,r->stang);
    else if(r->cheie<cheie) r->drept = suprima(cheie,r->drept);
    else{
        if(r->stang == NULL){
            struct Nod *temp = r->drept;
            free(r);
            return temp;
        }
        else if(r->drept == NULL){
            struct Nod *temp = r->stang;
            free(r);
            return temp;
        }
        struct Nod *temp;
        temp = r->drept;
        while(temp && temp->stang != NULL) temp = temp->stang;
        r->cheie = temp->cheie;
        r->drept = suprima(temp->cheie,r->drept);
    }
    return r;
}
int aceeasi_forma(struct Nod *a, struct Nod *b){
    if(a == NULL && b == NULL) return 1;
    else if(a !=NULL && b!=NULL){
        if(aceeasi_forma(a->stang,b->stang) && aceeasi_forma(a->drept,b->drept)) return 1;
    }
    else return 0;
}
int cmm(){
    struct Nod *p = radacina;
    if(p == NULL) return -1;
    else{
        while(p && p->stang != NULL){
            p = p->stang;
        }
    }
    return p->cheie;
}
int inaltime(struct Nod *r){
    if(r == NULL) return 0;
    else{
        if(inaltime(r->stang)>inaltime(r->drept)) return inaltime(r->stang)+1;
        else return inaltime(r->drept)+1;
    }
}
void printNivel(struct Nod *r,int nivel){
    if(r == NULL) return;
    if(nivel == 1) printf("%d ",r->cheie);
    else if(nivel>1){
        printNivel(r->stang,nivel-1);
        printNivel(r->drept,nivel-1);
    }
}
void afisare_nivel(struct Nod *r){
    int h = inaltime(r);
    for(int i = 1;i<=h;i++){
        printNivel(r,i);
        printf("\n");
    }
}
void oglinda(struct Nod *r){
    if(r == NULL) return;
    else{
        struct Node *aux;
        oglinda(r->stang);
        oglinda(r->drept);
        aux = r->stang;
        r->stang = r->drept;
        r->drept = aux;
    }
}
struct Nod *simm(struct Nod *r){
    struct Nod *p = r;
    oglinda(p);
    return p;
}
int stramos(struct Nod *r,int k){
    if(r!=NULL){
        stramos(r->drept,k);
        stramos(r->stang,k);
        if(r->cheie == k) return 1;
    }
    return 0;
}
void relatii(int k1, int k2){
    struct Nod *p = radacina;
    while(p && p->cheie !=k1){
        if(p->cheie == k1) break;
        if(p->cheie>k1) p = p->stang;
        else p = p->drept;
    }
    if(p!=NULL) if(stramos(p,k2)) printf("%d e stramos pentru %d",k1,k2);
    p = radacina;
    while(p && p->cheie != k2){
        if(p->cheie == k2) break;
        if(p->cheie>k2) p = p->stang;
        else p = p->drept;
    }
    if(p!=NULL) if(stramos(p,k1))  printf("%d e stramos pentru %d",k2,k1);
}
int main()
{

    radacina  = adauga(5,radacina);
    radacina  = adauga(7,radacina);
    radacina  = adauga(4,radacina);
    radacina  = adauga(6,radacina);
    radacina  = adauga(8,radacina);
    radacina  = adauga(2,radacina);
    radacina  = adauga(1,radacina);
    radacina  = adauga(3,radacina);
    r2 = adauga(6,r2);
    r2  = adauga(8,r2);
    r2  = adauga(5,r2);
    r2  = adauga(7,r2);
    r2  = adauga(9,r2);
    r2  = adauga(3,r2);
    r2  = adauga(2,r2);
    r2  = adauga(4,r2);
    inordine(radacina); printf("\n");
    //printf("%d\n",cauta(2));
    //printf("%d\n",cauta(12));
    //radacina = suprima(1,radacina);
    //inordine(radacina); printf("\n");
    printf("%d\n",aceeasi_forma(radacina,r2));
    //printf("%d\n",cmm());
    //printf("%d\n",intre(radacina,0,3,7));
    //printf("%d\n",inaltime(radacina)); printf("\n\n");
    //afisare_nivel(radacina);
    inordine(simm(radacina));
    relatii(5,3);
    FILE *f;
    f = fopen("ana.txt","r");
    while(!feof(f)){
        fscanf(f,"%d",&aux);

    }
}
