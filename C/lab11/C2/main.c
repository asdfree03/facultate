#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char c[10][10]; char temp[10]; int i,j;
int gata = 0; int count = 0;
while(!gata){
    gets(c[count]);
    if(strcmp(c[count],"STOP")==0) break;
    count++;
}
for(i=0; i<count-1; i++)
        for(j=i+1; j<count ; ++j)
        {
            if(strcmp(c[i], c[j])>0)
            {
                strcpy(temp, c[i]);
                strcpy(c[i], c[j]);
                strcpy(c[j], temp);
            }
        }
for(int j = 0;j<count;j++) printf("%s\n", c[j]);
}
