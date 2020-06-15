#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
    return strcmp(*(char**)a, *(char**)b);
}
int main(){
    char text[80];
    char *words[40];
    char *word;
    int wmax=0, i;
    scanf("%30[^\n]", text);
    for(word = strtok(text, " "); word ; word = strtok(NULL, " ")){
        words[wmax++] = word;
    }
    qsort(words, wmax, sizeof(*words), compare);
    for(i=0;i<wmax;++i)
        printf("%s\n", words[i]);

}
