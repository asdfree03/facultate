include <stdio.h>
#include <stdlib.h>

void sugestie(char *x, NodArboreDeRegasire *cuvinte)
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
