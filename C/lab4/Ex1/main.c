#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *f = fopen("cuvinte.txt","r");
    char str[1000];
    size_t pos = ftell(f);
    fseek(f,0,SEEK_END);
    size_t len1 = ftell(f);
    fseek(f,pos, SEEK_SET);
    for(int i = 0 ;i<len1;i++) fscanf(f,"%c",&str[i]);
    fclose(f);
    char* token;
    char del[2] = " ";
    char rima[2];
    token=strtok(str,del);
    rima[0]=token[strlen(token)-2];
    rima[1]=token[strlen(token)-1];
    puts(token);
    token = strtok(NULL, del);
    puts(token);
       if(token[strlen(token)-1] == rima[1] && token[strlen(token)-2] == rima[0])  printf("Sunt rime");
       else printf("Nu rimeaza");

}
