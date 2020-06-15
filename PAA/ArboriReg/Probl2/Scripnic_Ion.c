#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char cuvm[30];
typedef struct NodArboreDeRegasire {
	struct NodArboreDeRegasire *alfabet[27];
}NodArboreDeRegasire;
NodArboreDeRegasire *list;
void Initializare(NodArboreDeRegasire *Nod)
{
	//ATENTIE, aceasta functie trebuie apelata cu *Nod deja alocat
	char c;
	for (c = 'a'; c <= '{'; c++)
		Nod->alfabet[c - 'a'] = NULL;
}

void Atribuie(NodArboreDeRegasire *Nod, char c, NodArboreDeRegasire *p)
{
	Nod->alfabet[c - 'a'] = p;
}

NodArboreDeRegasire *Valoare(NodArboreDeRegasire *Nod, char c)
{
	return Nod->alfabet[c - 'a'];
}
void NodNou(NodArboreDeRegasire *Nod, char c)
{
	Nod->alfabet[c - 'a'] = (NodArboreDeRegasire *)malloc(sizeof(struct NodArboreDeRegasire));
	Initializare(Nod->alfabet[c - 'a']);
}

void Adauga(char *x, NodArboreDeRegasire *cuvinte)  //x=cuvantul, cuvinte=radacina arborelui de regasire
{
    if(strcmp(x,cuvm)>0) strcpy(cuvm,x);
	unsigned i;
	NodArboreDeRegasire *t;
	t = cuvinte;
	for (i = 0; i < strlen(x);i++)
	{
		if (Valoare(t, x[i]) == NULL){//nodul curent nu are fiu pentru caracterul x[i], deci se creaza unul nou
			NodNou(t, x[i]);
		}
		t = Valoare(t, x[i]); //avansez in arborele de regasire

	}
	Atribuie(t, '{', t); //se face o bucla pentru '[', pentru a marca un nod terminal

}
char *cmmc(){
    return cuvm;
}
int main()
{
    strcpy(cuvm,"");
    int n;
    list = (NodArboreDeRegasire *)malloc(sizeof(struct NodArboreDeRegasire));
    Initializare(list);
    for(char c ='a';c<'{';c++) NodNou(list,c);
    char s[30];
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%s",s);
        Adauga(s,list);
    }
    printf("%s",cmmc());
}
