/* - Adaugare + explicatie
- Stergere cuvant dat
- Afisare ultimul cuvant
*/

#include<stdio.h>
#include<stdlib.h>

int n;
char cuvant[40];
char lung[40] = "";
char scurt[40] = "SUPERCALIFRAGILISTICEXPIALIDOCIOUS";

typedef struct NodArboreDeRegasire {
	struct NodArboreDeRegasire *alfabet[27];
} NodArboreDeRegasire;

void Initializare(NodArboreDeRegasire *Nod)
{
	char c;
	for (c = 'A'; c <= '['; c++)
		Nod->alfabet[c - 'A'] = NULL;
}

void Atribuie(NodArboreDeRegasire *Nod, char c, NodArboreDeRegasire *p)
{
	Nod->alfabet[c - 'A'] = p;
}

NodArboreDeRegasire *Valoare(NodArboreDeRegasire *Nod, char c)
{
	return Nod->alfabet[c - 'A'];
}

void NodNou(NodArboreDeRegasire *Nod, char c)
{
	Nod->alfabet[c - 'A'] = (NodArboreDeRegasire *)malloc(sizeof(struct NodArboreDeRegasire));
	Initializare(Nod->alfabet[c - 'A']);
}

void Adauga(char *x, NodArboreDeRegasire *cuvinte, char*explicatie)  //x = cuvantul, cuvinte = radacina arborelui de regasire
{

	int i;
	NodArboreDeRegasire *t;
	t = cuvinte;
	for (i = 0; i < strlen(x); i++)
	{
		if (Valoare(t, x[i]) == NULL) //nodul curent nu are fiu pentru caracterul x[i], deci se creaza unul nou
			NodNou(t, x[i]);
		t = Valoare(t, x[i]); //avansez in arborele de regasire
	}
	Atribuie(t, '[', explicatie); //caracterul '[' indica spre explicatie
}

int FinalCuvant(NodArboreDeRegasire *Nod)
{
	if (Nod->alfabet['[' - 'A'])
		return 1;
	return 0;
}

int NodNenul(NodArboreDeRegasire *Nod)
{
	if (Nod != NULL)
		return 1;
	return 0;
}


void AfisareAlfabetica(NodArboreDeRegasire *arbore, int n)
{
	int i;
	if (Valoare(arbore, '['))
	{
		cuvant[n] = '\0';
		printf("%s %s \n", cuvant, arbore->alfabet[26]);
	}
	for (i = 0; i<26; i++)
	{
		if (arbore->alfabet[i])
		{
			cuvant[n] = i + 'A';
			AfisareAlfabetica(arbore->alfabet[i], n + 1);
		}
	}
}

void afisareCuvinteCareIncepCuLitera(NodArboreDeRegasire *arbore, char c)
{
    if(arbore->alfabet[c-'A'] == NULL)
        printf("Nu exista cuvinte care incep cu litera respectiva\n");
    else
    {
        cuvant[0] = c;
        AfisareAlfabetica(arbore->alfabet[c-'A'], 1);
    }
}

int Cautare(char *x, NodArboreDeRegasire *arbore)
{
	int i = 0;
	while (i < strlen(x) && Valoare(arbore, x[i]) != NULL)
	{
		arbore = Valoare(arbore, x[i]);
		i++;
	}
	if (!NodNenul(arbore->alfabet[26]))
	{
		printf("Nu exista cuvantul!");
		return 0;
	}
	else
	{
		printf("Gasit! Explicatie: %s\n", arbore->alfabet[26]);
		return 1;
	}
}

int AreCopii(NodArboreDeRegasire *arbore)
{
	for (int i = 0; i < 26; i++)
		if (arbore->alfabet[i])
			return 1;
	return 0;
}

int Stergere(char *x, NodArboreDeRegasire *arbore)
{
	int i;
	if (!NodNenul(arbore) || !Cautare(x, arbore))
		return 0;
	for (i = 0; i < strlen(x); i++)
	{
		if (Valoare(arbore, x[i]) != NULL)
		if (!AreCopii(arbore))
		{
			free(arbore);
			arbore->alfabet[x[i] - 'A'] = NULL;
		}
		arbore = Valoare(arbore, x[i]);
	}
	if (Valoare(arbore, '['))
		arbore->alfabet[26] = NULL;
}

