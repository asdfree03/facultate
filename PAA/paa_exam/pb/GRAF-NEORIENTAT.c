#include <stdio.h>
#include <stdlib.h>

int N; //numar noduri
int k = 0;

typedef struct Nod {
	char cheie;
	int culoare;
} Nod;

Nod vector_elemente[26];
int matrice_adiacenta[26][26];
int marc[26];

void atribuire() //Initializare litere din alfabet
{
	char c = 'A';
	int i;
	for (i = 0; i < 26; i++)
	{
		vector_elemente[i].cheie = c++;
	}
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
	{
		if ((vector_elemente[i].cheie) == cheie)
			return i;
	}
}

void inserare_nod(char cheie)
{
	int  i;
	N++;
	//se adauga elementul e in noul nod
	vector_elemente[N].cheie = cheie;
	//se initializeaza matricea de adiacenta pentru noul nod
	for (i = 0; i < N; i++)
	{
		matrice_adiacenta[i][N] = 0;
		matrice_adiacenta[N][i] = 0;
	}
}

void inserare_arc(char cheie1, char cheie2)
{
    int idx1, idx2;
    idx1 = index(cheie1);
    idx2 = index(cheie2);
    matrice_adiacenta[idx1][idx2] = 1;
	matrice_adiacenta[idx2][idx1] = 1;
}

void suprimare_nod(char cheie) //Functie care sterge un nod
{
	int i, pozitie;
	pozitie = index(cheie);
	//nodul indicat este inlocuit cu ultimul nod
	vector_elemente[pozitie] = vector_elemente[N - 1]; //Sterg din vectorul de elemente
	for (i = 0; i < N; i++) //Sterg din matricea de adiacenta
	{
		matrice_adiacenta[i][pozitie] = matrice_adiacenta[i][N - 1];
		matrice_adiacenta[pozitie][i] = matrice_adiacenta[N - 1][i];
	}
	N--;
}

void CautaInAdancime(int x)
{
	/*se parcurg toate nodurile din aceeasi componenta
	conexa cu x  prin cautare in adancime*/
	int y;
	if (marc[x] == 0)
		printf("%c\n", vector_elemente[x].cheie);
	marc[x] = 1; //vizitat
	for (y = 0; y < N; y++)
	if (matrice_adiacenta[x][y] == 1)
	if (marc[y] == 0) //nevizitat
		CautaInAdancime(y);
}

void ParcurgereInAdancime()
{
	int x, comp = 0;
	for (x = 0; x < N; x++)
		marc[x] = 0; //nevizitat
	for (x = 0; x < N; x++)
	if (marc[x] == 0) //nevizitat
	{
		printf("\nComponenta %d:\n", comp + 1);
		CautaInAdancime(x);
		comp++;
	}
	printf("\nNumarul de componente conexe este: %d\n", comp);
}

void existaDrum(int i)
{
    int x;
    for (x = 0; x < N; x++)
		marc[x] = 0; //nevizitat
	CautaInAdancime(i);
	for (x = 0; x < N; x++)
		if(marc[x] == 0)
		{
		    printf("Nu s-a putut parcurge tot graful!");
		    break;
		}
}

int cod_componenta[26];
int marcat[26], componente_conexe = 0;

void determinaComponente(int x)
{
	int y;
	if (marcat[x] == 0)
	{
	    printf("%c\n", vector_elemente[x].cheie);
	    cod_componenta[x] = componente_conexe + 1;
	}
	marcat[x] = 1; //vizitat
	for (y = 0; y < N; y++)
	if (matrice_adiacenta[x][y] != 0)
		if (marcat[y] == 0) //nevizitat
			determinaComponente(y);
}

void faConex()
{
	int x, y;
	for (x = 0; x < N; x++)
		marcat[x] = 0; //nevizitat
	for (x = 0; x < N; x++)
		if (marcat[x] == 0) //nevizitat
		{
			printf("\nComponenta %d:\n", componente_conexe + 1);
			determinaComponente(x);
			componente_conexe++;
		}
	for(x = 1; x < N; x++)
	    if(cod_componenta[0] != cod_componenta[x])
	    {
	        printf("\nAdaug arc intre %c -> %c", vector_elemente[0].cheie, vector_elemente[x].cheie);
	        matrice_adiacenta[0][x] = 2;
	        matrice_adiacenta[x][0] = 2;
	        int aux = cod_componenta[x];
	        for(y = 1; y < N; y++)
	            if(cod_componenta[y] == aux )
	                cod_componenta[y] = cod_componenta[0];
	        componente_conexe--;
	    }
	 printf("\nGraful are %d elemente conexe", componente_conexe);
}

void suprima_arc(int x, int y)
{
	matrice_adiacenta[x][y] = 0;
	matrice_adiacenta[y][x] = 0;
}

int grad(char cheie)
{
	int suma = 0;
	int ind = index(cheie);
	for (int j = 0; j < N; j++)
		suma = suma + matrice_adiacenta[ind][j];
	return suma;
}

