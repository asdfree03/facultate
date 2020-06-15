//Rat

#include <stdio.h>
#include <stdlib.h>

#define NumarNoduri	26

int nr_noduri;
int componente;

typedef struct Nod {
	char cheie;
	// char info;
}Nod;

Nod vector_elem[NumarNoduri];
int tablou_adiacenta[NumarNoduri][NumarNoduri];
int marc[NumarNoduri];
void atribuie()
{
	char c = 'A';
	int i;
	for (i = 0; i < NumarNoduri; i++)
	{
		vector_elem[i].cheie = c++;
		// printf("\nLa poz %d avem litera %c", i, c-1);
	}
}

void afisare_tablou_adiacenta(int nr_noduri)
{
	int i, j;
	for (i = 0; i < nr_noduri; i++)
	{
		for (j = 0; j < nr_noduri; j++)
			printf("%d ", tablou_adiacenta[i][j]);
		printf("\n");
	}
}

void CautaInAdancime(int x)
{
	/*se parcurg toate nodurile din aceeasi componenta
	conexa cu x  prin cautare in adancime*/
	int y;
	if (marc[x] == 0)
		printf("Am vizitat nodul %c\n", vector_elem[x].cheie);
	marc[x] = 1; //vizitat
	for (y = 0; y < nr_noduri; y++)
		if (tablou_adiacenta[x][y] == 1)
			if (marc[y] == 0) //nevizitat
				CautaInAdancime(y);
}

void TraversareInAdancime()
{
	int x;

	for (x = 0; x < nr_noduri; x++)
		marc[x] = 0; //nevizitat

	for (x = 0; x < nr_noduri; x++)
	if (marc[x] == 0) //nevizitat
	{
		printf("Componenta %d:\n", componente+1);
		CautaInAdancime(x);
		componente++;
	}
}

int main()
{
	FILE *f;
	f = fopen("fisier.txt", "r");

	fscanf(f, "%d", &nr_noduri);

	atribuie();

	int i, p1, p2;
	char intrare[7];
	while (fscanf(f, "%s", &intrare) != EOF)
	{
		// intrare[1], intrare[3]
		for (i = 0; i < nr_noduri; i++)
		{
			if (vector_elem[i].cheie == intrare[1])
			{
				p1 = i;
				// printf("Am gasit litera %c la poz %d\n", intrare[1], p1);
			}
		}

		for (i = 0; i < nr_noduri; i++)
		{
			if (vector_elem[i].cheie == intrare[3])
			{
				p2 = i;
				// printf("Am gasit litera %c la poz %d\n", intrare[3], p2);
			}
		}

		printf("Se face legatura dintre %c si %c\n", vector_elem[p1].cheie, vector_elem[p2].cheie);
		tablou_adiacenta[p1][p2] = 1;
		tablou_adiacenta[p2][p1] = 1;
	}
	afisare_tablou_adiacenta(nr_noduri);

	TraversareInAdancime();
	printf("Numar de componente conexe: %d\n", componente);

	return 0;
}

//Raul

#include <stdio.h>

typedef struct {
	char cheie;
} Nod ;


typedef struct Graf {
	int Contor;
	Nod Noduri[10];
	int  Matrice[10][10];
} Graf;

Graf g;
int N;
int Index(char  cheie)
{
	int i = 0; int j = 0;

		for (i = 0; i < 10; i++)
		{
			if ((g.Noduri[i].cheie) == cheie)
				return i;
		}
	
}

void InserNod( char  e)
{
	int  i;

	g.Contor++;
	//se adauga elementul e in noul nod
	g.Noduri[g.Contor].cheie = e;
	//se initializeaza matricea de adiacenta pentru noul nod
	for (i = 0; i < g.Contor; i++)
	{
		g.Matrice[i][g.Contor] = 0;
		g.Matrice[g.Contor][i] = 0;
	}
}

void InserArc(char* A , char* B)
{
	g.Matrice[Index(A)][Index(B)] = 1;
	g.Matrice [Index(B)][Index(A)] = 1;
}


int main()
{
	FILE* f;
	f = fopen("fix.txt", "r");
	char c[5];
	int i; int j;
	if (f)
	{
		fscanf(f, "%d\n", &N);
		g.Contor = 0;
		for (i = 0; i < N; i++)
		{
			InserNod('A'+i);
		}

		while (!feof(f))
		{
			fgets(c, 5, f);
			//InserNod(g, c[0]);
			//InserNod(g, c[2]);
			InserArc(c[0],c[2]);
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d", g.Matrice[i][j]);
		}
		printf("\n");
	}
}

//Alta varianta

#include<stdio.h>
#include<conio.h>
#define max 20
int adj[max][max];
int n;
main() {
    int choice;
    int node, origin, destin;
    create_graph();
    while (1) {
        printf("1.Insert a node\n");
        printf("2.Delete a node\n");
        printf("3.Dispaly\n");
        printf("4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insert_node();
            break;
        case 2:
            printf("Enter a node to be deleted : ");
            fflush(stdin);
            scanf("%d", &node);
            delete_node(node);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice\n");
            break;
        }
    }
    getch();
}
 
create_graph() {
    int i, max_edges, origin, destin;
 
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    max_edges = n * (n - 1);
 
    for (i = 1; i <= max_edges; i++) {
        printf("Enter edge %d( 0 0 ) to quit : ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == 0) && (destin == 0))
            break;
        if (origin > n || destin > n || origin <= 0 || destin <= 0) {
            printf("Invalid edge!\n");
            i--;
        } else
            adj[origin][destin] = 1;
    }
}
 
display() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}
 
insert_node() {
    int i;
    n++;
    printf("The inserted node is %d \n", n);
    for (i = 1; i <= n; i++) {
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
}
 
void delete_node(char u) {
    int i, j;
    if (n == 0) {
        printf("Graph is empty\n");
        return;
    }
    if (u > n) {
        printf("This node is not present in the graph\n");
        return;
    }
    for (i = u; i <= n - 1; i++)
        for (j = 1; j <= n; j++) {
            adj[j][i] = adj[j][i + 1];
            adj[i][j] = adj[i + 1][j];
        }
    n--;
}

//Bogdan

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int n, m[10][10], verificat[10];

void afisare()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

void citire()
{
	FILE *f;
	int i, j;
	f = fopen("matrice.txt", "r");
	fscanf(f, "%d", &n);

	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		fscanf(f, "%d", &m[i][j]);
}

int cc = 1;//are cel putin o componenta conexa

void cir(int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (m[x][i] == 1 && verificat[i] == 0)
		{
			printf("%d ", i + 1);
			verificat[i] = 1;
		}
	
		for (i = x + 1; i < n;i++)
		if (m[x][i] == 1)
			cir(i);

		for (i = 0; i < n;i++)
		if (verificat[i] == 0)
		{
			verificat[i] = 1;
			printf("\n");
			printf("%d", i + 1);
			cc++;
		}
}

void init()
{
	int i;
	for (i = 0; i < n; i++)
		verificat[i] = 0;
}

int main()
{
	citire();
	afisare();
	init();
	printf("1 ");//pozitia de pornire, pe care o consideram ulterior verificata
	verificat[0] = 1;
	cir(0);
	printf("\n");
	printf("\nGraful are %d componente conexe\n", cc);
	return 0;
}
