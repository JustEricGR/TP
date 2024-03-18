#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char nume[21];
    int nota;
}Elev;

void citire(Elev *v,int size)
{
    for(int i=0;i<size;i++)
    {
        scanf("%20s %d",v[i].nume,&v[i].nota);
    }

}

void afisare(Elev *v, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%s - %d\n",v[i].nume,v[i].nota);
    }
}

void getter(char *s,Elev *v,int size)
{
    int ok=0;
    Elev aux={"",0};
    for(int i=0;i<size;i++)
    {
        if(!strcasecmp(v[i].nume,s))
        {
            ok++;
            aux.nota=v[i].nota;
            strcpy(aux.nume,v[i].nume);
        }
    }
    if(ok==1)
    {
        printf("%s - %d\n",aux.nume,aux.nota);
    }
    else
    {
        printf("Nu s a gasit\n");
    }

}

int main(int argc, char **argv)
{
    int size=0;
    printf("Introduceti dimensiunea");
    scanf("%d",&size);
    Elev *v=NULL;
    v=(Elev*)malloc(size*sizeof(Elev));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v,size);
    getter(argv[1],v,size);
    free(v);
}