void suprimare_noduri() //Sterge toate nodurile care au gradul 0 sau 1
{
	int i, numar=0;
	for (i = 0; i < N; i++)
	if (grad(vector_elemente[i].cheie) < 2)
		numar++;
	while (numar>0)
	{
		for (i = 0; i < N; i++)
		if (grad(vector_elemente[i].cheie) < 2)
			suprimare_nod(vector_elemente[i].cheie);
		numar--;
	}
}

int ciclic()
{
	int i;
	suprimare_noduri();
	if (N == 0)
		return 0;
	for (i = 0; i < N; i++)
	if (grad(vector_elemente[i].cheie) < 2)
		return 0;
	return 1;
}

/* We do a DFS traversal of the given graph. For every visited vertex ‘v’, if there is an adjacent ‘u’
such that u is already visited and u is not parent of v, then there is a cycle in graph.
If we don’t find such an adjacent for any vertex, we say that there is no cycle. */

int visited[26];

int isCyclicUtil(int v, int parent)
{
    // Mark the current node as visited
    visited[v] = 1;

    for (int i = 0; i < N; i++)
    if(matrice_adiacenta[v][i] == 1)
    {
        if (!visited[i])  // If an adjacent is not visited, then recur for that adjacent
        {
           if (isCyclicUtil(i, v))
              return 1;
        }
        else if (i != parent) // If an adjacent is visited and not parent of current vertex, then there is a cycle
           return 1;
    }
    return 0;
}

int isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion stack
    for (int i = 0; i < N; i++)
        visited[i] = 0;
    // Call the recursive helper function to detect cycle in different DFS trees
    for (int u = 0; u < N; u++)
        if (!visited[u]) // Don't recur for u if it is already visited
          if (isCyclicUtil(u,-1))
             return 1;
    return 0;
}

void next_color(int k)
{
   int i,j;
   vector_elemente[k].culoare = 1;  //coloring vertex with color1
   for(i = 0; i < k; i++)
   { //checking all k-1 vertices-backtracking
     if(matrice_adiacenta[i][k] !=0 && vector_elemente[k].culoare==vector_elemente[i].culoare)  //if connected and has same color
       vector_elemente[k].culoare=vector_elemente[i].culoare+1;  //assign higher color than x[i]
   }
}

int main()
{
	// CITIRE DATE DIN fisier
	char elemente[26], sir[4], index1, index2;
	int i, j, k = 0;

	FILE *file;
	file= fopen("neconex.txt", "r");
	if (!file)
		printf("Eroare la deschiderea fisierului!");

    fscanf(file, "%d \n", &N); //Citesc numarul de noduri
	printf("%d \n", N);

    fgets(elemente, 26, file); //Citesc lista de noduri sub forma de sir de caractere (litere separate printr-un spatiu)
    printf("Nodurile sunt %s\n", elemente);

    for(i = 0; i < N; i++)
    {
        vector_elemente[i].cheie = elemente[k]; //Adaug nodurile citite in vectorul de elemente al grafului
        k = k+2; //Initial k = 0; literele sunt pe pozitii pare, spatiile pe pozitii impare
    }

	while (!feof(file))
	{
	    fgets(sir, 4, file); //Citesc de pe fiecare linie nodurile intre care exista arc (litere separate printr-un spatiu)
		index1 = index(sir[0]); //Aflu indicii nodurilor
		index2 = index(sir[2]);
		printf("\nArc intre %c si %c\n", vector_elemente[index1].cheie, vector_elemente[index2].cheie);
		matrice_adiacenta[index1][index2] = 1; //Marchez existenta unui arc intre cele doua noduri
		matrice_adiacenta[index2][index1] = 1;
	}

	// AFISARE
	printf("\nMatricea de adiacenta a grafului este:\n");
	afisare(N);
	ParcurgereInAdancime();

	/*// SUPRIMARE
	suprimare_nod('H');
	afisare(N);
	ParcurgereInAdancime();

	// INSERARE
	inserare_nod('H');
	afisare(N);
	//inserare_arc('A', 'H');
	ParcurgereInAdancime();*/

    // INDEX
	printf("\nNodul A are indexul: %d", index('A'));

    // GRAD
	printf("\nNodul A are gradul: %d", grad('A'));
	printf("\nNodul F are gradul: %d", grad('F'));

	// CULORI
	for(i=0;i<N;i++)
        next_color(i);  //coloring each vertex
    printf("\nColorile nodurilor: \n");
    for(i=0;i<N;i++)  //displaying color of each vertex
        printf("%c : %d\n",vector_elemente[i].cheie, vector_elemente[i].culoare);

    existaDrum(0);
    // CILIC
	//printf("\n%d", isCyclic());
	//ciclic();

	// FA CONEX
	//faConex();
	//printf("\nNumar de elemente conexe: %d", cc);
	//printf("\nMatricea de adiacenta a grafului este:\n");
	//afisare(N);

	/*ParcurgereInAdancime();

	if (ciclic())
		printf("\nGraful contine un ciclu!");
	else
		printf("\nGraful nu contine un ciclu!");*/

	return 0;
}

