#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];
    int t[5];
    for(int i = 0;i<5;i++) t[i]=0;
    gets(s);
    for (int i=0;i<strlen(s);i++) {if(s[i]=='a') t[0]=t[0]+1;
    else if(s[i]=='e') t[1]=t[1]+1;
    else if(s[i]=='i') t[2]=t[2]+1;
    else if(s[i]=='o') t[3]=t[3]+1;
    else if(s[i]=='u') t[4]=t[4]+1;
}
if(t[0]>=t[1] && t[0]>=t[2] && t[0]>=t[3] && t[0]>=t[4]) printf("Cel mai des apare 'a' de %d ori",t[0]);
if(t[1]>=t[0] && t[1]>=t[2] && t[1]>=t[3] && t[1]>=t[4]) printf("Cel mai des apare 'e' de %d ori",t[1]);
if(t[2]>=t[0] && t[2]>=t[1] && t[2]>=t[3] && t[2]>=t[4]) printf("Cel mai des apare 'i' de %d ori",t[2]);
if(t[3]>=t[0] && t[3]>=t[2] && t[3]>=t[1] && t[3]>=t[4]) printf("Cel mai des apare 'o' de %d ori",t[3]);
if(t[4]>=t[0] && t[4]>=t[2] && t[4]>=t[3] && t[4]>=t[1]) printf("Cel mai des apare 'u' de %d ori",t[4]);
}
