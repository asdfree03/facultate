#include <stdio.h>
#include <stdlib.h>

int N; //Numar noduri
int componente;

typedef struct Nod {
	char cheie;
} Nod;

Nod vector_elemente[26];
int matrice_adiacenta[26][26];
int marc[26];

void initializare() //Initializare litere din alfabet
{
	for (int i = 0; i < 26; i++)
		vector_elemente[i].cheie = 'A' + i;
}

void afisare(int N) //Afisare matrice adiacenta
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", matrice_adiacenta[i][j]);
		printf("\n");
	}
}

int index(char cheie) //Functie care returneaza indexul nodului cu cheia data
{
	for (int i = 0; i < N; i++)
		if ((vector_elemente[i].cheie) == cheie)
			return i;
}

void CautaInAdancime(int x)
{
	int y;
	if (marc[x] == 0)
		printf("%c\n", vector_elemente[x].cheie);
	marc[x] = 1; //vizitat
	for (y = 0; y < N; y++)
	if (matrice_adiacenta[x][y] != 0)
		if (marc[y] == 0) //nevizitat
			CautaInAdancime(y);
}

void ParcurgereInAdancime()
{
	int x;
	for (x = 0; x < N; x++)
		marc[x] = 0; //nevizitat
	for (x = 0; x < N; x++)
		if (marc[x] == 0) //nevizitat
		{
			printf("\nComponenta %d:\n", componente + 1);
			CautaInAdancime(x);
			componente++;
		}
}

int main()
{
	char noduri[26], sir[5], index1, index2;
	int i, k = 0, cost;

	FILE *fisier;
	fisier = fopen("fisier.txt", "r");
	if (!fisier)
		printf("Eroare la deschiderea fisierului!");

    fscanf(fisier, "%d \n", &N); //Citesc numarul de noduri
	printf("%d \n", N);

    fgets(noduri, 26, fisier); //Citesc lista de noduri sub forma de sir de caractere (litere separate printr-un spatiu)
    printf("Nodurile sunt %s\n", noduri);

    for(i=0;i<N;i++)
    {
        vector_elemente[i].cheie = noduri[k]; //Adaug nodurile citite in vectorul de elemente al grafului
        k = k+2; //Initial k = 0; literele sunt pe pozitii pare, spatiile pe pozitii impare
    }

	while (!feof(fisier))
	{
	    fgets(sir, 5, fisier); //Citesc de pe fiecare linie nodurile intre care exista arc (litere separate printr-un spatiu)
	    fscanf(fisier, "%d \n", &cost); //Citesc costul de conectare (intreg)
		index1 = index(sir[0]); //Aflu indicii nodurilor
		index2 = index(sir[2]);
		printf("\nArc intre %c si %c de cost %d\n", vector_elemente[index1].cheie, vector_elemente[index2].cheie, cost);
		matrice_adiacenta[index1][index2] = cost; //Trec costul in matricea de adiacenta, marcand existenta unui arc intre cele doua noduri
		matrice_adiacenta[index2][index1] = cost;
	}

	printf("\nMatricea de adiacenta a grafului este:\n");
	afisare(N);

	ParcurgereInAdancime();
	printf("\nNumarul de componente conexe este: %d\n", componente);

	return 0;
}



