#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>
#define CHUNK 20

char *concat(int n,...)
{
    char *rez=NULL;
    int current=CHUNK,index=0;
    rez=(char*)malloc(current*sizeof(char));
    if(rez==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    strcpy(rez,"");
    va_list va;
    va_start(va,n);
    for(int i=0;i<n;i++)
    {
        char *aux=va_arg(va,char*);
        index=strlen(aux)+2;
        if(index>=current)
        {
            current+=CHUNK;
            rez=(char*)realloc(rez,current*sizeof(char));
        }
        strcat(rez,aux);
        strcat(rez," ");
    }
    va_end(va);
    return rez;
}

int main(void)
{
    char *v=NULL;
    v=concat(3,"Ion","si","Ana");
    puts(v);
    free(v);
}