#include<stdlib.h>
#include<stdio.h>

int const PF[11] = { 1, 5, -1, 8, 9, 7, -1, -1, -1, -1, -1 };
int const FD[11] = { -1, 2, 3, 4, -1, -1, -1, 6, -1, 10, -1 };

void pre(int R)
{
	printf("%d ", R);
	if (PF[R] != -1)
		pre(PF[R]);
	int fd = FD[PF[R]];
	while (fd != -1)
	{
		pre(fd);
		fd = FD[fd];
	}
}

void post(int R)
{
	if (PF[R] != -1)
		post(PF[R]);
	int fd = FD[PF[R]];
	while (fd != -1)
	{
		post(fd);
		fd = FD[fd];
	}
	printf("%d ", R);
}

void in(int R)
{
	if (PF[R] != -1)
		in(PF[R]);
	int fd = FD[PF[R]];
	printf("%d ", R);
	while (fd != -1)
	{
		post(fd);
		fd = FD[fd];
	}

}
int main()
{
	printf("Arborele parcurs in preordine este ");
	pre(0);
	printf("\nArborele parcurs in postordine este ");
	post(0);
	printf("\nArborele parcurs in inordine este ");
	in(0);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10;

int P[] = { -1, 1, 1, 1, 2, 3, 3, 4, 8, 8 };

void afisarePreOrdine(int Root){
	int i;
	printf("%d ", Root);
	for (i = 0; i < 10; i++){
		if (P[i] == Root)
			afisarePreOrdine(i+1);
	}
}

void afisareInordine(int Root){
	int i;
	for (i = 0; i < 10; i++)
		if (P[i] == Root){

			afisareInordine(i + 1);
			break;
		}
		
	printf("%d ", Root);
	for (i = i+1; i < 10; i++)
		if (P[i] == Root)
			afisareInordine(i + 1);

}

void afisarePostordine(int Root){
	int i;
	for (i = 0; i < 10; i++){
		if (P[i] == Root)
			afisarePostordine(i+1);
	}
	printf("%d ", Root);
}

int main(){
	printf("\nPreordine:\n");
	afisarePreOrdine(1);
	printf("\n");
	printf("\nPostodrine:\n");
	afisarePostordine(1);
	printf("\n");
	printf("\nInordine:\n");
	afisareInordine(1);
	getch();
	getch();
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct nod {
	int cheie, PF, FD;
}nod;

nod arbore[100];
int n = 11;

void nr_frati_dreapta(int cheita)
{
	int i, index, nr = 0;
	for (i = 0; i < n; i++)
	{
		if (arbore[i].cheie == cheita)
		{
			if (arbore[i].FD == -1)
				printf("-1");
			else
			{
				index = i;
				while (arbore[index].FD != -1)
				{
					index = arbore[index].FD;
					nr++;
				}
			}
		}
	}
	printf("Numarul de frati din dreapta: %d", nr);
}

void cel_mai_din_dreapta(int cheita)
{
	int i, index;
	for (i = 0; i < n; i++)
	{
		if (arbore[i].cheie == cheita)
		{
			if (arbore[i].FD == -1)
				printf("-1");
			else
			{
				index = i;
				while (arbore[index].FD != -1)
				{
					index = arbore[index].FD;
				}
			}
		}
	}
	printf("Cel mai din dreapta frate: %d", arbore[index].cheie);
}

int main()
{
	int i;
	FILE *fisier;
	fisier = fopen("arbore.txt", "r");
	for (i = 0; i < n; i++)
		fscanf(fisier, "%d", &arbore[i].cheie);
	for (i = 0; i < n; i++)
		fscanf(fisier, "%d", &arbore[i].PF);
	for (i = 0; i < n; i++)
		fscanf(fisier, "%d", &arbore[i].FD);
	for (i = 0; i < n; i++)
		printf("%d ", arbore[i].cheie);
	nr_frati_dreapta(14);
	cel_mai_din_dreapta(14);
	return 0;
}
