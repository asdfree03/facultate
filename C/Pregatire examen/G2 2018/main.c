#include <stdio.h>
#include <stdlib.h>
struct Persoane{
char nume[20];
char prenume[20];
char functie[20];
int salariu;
int zile;
};

int main()
{
    struct Persoane *p;
    int n;
    scanf("%d",&n);
    p = (struct Persoane *)malloc(n*sizeof(struct Persoane));
    int sal;
    for(int i = 0;i<n;i++) {
        scanf("%s",&p[i].nume);
        scanf("%s",&p[i].prenume);
        scanf("%s",&p[i].functie);
        scanf("%d",&p[i].salariu);
        scanf("%d",&p[i].zile);
    }
    scanf("%d",&sal);
    for(int i = 0;i<n;i++) {
        if(p[i].salariu>=sal) {
        printf("%s ",p[i].nume);
        printf("%s ",p[i].prenume);
        printf("%s ",p[i].functie);
        printf("%d ",p[i].salariu);
        printf("%d ",p[i].zile);
        }
    }
}
