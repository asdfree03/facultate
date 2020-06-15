#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s1[10],s2[10],s3[10],s4[10],s5[100];
    gets(s1);
    gets(s2);
    gets(s3);
    gets(s4);
    strcpy(s5,s1);strcat(s5,",");
    strcat(s5,s2); strcat(s5,",");
    strcat(s5,s3); strcat(s5,",");
    strcat(s5,s4);
    puts(s5);
}
