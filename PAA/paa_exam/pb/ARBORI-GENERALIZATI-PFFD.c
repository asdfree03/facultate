3 4 7 9 1 2 12 14 16 18 22
1 4 6 7 -1 -1 -1 -1 -1 -1 -1
-1 2 3 -1 5 -1 -1 8 9 10 -1

#include<stdio.h>
#include<stdlib.h>

typedef struct nod {
	int cheie, PF, FD;
} ArboreGeneralizat;

ArboreGeneralizat arbore[100];
int n = 11;

int getCheie(int index)
{
    return arbore[index].cheie;
}

int getIndex(int key)
{
    int i;
     for(i = 0; i < n; i++)
        if(arbore[i].cheie == key)
            return i;
}

int isLeaf(int index)
{
     int i;
     for(i = 0; i < n; i++)
       if (arbore[i].PF == -1)
	        return 1;
     return 0;
}

int celMaiDinStanga(int index)
{
    int i, j;
    for(i = 0; i < n; i++) 
        if(arbore[i].FD == index) 
        {
            for(j = 0; j < n; j++)
                if(arbore[j].PF == i)
                    return i;
                else
                    celMaiDinStanga(i);
        } 
}

int celMaiDinDreapta(int key)
{
	int i;
	int index;
	int nr = 0;
	for (i = 0; i < n;i++)
		if (arbore[i].cheie == key)
		{
			if (arbore[i].FD == -1) 
				printf("Nu am frate dreapta!");
			else
			{
				index = i;
				while (arbore[index].FD != -1)
				{
					index = arbore[index].FD;
					nr++;
				}
			}
			printf("\nNumar frati dreapta %d", nr);
			printf("\nCel mai din dreapta frate: %d", arbore[index].cheie);
			return index;
	  }
}


/*int numarFrati(int index)
{
    int i;
    for(i = 0; i < n; i++)
       if (arbore[i].PF == index)
}*/

void afisare()
{
    int i;
    printf("\nIndex: ");
    for (i = 0; i < n; i++)
        printf("%d ", i);
    printf("\nCheie: ");
    for (i = 0; i < n; i++)
        printf("%d ", arbore[i].cheie);
    printf("\nPrimul fiu: ");
    for (i = 0; i < n; i++)
        printf("%d ", arbore[i].PF);
    printf("\nFrate dreapta: ");
    for (i = 0; i < n; i++)
        printf("%d ", arbore[i].FD);
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
	afisare();
	
	// FRUNZE
	if(isLeaf(4))
	    printf("\nE frunza!");
	else
	    printf("\nNu e frunza!");
	
	// CEL MAI DIN STANGA FRATE 
	printf("\n%d", getCheie(celMaiDinStanga(3)));
	celMaiDinDreapta(14);
	/*// NUMAR FRATI 
	printf("\nNodul are %d frati", numarFrati(22));*/
	
	
	return 0;
}

//BIANCA
#include <stdio.h>

struct nod {
	int cheie;
	int PF;
	int FD;
};

struct nod arbore[50];
int n = 11;


int celMaiDinDreapta(int cheie_c){
	int i;
	int index;
	int nr = 0;
	for (i = 0; i < n;i++)
		if (arbore[i].cheie == cheie_c)
		{
			if (arbore[i].FD == -1) {
				printf("nu am frate dreapta !");
		
			 }
			else
			{
				index = i;
				while (arbore[index].FD != -1)
				{
					index = arbore[index].FD;
					nr++;
				}
			}
			printf("\n Numar frati dreapta %d \n", nr);
			return index;
		//printf("Cel mai din dreapta frate: %d \n", arbore[index].cheie);
	  }
}


void insereaza(int c, int cheie_p){
	int i;
	struct nod aux;
	arbore[n].cheie = c;
	arbore[n].PF = -1;
	arbore[n].FD = -1;
	n++;
	for (i = 0; i < n;i++)
	for (i = 0; i < n; i++){
		if (arbore[i].cheie == cheie_p){
			if (arbore[i].PF == -1)
				arbore[i].PF = n-1; // adaug ca prim fiu 
			else{
				for (i = 0; i < n; i++){
					if (arbore[i].cheie == cheie_p)
						arbore[celMaiDinDreapta(arbore[arbore[i].PF].cheie)].FD=n-1;
				}
			}
		}

		}
	}

	
	
void afisare(int i)//index radacina
{
    printf("%d", arbore[i].cheie);
    if(arbore[i].FD !=-1)
        afisare(arbore[i].FD);
    afisare(arbore[i].PF);
  
}

	
int main(){
	FILE *f;
	int i;

	f = fopen("date.txt", "r");
	for (i = 0; i < n; i++){
		fscanf(f,"%d", &arbore[i].cheie);
	}
	for (i = 0; i < n; i++){
		fscanf(f,"%d", &arbore[i].PF);
	}
	for (i = 0; i < n; i++){
		fscanf(f,"%d", &arbore[i].FD);
	}
	int ind = celMaiDinDreapta(14);
	printf("Cel mai din dreapta frate: %d \n", arbore[ind].cheie);
	//celMaiDinDreapta(14);
	insereaza(30, 1);

	for (i = 0; i < n; i++)
		printf("\n%d ", arbore[i].cheie);

	insereaza(31, 4);

	for (i = 0; i < n; i++)
	  printf(" %d ", arbore[i].cheie);
	printf("\n");
	for (i = 0; i < n; i++)
		printf(" %d ", arbore[i].PF);
	printf("\n");
	for (i = 0; i < n; i++)
		printf(" %d ", arbore[i].FD);
}
