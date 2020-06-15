#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    2 functii recursive
    1- primeste un string ca param si returneaza caracterul cel mai mic
    2- functie care primeste un string ca parametru si il oglindeste
*/
char s1[256];
char f1(char s[],char mic){
    if(strlen(s)==1){
        if(s[strlen(s)-1]<mic) return s[strlen(s)-1];
        else return mic;
    }
    else{
        if(s[strlen(s)-1]<mic)
                mic = s[strlen(s)-1];
                s[strlen(s)-1] = '\0';
        return f1(s,mic);
    }
}
void f2(char s[]){
    if(strlen(s)==1) {strcat(s1,s[strlen(s)-1]); strcat(s1,'\0');}
    else{
        strcat(s1,s[strlen(s)-1]);
        s[strlen(s)-1] = '\0';
        f2(s);
    }
}
void functie1(char s[]){
    printf("%c\n",f1(s,s[strlen(s)-1]));
}
void functie2(char s[]){
    strcpy(s1,"");
    f2(s);
    printf("%s",s1);
}
int main()
{
    char s[256]; strcpy(s,"abcde");
    functie1(s);
    functie2(s);
}
