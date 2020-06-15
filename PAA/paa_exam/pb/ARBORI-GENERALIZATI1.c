#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct nod {
    int key;
    int parent;
} GeneralizedTree;

GeneralizedTree Tree[SIZE];
int numberOfElements;

void deleteElementOnGivenPoistion(int position)
{
    int index;
    for(index = position + 1; index < SIZE; index++)
        Tree[index - 1] = Tree[index];
    numberOfElements--;
}

void initializeTree()
{
    int index;
    for(index = 0; index < numberOfElements; index++)
    {
        deleteElementOnGivenPoistion(index);
        index--;
    }
}

void insertRoot(int RootKey){
    if(numberOfElements != 0)
        initializeTree();
    Tree[numberOfElements].key = RootKey;
    Tree[numberOfElements].parent = -1;
    numberOfElements++;
}

void insertNode(int key, int parentKey){
    Tree[numberOfElements].key = key;
    Tree[numberOfElements].parent = parentKey;
    numberOfElements++;
}

int findKey(int key){
    int index;
    for(index = 0; index < numberOfElements; index++)
        if(Tree[index].key == key)
            return 1;
    return 0;
}

int getRootKey(){
    int index;
    for(index = 0; index < numberOfElements; index++)
        if(Tree[index].parent == -1)
            return Tree[index].key;
    return -1;
}

int getKey(int i)
{
    return Tree[i].key;
}

void listInPreorder(int Root){
    int index;
    printf("%d ", Root);
    for(index = 0; index < numberOfElements; index++)
        if(Tree[index].parent == getIndex(Root))
            listInPreorder(Tree[index].key);
}

void listInInorder(int Root){
    int index;
    for(index = 0; index < numberOfElements; index++)
        if(Tree[index].parent == getIndex(Root)){
            listInInorder(Tree[index].key);
            break;
        }
    printf("%d ", Root);
    for(index = index + 1; index < numberOfElements; index++)
        if(Tree[index].parent == getIndex(Root))
          listInInorder(Tree[index].key);
}

void listInPostorder(int Root){
    int index;
    for(index = 0; index < numberOfElements; index++)
        if(Tree[index].parent == getIndex(Root))
            listInPostorder(Tree[index].key);
    printf("%d ", Root);
}

int getParentIndex(int key){
    int index;
    for(index = 0; index < numberOfElements; index++)
        if(Tree[index].key == key)
            return Tree[index].parent;
    return -1;
}

int getLeftMostSibling(int key){
    int index;
    int parentK = getParentIndex(key);
    for(index = 0; index < numberOfElements; index++)
        if(Tree[index].parent == parentK && Tree[index].key != key)
            return Tree[index].key;
    return -1;
}

int getRightMostSibling(int key){
    int index, siblingK = -1;
    int parentK = getParentIndex(key);
    for(index = 0; index < numberOfElements; index++)
        if(Tree[index].parent == parentK && Tree[index].key != key)
            siblingK = Tree[index].key;
    if(siblingK != -1)
        return siblingK;
    else
        return -1;
}

int getNumberOfSiblings(int key){
    int count = 0, index, parentK;
    parentK = getParentIndex(key);
    for(index = 0; index < numberOfElements; index++){
        if(Tree[index].parent == parentK && Tree[index].key !=  key)
            count++;
    }
    return count;
}

int getMaximum(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int calculateHeight(int Root){
    int index, height = 0;
    for(index = 0; index < numberOfElements; index++){
        if(Tree[index].parent == getIndex(Root))
            height = getMaximum(height, 1 + calculateHeight(Tree[index].key));
    }
    return height;
}

int getIndex(int key){
    int index;
    for(index = 0; index < numberOfElements; index++)
        if(Tree[index].key == key)
            return index;
    return -1;
}

int deleteKey(int key){
    int index;
    for(index = 0; index < numberOfElements; index++)
        if(Tree[index].key == key){
            deleteElementOnGivenPoistion(getIndex(Tree[index].key));
            return 1;
        }
    return 0;
}

int isLeaf(int i)
{
     int index;
     for(index = 0; index < numberOfElements; index++)
       if (Tree[index].parent == i)
	        return 0;
     return 1;
}

int gradNode(int cheie)
{
    int index, i, k = 0;
    i = getIndex(cheie);
    for(index = 0; index < numberOfElements; index++)
        if(Tree[index].parent == i)
            k++;
    return k;
}

int gradTree()
{
    int index, cheie, max = 0;
    for(index = 0; index < numberOfElements; index++)
    {
        cheie = Tree[index].key;
        if(gradNode(cheie) > max)
            max = gradNode(cheie);
    }
    return max;
}

void afisare()
{
    int i;
    printf("\nIndex: ");
    for (i = 0; i < numberOfElements; i++)
        printf("%d ", i);
    printf("\nCheie: ");
    for (i = 0; i < numberOfElements; i++)
        printf("%d ", Tree[i].key);
    printf("\nTata: ");
    for (i = 0; i < numberOfElements; i++)
        printf("%d ", Tree[i].parent);
}

int main()
{
    // INITIALIZARE
    int i;
	FILE *fisier;
	fisier = fopen("arbore.txt", "r");
	fscanf(fisier, "%d", &numberOfElements);
	for (i = 0; i < numberOfElements; i++)
		fscanf(fisier, "%d", &Tree[i].key);
	for (i = 0; i < numberOfElements; i++)
		fscanf(fisier, "%d", &Tree[i].parent);

    // AFISARI
    printf("\nAfisare in preordine: ");
    listInPreorder(3);
    printf("\nAfisare in inordine: ");
    listInInorder(3);
    printf("\nAfisare in postordine: ");
    listInPostorder(3);

    // INSERARE
    insertNode(23, 0);
    afisare();

    // NUMAR DE FRATI
    printf("\nNumar de frati: %d", getNumberOfSiblings(22));

    // CEL MAI DIN DREAPTA FRATE
    printf("\nCel mai din dreapta frate: %d", getRightMostSibling(14));

    // CEL MAI DIN STANGA FRATE
    printf("\nCel mai din stanga frate: %d", getLeftMostSibling(22));

    // INALTIME
    printf("\nInaltimea arborelui: %d", calculateHeight(3));
    return 0;
}