char ultim[40] = "";

char *Ultimul(NodArboreDeRegasire *arbore, int n)
{
	int i;
	for (i = 0; i<26; i++)
	{
		if (arbore->alfabet[i])
		{
			cuvant[n] = i + 'A';
			Ultimul(arbore->alfabet[i], n + 1);
		}
	}
	if (Valoare(arbore, '['))
	{
		cuvant[n] = '\0';
		strcpy(ultim, cuvant);
	}
	return ultim;
}

char prim[40] = "";

char *Primul(NodArboreDeRegasire *radacina, int n)
{
    int i;
    if(radacina == NULL)
        return NULL;
    if(radacina->alfabet[26] != NULL)
    {
        // daca am gasit primul terminator de cuvant inseamna ca avem primul cuvant
        prim[n] = '\0';
    }
    else
    {
        // daca nu, mai cautam
        for(i=0; i<26; i++)
            if(radacina->alfabet[i] != NULL)
            {
                prim[n] = i + 'A';
                Primul(radacina->alfabet[i], n+1);
                break;
            }
    }
    return prim;
}

char* CelMaiScurt(NodArboreDeRegasire *arbore, int n)
{
	int i;
	for (i = 0; i<26; i++)
	{
		if (arbore->alfabet[i])
		{
			cuvant[n] = i + 'A';
			CelMaiScurt(arbore->alfabet[i], n + 1);
		}
	}
	if (Valoare(arbore, '['))
	{
		cuvant[n] = '\0';
		if (strlen(cuvant) < strlen(scurt))
			strcpy(scurt, cuvant);
	}
	return scurt;
}

char* CelMaiLung(NodArboreDeRegasire *arbore, int n)
{
	int i;
	for (i = 0; i<26; i++)
	{
		if (arbore->alfabet[i])
		{
			cuvant[n] = i + 'A';
			CelMaiLung(arbore->alfabet[i], n + 1);
		}
	}
	if (Valoare(arbore, '['))
	{
		cuvant[n] = '\0';
		if (strlen(cuvant) > strlen(lung))
			strcpy(lung, cuvant);
	}
	return lung;
}

int DeterminaMaximul(int numar1, int numar2)
{
	if (numar1 > numar2)
		return numar1;
	else
		return numar2;
}


int Inaltime(NodArboreDeRegasire *arbore)
{
	int i, h = 1;
	for (i = 0; i < 26; i++)
	{
		if (NodNenul(arbore->alfabet[i]))
			h = DeterminaMaximul(h, 1 + Inaltime(arbore->alfabet[i]));
	}
	return h;
}

int n = 0;
char p[40]="";
void primulCuvant(NodArboreDeRegasire *cuvinte)
{
    char c;
    char i;
    while(cuvinte->alfabet[26]==NULL)
	 {
	    i='A';
	    while(cuvinte->alfabet[i-'A']==NULL)
		    i++;
        p[n]=i;
        n++;
        cuvinte=cuvinte->alfabet[i-'A'];
    }
}

int m = 0;
char u[40]="";
char aux;//tin minte ultima litera din nod
void ultimulCuvant(NodArboreDeRegasire *cuvinte)
{
    char c;
    while(cuvinte->alfabet[c-'A']==NULL)
    {
	    for(c='A';c<'[';c++)
		    if(cuvinte->alfabet[c-'A']!=NULL)
			    aux=c;
	    u[m]=aux;
	    m++;
	    cuvinte=cuvinte->alfabet[aux-'A'];
	}
}

