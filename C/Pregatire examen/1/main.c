#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
char *c; char s[10][100];
int vocale(char *t){
    int k = 0;
    for(int i = 0;i<strlen(t);i++) if(t[i]=='a' || t[i]=='u' || t[i]=='o' || t[i]=='i' || t[i]=='e' || t[i]=='A' || t[i]=='U' || t[i]=='O' || t[i]=='I' || t[i]=='E') k++;
    return k;
}
int main()
{
    int i = 0; int nr = 0;
    while(1){
        if (fgets(s[i], 100, stdin)) {
    i++; nr ++;
} else break;
    }
    char *token;
    for(int i = 0;i<nr;i++){
    token = strtok(s[i]," ");
    while(token!=NULL){
        if(vocale(token)>=3){
        printf("%s %d\n",token,vocale(token));
        }
        token  = strtok(NULL," ");
    }
    }
//    for(int i = 0;i<e;i++) puts(c[e]);
 //   free(c);
}
