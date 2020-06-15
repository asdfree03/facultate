#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Nod {
    int numar_matricol;
    int an;

    struct Pagina* p;
};

struct Pagina {
    int m;
    struct Pagina *p0;
    struct Nod e[SIZE];
};

//teoretic asta e, practic sa luam 5
int nrmat(struct Pagina *pag, int nr) {
    if(pag == NULL) return -1;

    nrmat(pag->p0, nr);

    for(int i = 1; i < pag->m; i++) {
        if(pag->e[i].numar_matricol == nr) {
            if(i == 1) {
                printf("Pagina nu are un numar matricol mai mic decat cel dat");
                exit(EXIT_FAILURE);
            }

            return pag->e[i-1].numar_matricol;
        }

        nrmat(pag->e[i].p, nr);
    }

    return -1;
}


int main() {



    return 0;
}