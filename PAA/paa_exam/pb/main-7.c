#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define SIZE 5

typedef struct masina{
	char* numar_inmatriculare;
	struct masina *urm;
}m;

typedef struct parc_auto{

	int id;
	m*varf;
}p;

typedef struct lista{

	p tab[SIZE];
}lista;

lista l;
int fata = -1;
int spate = -1;

void adaugare_parc(int id)
{
	if (spate == SIZE)
		printf("\n Categoria e plina!");
	else
	{
		if (fata == -1)
			fata = 0;
		spate++;
		l.tab[spate].id = id;
		printf("\n Am inserat parcul auto cu id-ul -> %d", l.tab[spate].id);
	}
}

void initializare_varf(){

	int i;
	for (i = fata; i <= spate; i++)
		l.tab[i].varf = NULL;
}


void adaugare_masina(int id,char *numar)
{
	m *p;
	int i;
	int poz;
	
	p=(m*)malloc(sizeof(m));
	p->numar_inmatriculare = (char *)malloc(strlen(numar) + 1);
	strcpy(p->numar_inmatriculare, numar);
	for (i = fata; i <= spate; i++)
	if (l.tab[i].id == id)
	{
		poz = i;
	}
	p->urm = l.tab[poz].varf;
	l.tab[poz].varf = p;

}

void scoatere_masina(int id)
{
	m *p;
	int poz;
	int i;

	for (i = fata; i <= spate;i++)
	if (l.tab[i].id == id)
	{
		poz = i;
	}
	if (l.tab[poz].varf != NULL)
	{
		p = l.tab[poz].varf;
		l.tab[poz].varf = l.tab[poz].varf->urm;
	}
		else
		{
			printf("Nu avem nimic in stiva!");
		}

	
}

void afisare()
{
	m *p;
	int i;
	for (i = fata; i <= spate; i++)
	{
		printf("\n Parc auto: %d", l.tab[i].id);
		for (p = l.tab[i].varf; p != NULL; p = p->urm)
			printf("\n %s", p->numar_inmatriculare);
	}
}

int main()
{

	adaugare_parc(1);
	adaugare_parc(2);
	adaugare_parc(3);

	adaugare_masina(1, "CS97BIA");
	adaugare_masina(1, "TM86BLA");

	adaugare_masina(2, "CS87ANA");
	adaugare_masina(2, "CS65KIT");
	adaugare_masina(2, "CS98NOI");

	adaugare_masina(3, "TM09BLA");
	afisare();
	printf("\n");

	scoatere_masina(1);
	scoatere_masina(2);
	afisare();
	
	
	return 0;
}
