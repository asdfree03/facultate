#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct elm {
    char nume[100];
    char prenume[100];
    int nota;

    struct elm *stanga;
    struct elm *dreapta;
} student;


student* predecesor(student *radacina, char *nume) {
    if(radacina == NULL) return NULL;



    int cmp = strcmp(radacina->nume, nume);
    if(cmp == 0) {
        if(radacina->stanga != NULL) {
            student *p = radacina->stanga;
            while(p->dreapta) p = p->dreapta;
            return p;
        }

        return NULL;
    } else if(cmp > 0) return predecesor(radacina->stanga, nume);
    else return predecesor(radacina->dreapta, nume);
}

student* adauga(student *radacina, char *nume, char *prenume, int nota) {
    if(radacina == NULL) {
        student *p = (student *) malloc(sizeof(student));
        strcpy(p->nume, nume);
        strcpy(p->prenume, prenume);
        p->nota = nota;
        p->stanga = NULL;
        p->dreapta = NULL;

        return p;
    }

    int cmp = strcmp(radacina->nume, nume);
    if(cmp > 0) {
        radacina->stanga = adauga(radacina->stanga, nume, prenume, nota);
    } else {
        radacina->dreapta = adauga(radacina->dreapta, nume, prenume, nota);
    }
    return radacina;
}

void afisare(student *radacina, int nivel) {
    if(radacina == NULL) return;

    afisare(radacina->stanga, nivel + 1);
    printf("%d -> %s\n", nivel, radacina->nume);
    afisare(radacina->dreapta, nivel + 1);
}

int main() {
    student *s = adauga(NULL, "Bejan", "Daniel", 5);
    s = adauga(s, "Cristian", "Munteanu", 6);
    s = adauga(s, "Agape", "Cristina", 7);
    s = adauga(s, "Arazan", "Georgiana", 8);
    s = adauga(s, "Coste", "Darius", 10);
    s = adauga(s, "Barboni", "Dorian", 9);

    afisare(s, 0);
    char *pred = "Cristian";
    student *p = predecesor(s, pred);
    if(p) {
        printf("Predecesoru lui %s este %s", pred, p->nume);
    } else {
        printf("%s nu are predecesor", pred);
    }

    return 0;
}