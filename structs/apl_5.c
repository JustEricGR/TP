#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    unsigned int nr_picioare:10;
    unsigned int greutate:10;
    unsigned int pericol:1;
    char abreviere[9];
    unsigned int varsta:10;
    char danger[3];
}Animale;

void citire(Animale *v,int size)
{
    for(int i=0;i<size;i++)
    {
        unsigned int picioare=0,greutate=0,pericol=0,varsta=0;
        char abreviere[9]="";
        scanf("%d %d %d %8s %d",&picioare,&greutate,&pericol,abreviere,&varsta);
        switch(pericol)
        {
            case 0:
                strcpy(v[i].danger,"nu");
                break;
            case 1:
                strcpy(v[i].danger,"da");
        }
        v[i].nr_picioare=picioare;
        v[i].greutate=greutate;
        strcpy(v[i].abreviere,abreviere);
        v[i].varsta=varsta;
    }
}

void afisare(Animale *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("nr picioare: %d ,greutate: %d ,pericol: %s ,abreviere: %s ,varsta: %d\n",v[i].nr_picioare,v[i].greutate,v[i].danger,v[i].abreviere,v[i].varsta);
    }
}

int main(void)
{
    unsigned int size=0;
    printf("Cate elemente sa se citeasca:");
    scanf("%d",&size);
    Animale *v=NULL;
    v=(Animale*)malloc(size*sizeof(Animale));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v,size);
    afisare(v,size);
    free(v);
}