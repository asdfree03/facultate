#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10
typedef int Cursor;
struct Zona {
    char cheie;                  //cheia nodului curent
    Cursor primul_fiu, frate_drept;

};
struct Arbore {
    struct Zona noduri[MAX_N + 1];
    Cursor radacina;              //pozitia radacinii
}tree;
void adauga(){
    int n; char c;
    scanf("%c",&c);
    tree.noduri[tree.radacina].cheie = c;
    scanf("%d",&n);
    tree.noduri[tree.radacina].primul_fiu = n;
    scanf("%d",&n);
    tree.noduri[tree.radacina].frate_drept = n;
    tree.radacina++;
}
void afisare(){
    for(int i = 0;i<tree.radacina;i++){
        printf("%c %d %d\n",tree.noduri[i].cheie,tree.noduri[i].primul_fiu,tree.noduri[i].frate_drept);
    }
    scanf("\n");
}
void inordine(){

}
int main()
{
    adauga();
    afisare();
    adauga();
    afisare();
}
