#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Nod{
    char nume[30];
    char prenume[30];
    int nota;
    struct Nod *st,*dr;
}Nod;
Nod *r;
Nod *crearen(char nume[], char prenume[], int nota){
    Nod *aux = (Nod *)malloc(sizeof(Nod));
    strcpy(aux->nume,nume);
    strcpy(aux->prenume,prenume);
    aux->nota = nota;
    aux->st = NULL;
    aux->dr = NULL;
    return aux;
}
void adaugare(Nod *p){
    if(r==NULL){
        r = p;
    }
    else{
        Nod *temp = r;
        while(temp){
            if(temp->nota>p->nota){
                if(temp->st != NULL) temp = temp->st;
                else break;
            }
            else{
                if(temp->dr != NULL) temp = temp->dr;
                else break;
            }
        }
                    if(temp->nota > p->nota) temp->st = p;
            else temp->dr = p;
    }
}
Nod *predecesor(Nod *p){
    if(r!=NULL){
        Nod *temp = r;
        Nod *pred = r;
        while(temp){
            if(temp->nota > p->nota){
                    if(temp->st != NULL){
                        pred = temp;
                        temp = temp->st;
                    }
                    else break;
            }
            else if(temp->nota < p->nota){
                    if(temp->dr!= NULL){
                        pred = temp;
                        temp = temp->dr;
                    }
                    else break;
            }
            else if(temp->nota == p->nota){
                return pred;
            }
        }
    }
    return 0;
}
void afisare(Nod *n){
    printf("%s %s %d\n",n->nume,n->prenume,n->nota);
}
int main()
{
    Nod *n; Nod *m;
    n = crearen("ana", "maria", 7);
    adaugare(n);
        m=n;
    n = crearen("vasea", "maria", 8);
    adaugare(n);
    n = crearen("grisa", "maria", 9);
    adaugare(n);
    n = crearen("enakentii", "maria", 10);
    adaugare(n);
    afisare(predecesor(m));
}
