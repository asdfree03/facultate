#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArboreRegasire.h"

#define SIZE 27


NodArboreDeRegasire *nod;

void AfisareCuvant(NodArboreDeRegasire *nod) {
    if (nod == NULL) return;

    for (int i = 0; i < SIZE; i++) {
        if (nod->alfabet[i] != NULL) {
            if ('A' + i == '[') {
                printf("\n");
                return;
            }

            printf("%c", 'A' + i);

            AfisareCuvant(nod->alfabet[i]);
        }
    }
}

NodArboreDeRegasire *CautareCuvant(NodArboreDeRegasire *radacina, char *cuvant) {
    if(cuvant == NULL || strcmp(cuvant, "") == 0) {
        return radacina;
    }

    char c = cuvant[0];

    NodArboreDeRegasire *n = radacina->alfabet[c + 'A'];
    if (n != NULL) {
        strcpy(cuvant, cuvant + 1);
        return CautareCuvant(n, cuvant);
    }

    return NULL;
}

NodArboreDeRegasire *AdaugaCuvant(NodArboreDeRegasire *radacina, char *cuvant, char *adaugat) {
    size_t len = strlen(cuvant);
    if (cuvant == NULL || len == 0) {
        char c = '[' - 'A';
        NodArboreDeRegasire *n = (NodArboreDeRegasire *) malloc(sizeof(NodArboreDeRegasire));
        Initializare(n);
        radacina->alfabet[c] = n;
        return n;
    };

    char cc = cuvant[0];
    char c = cuvant[0] - 'A';
    int x = c;

    NodArboreDeRegasire *n = (NodArboreDeRegasire *) malloc(sizeof(NodArboreDeRegasire));
    Initializare(n);
    radacina->alfabet[c] = n;

    adaugat[strlen(adaugat)] = cuvant[0];
    adaugat[strlen(adaugat)] = 0;
    return AdaugaCuvant(n, cuvant + 1, adaugat);
}

char *Sugestie(NodArboreDeRegasire *radacina, char* cuvantOriginal, char *cuvant, char *acumulator) {
    if(strlen(cuvant) == 0) return acumulator;

    char cc = cuvant[0];
    char c = cc - 'A';
    int x = c;

    char aux[100];
    strcpy(aux, acumulator);

    if(radacina->alfabet[c]) {
        acumulator[strlen(acumulator)] = cuvant[0];
        acumulator[strlen(acumulator)] = 0;
        return Sugestie(radacina->alfabet[c], cuvantOriginal, cuvant + 1, acumulator);
    } else {
        for(int i = 0; i < SIZE; i++) {
            if(radacina->alfabet[i] && radacina->alfabet[i]->alfabet[c]) {
                acumulator[strlen(acumulator)] = 'A' + i;
                acumulator[strlen(acumulator)] = 0;

                char *dd = Sugestie(radacina->alfabet[i], cuvantOriginal, cuvant, acumulator);

                int greseli = 1;
                for(int j = 0, k = 0; j < strlen(dd); j++, k++) {
                    if(dd[j] != cuvantOriginal[k]) {
                        greseli--;
                        k--;
                        if(greseli < 0) {
                            break;
                        }
                    };
                }

                return dd;
            }
        }
    }
}

int main() {
    nod = (NodArboreDeRegasire *) malloc(sizeof(NodArboreDeRegasire));
    Initializare(nod);

    char adaugat[100] = "";

    char cuvant[100] = "COMPUTER";

    AdaugaCuvant(nod, cuvant, adaugat);

    char cauatat[100] = "COMUTER";
    char *cuvantOriginal = strdup(cauatat);
    char acc[100] = "";

    char *cvt = Sugestie(nod, cuvantOriginal, cauatat, acc);
    printf("Ati dorit sa scrieti %s?", cvt);

    return 0;
}