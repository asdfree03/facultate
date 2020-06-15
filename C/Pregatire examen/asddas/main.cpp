#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
fstream f,g;
struct casti{
char marca[20],model[20],tip[20];
int an;
float pret;
} c[100],aux;
int i,n,r,a;

void afisare(){
system("cls");
cout<<"Marca"<<setw(15)<<"Model"<<setw(15)<<"Tip"<<setw(15)<<"Pret"<<setw(15)<<"An";
cout<<endl;
for(i=1;i<=n;i++){
cout<<c[i].marca<<setw(15)<<c[i].model<<setw(15)<<c[i].tip<<setw(15)<<c[i].pret<<setw(15)<<c[i].an;
cout<<endl;
}
getch();
}
void adaugare(){
system("cls");
cout<<"Marca= ";cin>>c[n+1].marca;
cout<<"Model= ";cin>>c[n+1].model;
cout<<"Tip= ";cin>>c[n+1].tip;
cout<<"Pret= ";cin>>c[n+1].pret;
cout<<"An= ";cin>>c[n+1].an;
cout<<endl;
n++;
}
void find_an(){
    system("cls");
cout<<"Cautare an\n";
cout<<"Introduceti anul dorit: ";cin>>a;
for(i=1;i<=n;i++){
    if(c[i].an==a) {
cout<<c[i].marca<<setw(15)<<c[i].model<<setw(15)<<c[i].tip<<setw(15)<<c[i].pret<<setw(15)<<c[i].an;
cout<<endl;
    }
}
getch();
}
void find_pret(){
    system("cls");
cout<<"Cautare dupa pret\n";
float p_min,p_max;
cout<<"Introduceti pretul minim: ";cin>>p_min;
cout<<"Introduceti pretul maxim: ";cin>>p_max;
for(i=1;i<=n;i++){
    if(c[i].pret>p_min && c[i].pret<p_max) {
cout<<c[i].marca<<setw(15)<<c[i].model<<setw(15)<<c[i].tip<<setw(15)<<c[i].pret<<setw(15)<<c[i].an;
cout<<endl;
    }
}
getch();
}
void find_marca(){
    system("cls");
    char m[30];
cout<<"Cautare marca\n";
cout<<"Introduceti marca dorita: ";gets(m);
for(i=1;i<=n;i++){
    if(strcmp(c[i].marca,m)==0) {
cout<<c[i].marca<<setw(15)<<c[i].model<<setw(15)<<c[i].tip<<setw(15)<<c[i].pret<<setw(15)<<c[i].an;
cout<<endl;
    }
}
getch();
}
void sort_an()
{
 system("cls");
for(i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
                if(c[i].an>c[j].an){
aux=c[i];
c[i]=c[j];
c[j]=aux;
        }}}
 cout<<"Operatie Efectuata"; getch();
}
void sort_marca()
{
 system("cls");
for(i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
                if(strcmp(c[i].marca,c[j].marca)>0){
aux=c[i];
c[i]=c[j];
c[j]=aux;
        }}}
 cout<<"Operatie Efectuata"; getch();
}
void sort_pret()
{
 system("cls");
for(i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
                if(c[i].pret>c[j].pret){
aux=c[i];
c[i]=c[j];
c[j]=aux;
        }}}
 cout<<"Operatie Efectuata"; getch();
}
void salvare(){
system("cls");
char nume[15];
cout<<"Salvarea datelor\n";
cout<<"Dati numele fisierului pentru salvare\n";gets(nume);
ofstream g(nume,ios::out);
cout<<"Datele vor fi salvate in fisierul "<<nume<<", in prima linia va fi scris numarul de modele de casti.\n";
g<<n;
for (i=1;i<=n;i++){
g<<c[i].marca<<setw(15)<<c[i].model<<setw(15)<<c[i].tip<<setw(15)<<c[i].pret<<setw(15)<<c[i].an;
g<<endl;
}
}
void iesire(){
    system("cls");
cout<<"Bye";
getch();
}
void excludere()
{
 system("cls");
 char s[30];
 cout<<"Introdu modelul castilor care urmeaza a fi excluse\n";
 gets(s);
 if(strlen(s)!=0) {
for(i=1;i<=n;i++){
  if(strcmp(c[i].model,s)==0) {r++;
//      goto trece;
}
 }
if (r!=0){
// trece:

aux=c[i];
c[i]=c[n];
c[n]=aux;
 n--;
 cout<<"Operatie Efectuata"; getch();
}
else if (r==0) {
cout<<"Nu exista asa model.";getch();
}
}
}
main()
{
char k,cc;
f.open("casti.in",ios::in);
f>>n;
for(i=1;i<=n;i++){
f>>c[i].marca>>c[i].model>>c[i].tip>>c[i].pret>>c[i].an;
}
system("cls");
do{
cout<<setw(40)<<"Program casti\n";
cout<<"A - Afisati toate castile."<<endl;
cout<<"B - Adaugati informatie in baza de date."<<endl;
cout<<"C - Excludeti un exemplar din lista."<<endl;
cout<<"D - Sortati castile."<<endl;
cout<<"E - Cautati un model de casti."<<endl;
cout<<"G - Salvati datele intrun fisier"<<endl;
cout<<"Q - Iesire"<<endl;
k=getch();
switch (k){
case 'A': afisare();break;
case 'B': adaugare();break;
case 'C': excludere();break;
case 'D': system("cls");
cout<<"Sortare\n";
cout<<"A - Dupa an\n";
cout<<"M - Dupa marca\n";
cout<<"P - Dupa pret\n";
cc=getch();
switch (cc){
case 'A':sort_an();break;
case 'M':sort_marca();break;
case 'P':sort_pret();break;
}
case 'E':system("cls");
cout<<"Cautare\n";
cout<<"A - dupa an\n"<<"M - dupa marca\n"<<"P - dupa pret\n";
cc=getch();
switch (cc){
case 'A':find_an();break;
case 'M':find_marca();break;
case 'P':find_pret();break;
}
case 'G':salvare();break;
case 'Q':iesire();break;
}
system("cls");
}while(k!='Q');
}
