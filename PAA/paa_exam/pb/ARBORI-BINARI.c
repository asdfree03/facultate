#include<stdio.h>
#include<stdlib.h>

int n = 7, i;
int vector[7] = { 5, 2, 7, 4, 6, 10, 3 };

typedef struct nod {
	int cheie;
	struct nod *st;
	struct nod *dr;
} nod;

nod *radacina;

nod* creeaza(int info)
{
	nod *nou = NULL;
	nou = (nod*)malloc(sizeof(nod));
	nou->cheie = info;
	nou->dr = NULL;
	nou->st = NULL;
	return nou;
}

void insereaza(int info, nod** radacina)
{
	if ((*radacina) == NULL)
	    *radacina = creeaza(info);
	else
	{
		if (info < (*radacina)->cheie)
			insereaza(info, &((*radacina)->st));
		else
			insereaza(info, &((*radacina)->dr));
	}
}

void preordine(nod* radacina)
{
	if (radacina != NULL)
	{
		printf("%d ", radacina->cheie);
		preordine(radacina->st);
		preordine(radacina->dr);
	}
}

void inordine(nod* radacina)
{
	if (radacina != NULL)
	{
		inordine(radacina->st);
		printf("%d ", radacina->cheie);
		inordine(radacina->dr);
	}
}

void postordine(nod* radacina)
{
	if (radacina != NULL)
	{
		postordine(radacina->st);
		postordine(radacina->dr);
		printf("%d ", radacina->cheie);
	}
}

nod* cautare(nod* radacina, int key)
{
    if (radacina == NULL || radacina->cheie == key)
       return radacina;
    if (radacina->cheie < key)
       return cautare(radacina->dr, key);
    else
    return cautare(radacina->st, key);
}

/*int cautare(nod* radacina, int key)
{
    if(radacina == NULL)
        return 0;
    else
    {
        if(radacina->cheie == key)
            return 1;
        else
        {
            if(key < radacina->cheie)
                return cautare(radacina->st, key);
            else
                return cautare(radacina->dr, key);
        }
    }
}*/

nod *nod_minim(nod* radacina)
{
    nod* curent = radacina;
    while (curent->st != NULL)
        curent = curent->st;
    return curent;
}

nod* stergere(nod* radacina, int key)
{
    if (radacina == NULL)
        return radacina;

    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < radacina->cheie)
        radacina->st = stergere(radacina->st, key);

    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > radacina->cheie)
        radacina->dr = stergere(radacina->dr, key);

    else
    {
        // node with only one child or no child
        if (radacina->st == NULL)
        {
            nod *temp = radacina->dr;
            free(radacina);
            return temp;
        }
        else if (radacina->dr == NULL)
        {
            nod *temp = radacina->st;
            free(radacina);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest in the right subtree)
        nod* temp = nod_minim(radacina->dr);

        // Copy the inorder successor's content to this node
        radacina->cheie = temp->cheie;

        // Delete the inorder successor
        radacina->dr = stergere(radacina->dr, temp->cheie);
    }
    return radacina;
}

