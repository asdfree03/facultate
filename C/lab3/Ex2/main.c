#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *f = fopen("fraza.txt","r");
    char str[1000];
    size_t pos = ftell(f);
    fseek(f,0,SEEK_END);
    size_t len1 = ftell(f);
    fseek(f,pos, SEEK_SET);
    for(int i = 0 ;i<len1;i++) fscanf(f,"%c",&str[i]);
    fclose(f);
    puts(str);
    char str2[1000]=" ",w[20],r[20],neww[20][20];
        int i=0,len=0;
        const char del[2]=" ";
        char *token;
        printf("Replace : \n");
        gets(w);
        printf("With : \n");
        gets(r);
        token=strtok(str,del);
        if(strcmp(token,w)==0)
                strcpy(neww[i],r);

        else
                strcpy(neww[i],token);
       i=0;
        while(token!=NULL)
        {

                if(strcmp(token,w)==0)
                        strcpy(neww[i],r);

                else
                        strcpy(neww[i],token);
                token=strtok(NULL,del);
                i++;
        }
        len=i;
        printf("\n");
        strcpy(str2,neww[0]);
        for(i=1; i<len; i++) {
                strcat(str2," ");
                strcat(str2,neww[i]);
        }
        puts(str2);
        return(0);
}

