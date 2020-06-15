#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vocale(char *c){
    int nr = 0;
for(int i = 0;i<strlen(c);i++){
    if(strchr("aeiouAEIOU",c[i])) nr++;
}
return nr;
}
int main()
{
    char **c = (char **)malloc(20*sizeof(char *)); int n = 0;
    char fraza[100],*token, del[]=" !,.?";
    while(1){
        if(fgets(fraza,100,stdin)){
            token = strtok(fraza,del);
            while(token!=NULL){
            if(vocale(token)>2) {
                c[n] = (char *)malloc((strlen(token)+1)*sizeof(char));
                strcpy(c[n],token);
                n++;
            }
            token = strtok(NULL,del);
            }
        }
            else break;
    }
    for(int i = 0;i<n;i++) printf("%s %d\n",c[i],vocale(c[i]));
}