char sugestie[40] = "";
void sugestieCorectare(NodArboreDeRegasire *radacina, char *cuvant)
{
    int i;
    char j;
    if(Cautare(cuvant, radacina))
    {
        printf("\nCuvantul este corect!");
        return;
    }
    else
        printf("\nCuvantul este gresit!");
    for(i = 0; i < strlen(cuvant); i++)
    {
        if(Valoare(radacina, cuvant[i]))
        {
            sugestie[i] = cuvant[i];
            radacina = Valoare(radacina, cuvant[i]);
        }
        else // Am gasit o greseala
            for(j = 0; j < 26; j++)
            {
                if(radacina->alfabet[j]) {
                    sugestie[i] = j + 'A';
                radacina = Valoare(radacina, radacina->alfabet[j]);
                break;}
            }
    }
    if (Valoare(radacina, '['))
        sugestie[i+1] = '\0';
    printf("\nSugestie de corectare: %s", sugestie);
}

void sugestion(char *x, NodArboreDeRegasire *cuvinte)
{
    int i;
    NodArboreDeRegasire *t;
    t=cuvinte;
    int limit=0;//limita ca doar o litera sa lipseasca

    printf("Cuvantul pe care il cauti este: ");

    for(i=0;i<strlen(x);i++)
    {
    if(Valoare(t, x[i]) != NULL) //daca exista litera in arbore
        {
        printf("%c",x[i]); //printeaza caracterul din cuvant
        t=Valoare(t,x[i]); //avansam in arbore
        }
    else if(limit==0)//am intampinat litera lipsa
        {
        char c;
        for(c='A';c<='[';c++)
            {//parcurgem toate posibilitatiile din prefixul din dictionar
            int trigger=0; //trigger daca am gasit litera lipsa
            NodArboreDeRegasire *t2;
            t2=t;//o noua copie a prefixului existent ca sa nu il overwrituim
            if(Valoare(t2, c)!=NULL)
                {
                int j;
                for(j=i;j<strlen(x);j++)//continuam sa parcurgem cuvantul sarind peste litera lipsa
                    {
                    if(Valoare(t2, x[j]) != NULL) //daca exista litera in arbore
                        t2=Valoare(t2,x[j]); //avansam in arbore
                    if(i==strlen(x)-1)//daca am ajuns la finalul cuvantului
                        {
                        if(Valoare(t,'[')!=NULL)
                            trigger=1;
                        }
                    }
                }
            if(trigger==1)
                break;//c va fi litera lipsa
            }
        printf("%c",c);//printeaza caracterul lipsa
        limit=1;//setam ca deja a fost atinsa limita de o litera lipsa
        t=Valoare(t,c);
        }
    else printf(" <--- AI GRESIT CUVANTUL BAIATUL MEU ---> ");

    if(i==strlen(x)-1)//daca am ajuns la finalul cuvantului
        break;
    }
printf("?");
}

int main()
{
	NodArboreDeRegasire *radacina;
	radacina = (NodArboreDeRegasire *)malloc(sizeof(NodArboreDeRegasire));
	Initializare(radacina);
	Adauga("SDA", radacina, "structuri de date si algoritmi");
	Adauga("A", radacina, "prefix");
	Adauga("AR", radacina, "prefix");
	Adauga("ARC", radacina, "instrument");
	Adauga("PAA", radacina, "proiectarea si analiza algoritmilor");
	Adauga("POLITEHNICA", radacina, "facultate");
	Adauga("POLI", radacina, "prescurtare pentru politehnica");
	AfisareAlfabetica(radacina, 0);
	printf("\nAfisarea dupa stergere este:\n");
	Stergere("POLI", radacina);
	Stergere("AR", radacina);
    AfisareAlfabetica(radacina, 0);
	Cautare("POLI", radacina);
	printf("\nCel mai scurt cuvant este: %s", CelMaiScurt(radacina, 0));
	printf("\nCel mai lung cuvant este: %s", CelMaiLung(radacina, 0));
	printf("\nInaltimea este: %d", Inaltime(radacina));
	printf("\nUltimul cuvant este: %s", Ultimul(radacina, 0));
	printf("\nPrimul cuvant este: %s", Primul(radacina, 0));
	primulCuvant(radacina);
	printf("\nPrimul cuvant este: %s", p);
	ultimulCuvant(radacina);
	printf("\nUltimul cuvant este: %s", u);
	afisareCuvinteCareIncepCuLitera(radacina, 'A');
	Adauga("COMPUTER", radacina, "dispozitiv electronic");
	sugestion("COMPUER", radacina);
}