int maxim(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int inaltime(nod* radacina)
{
    if(radacina == NULL)
        return 0;
    else
        return 1 + maxim(inaltime(radacina->st), inaltime(radacina->dr));

}

int valoare_minima(nod* radacina)
{
    nod* curent = radacina;
    while (curent->st != NULL)
        curent = curent->st;
    return(curent->cheie);
}

int valoare_maxima(nod* radacina)
{
    nod* curent = radacina;
    while (curent->dr != NULL)
        curent = curent->dr;
    return(curent->cheie);
}

void stramos(nod *radacina, int cheie1, int cheie2)
{
	nod *n,*m;
	n = cautare(radacina, cheie1);
	if (n != NULL)
	{
		m = cautare(n, cheie2);
		if (m != NULL)
			printf("\n%d este descendent al stramosului %d", cheie2, cheie1);
		else
			printf("\n%d nu este descendent al stramosului %d", cheie2, cheie1);
	}
	else
		printf("\nNu am cheie!");
}

int pre = -1;

int predecesor(nod* radacina, int n)
{
		if (radacina)
		{
			if (radacina->cheie == n)
			{
				// go to the right most element in the left subtree, it will the predecessor
				if (radacina->st !=NULL)
				{
					nod* temp = radacina->st;
					while (temp->dr != NULL)
						temp = temp->dr;
					pre = temp->cheie;
				}
			}
			else if (radacina->cheie > n)
			{
				// we make the root as successor because we might have a
				// situation when value matches with the root, it wont have
				// right subtree to find the successor, in that case we need
				// parent to be the successor
				if(radacina->st !=NULL)
					predecesor(radacina->st, n);
			}
			else if (radacina->cheie < n)
			{
				// we make the root as predecessor because we might have a
				// situation when value matches with the root, it wont have
				// right subtree to find the predecessor, in that case we need
				// parent to be the predecessor.
				pre = radacina->cheie;
			    if(radacina->dr!=NULL)
					predecesor(radacina->dr,n);
			}
		}
    return pre;
}

int suc = -1;

int succesor(nod * radacina, int n)
{
		if (radacina)
		{
			if (radacina->cheie == n)
			{
				if (radacina->dr !=NULL)
				{
					// go to the left most element in the right subtree, it will the successor
					nod* temp = radacina->dr;
					while (temp->st != NULL)
						temp = temp->st;
				    suc = temp->cheie;
				}
			}
		    else if (radacina->cheie > n)
			{
				// we make the root as successor because we might have a
				// situation when value matches with the root, it wont have
				// right subtree to find the successor, in that case we need
				// parent to be the successor
			    suc = radacina->cheie;
				if(radacina->st !=NULL)
					succesor(radacina->st, n);
			}
			else if (radacina->cheie < n)
		    {
				// we make the root as predecessor because we might have a
				// situation when value matches with the root, it wont have
				// right subtree to find the predecessor, in that case we need
				// parent to be the predecessor.
			    if(radacina->dr!=NULL)
					succesor(radacina->dr,n);
			}
		}
    return suc;
}

void interval(nod *radacina, int k1, int k2)
{
	if(radacina==NULL)
		return;
	if(radacina->cheie > k1)
		interval(radacina->st, k1, k2);
	if((radacina->cheie >=k1) && (radacina->cheie <=k2))
		printf("%d ",radacina->cheie);
	if(radacina->cheie < k2)
		interval(radacina->dr, k1, k2);
}

void mai_mari(nod *radacina, int nr)
{
    if(radacina==NULL)
		return;
	if(radacina->cheie >= nr)
	{
	    printf("%d ",radacina->cheie);
	    mai_mari(radacina->st, nr);
	}
    mai_mari(radacina->dr, nr);
}

void mai_mici(nod *radacina, int nr)
{
    if(radacina==NULL)
		return;
	if(radacina->cheie <= nr)
	{
	    printf("%d ",radacina->cheie);
	    mai_mici(radacina->dr, nr);
	}
    mai_mici(radacina->st, nr);
}

int verif_geom(nod* a, nod* b)
{
    if (a==NULL && b==NULL)
		return 1;
    if (a!=NULL && b!=NULL)
    {
        if(verif_geom(a->st, b->st) && verif_geom(a->dr, b->dr))
        	return 1;
    }
    return 0;
}

int simetrie(nod* stanga, nod* dreapta)
{
    if (stanga==NULL && dreapta==NULL)
		return 1;
    if (stanga!=NULL && dreapta!=NULL)
    {
        if(simetrie(stanga->st, dreapta->dr) && simetrie(stanga->dr, dreapta->st))
        	return 1;
    }
    return 0;
}

int main()
{
    // INITIALIZARE
    nod *arbore = NULL;
	for (i = 0; i < 7; i++)
		insereaza(vector[i], &arbore);

	// AFISARI
	printf("\nPreordine: ");
	preordine(arbore);
	printf("\nInordine: ");
    inordine(arbore);
	printf("\nPostordine: ");
    postordine(arbore);

    // CAUTARE
    nod *nou = NULL;
    nou = cautare(arbore, 2);
    if(nou != NULL)
        printf("\nGasit!");
    else
        printf("\nNegasit!");

    // MINIM SI MAXIM
    printf("\nMinimul este: %d", valoare_minima(arbore));
    printf("\nMaximul este: %d", valoare_maxima(arbore));

    // STERGERE
    printf("\nArborele dupa stergere este: ");
    arbore = stergere(arbore, 5);
    inordine(arbore);

    // INALTIME
    printf("\nInaltimea arborelui este: %d", inaltime(arbore));

    // STRAMOS
    stramos(arbore, 6, 3);

    // PREDECESOR SI SUCCESOR
    printf("\nPredecesorul este: %d", predecesor(arbore, 10));
    printf("\nSuccesorul este: %d", succesor(arbore, 3));

    // INTERVAL
    printf("\nCheile din intervalul dat: ");
    interval(arbore,2,7);

    // MAI MARI
    printf("\nCheile mai mari sau egale ca numarul dat: ");
    mai_mari(arbore, 4);

    // MAI MICI
    printf("\nCheile mai mici sau egale ca numarul dat: ");
    mai_mici(arbore, 7);

    // SIMETRIE
    if(simetrie(arbore->st, arbore->dr))
        printf("\nJumatatea stanga si jumatatea dreapta sunt simetrice!");
    else
        printf("\nJumatatea stanga si jumatatea dreapta nu sunt simetrice!");

    return 0;
}


