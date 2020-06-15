#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int max_n; int nr_p;
typedef struct NodArboreDeRegasire {
    int ver;
	struct NodArboreDeRegasire *alfabet[27];
}NodArboreDeRegasire;
NodArboreDeRegasire *list;
void Initializare(NodArboreDeRegasire *Nod)
{
	//ATENTIE, aceasta functie trebuie apelata cu *Nod deja alocat
	char c;
	Nod->ver = 0;
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
int Verifica(NodArboreDeRegasire *Nod,char c){
    if(Nod->alfabet[c-'a']->ver == 0) return 1;
    return 0;
}
void NodNou(NodArboreDeRegasire *Nod, char c)
{
	Nod->alfabet[c - 'a'] = (NodArboreDeRegasire *)malloc(sizeof(struct NodArboreDeRegasire));
	Initializare(Nod->alfabet[c - 'a']);
}

void Adauga(char *x, NodArboreDeRegasire *cuvinte)  //x=cuvantul, cuvinte=radacina arborelui de regasire
{
	unsigned i;
	NodArboreDeRegasire *t;
	t = cuvinte;
	if(Verifica(t,x[0])){
        nr_p++;
        t->alfabet[x[0]-'a']->ver = 1;
	}
	for (i = 0; i < strlen(x);i++)
	{
		if (Valoare(t, x[i]) == NULL){//nodul curent nu are fiu pentru caracterul x[i], deci se creaza unul nou
            nr_p++;
			NodNou(t, x[i]);
		}
		t = Valoare(t, x[i]); //avansez in arborele de regasire

	}
	Atribuie(t, '{', t); //se face o bucla pentru '[', pentru a marca un nod terminal

}
void parc_inaltime(NodArboreDeRegasire *Nod, int niv) //nodul curent, un buffer pentru construirea cuvantului, nivelul curent
{
	char c;
	for (c = 'a'; c <= 'z'; c++)		//pentru toate literele considerate
	{
		if (Valoare(Nod, c))			//daca exista legatura in dictionar
		{				//adaug litera gasita in buffer
			parc_inaltime(Valoare(Nod, c),niv+1); //avansez
		}
	}
	if (Valoare(Nod, '{'))			//exista terminator=>am gasit un cuvant intreg
	{
		if(niv>max_n) max_n = niv;		//prelucrez datele
	}
}
int inaltime(){
    parc_inaltime(list,0);
    return max_n+1;
}
void Parcurge(NodArboreDeRegasire *Nod, char cuv[], int niv) //nodul curent, un buffer pentru construirea cuvantului, nivelul curent
{
	char c;
	for (c = 'a'; c <= 'z'; c++)		//pentru toate literele considerate
	{
		if (Valoare(Nod, c))			//daca exista legatura in dictionar
		{
			cuv[niv] = c;				//adaug litera gasita in buffer
			Parcurge(Valoare(Nod, c),cuv,niv+1); //avansez
		}
	}
	if (Valoare(Nod, '{'))			//exista terminator=>am gasit un cuvant intreg
	{
		cuv[niv] = '\0';
		printf("%s\n", cuv);		//prelucrez datele
	}
}
int nr_pag(){

 return nr_p+1;
}
int main()
{
    int n; nr_p = 0;
    list = (NodArboreDeRegasire *)malloc(sizeof(struct NodArboreDeRegasire));
    Initializare(list);
    for(char c ='a';c<'{';c++) NodNou(list,c);
    char s[30];
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%s",s);
        Adauga(s,list);
    }
    char cuv[30];
    max_n = 0;
    printf("%d ",inaltime());
   printf("%d",nr_pag());
}
