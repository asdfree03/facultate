#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *f = fopen("poezie.in","r");
    char c[5000],e[5000];
    size_t pos = ftell(f);
    fseek(f,0,SEEK_END);
    size_t len = ftell(f);
    fseek(f,pos, SEEK_SET);
    for(int i = 0 ;i<len;i++) fscanf(f,"%c",&c[i]);
    fclose(f);
int l=0;
    for(int i = 0;i<strlen(c);i++){
        if(c[i]=='.' || c[i]=='!' || c[i]=='?' || c[i]==','){
            if(c[i+1]=='\n' || c[i+1]=='\0') {
                e[l]=c[i];
                l++;
            }}
            else {e[l]=c[i]; l++;}
    }
    FILE *g = fopen("poezie.out","w");
    for(int i=0;i< strlen(e);i++) fprintf(g,"%c",e[i]);
}
