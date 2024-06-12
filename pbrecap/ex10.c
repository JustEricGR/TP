#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define IN1 "MultimeA.txt"
#define IN2 "MultimeB.txt"

typedef struct nod{
    int n;
    struct nod *urm;
}nod;

nod *nou(int n,nod *urm)
{
    nod *e=(nod*)malloc(sizeof(nod));
    if(e==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    e->n=n;
    e->urm=urm;
    return e;
}

nod *adaugaSfarsit(nod *lista,int n)
{
    if(lista==NULL)
    {
        return nou(n,NULL);
    }

    nod *c=lista;
    for(;c->urm!=NULL;c=c->urm)
    {}
    c->urm=nou(n,NULL);
    return lista;
}

void afisare(nod *lista,FILE *fout)
{
    for(;lista;lista=lista->urm)
    {
        fprintf(fout,"%d ",lista->n);
    }fprintf(fout,"\n");
}

void eliberare(nod *lista)
{
    nod *p=NULL;
    while(lista)
    {
        p=lista->urm;
        free(lista);
        lista=p;
    }
}

nod *reuniune(nod *lista,nod *lista1,nod *lista2)
{
    nod *c=NULL;
    for(c=lista1;c;c=c->urm)
    {
        lista=adaugaSfarsit(lista,c->n);
    }

    for(c=lista2;c;c=c->urm)
    {
        lista=adaugaSfarsit(lista,c->n);
    }
    return lista;
}

nod *intersectie(nod *lista,nod *lista1,nod *lista2)
{
    nod *c1=NULL,*c2=NULL;
    for(c1=lista1;c1;c1=c1->urm)
    {
        for(c2=lista2;c2;c2=c2->urm)
        {
            if(c1->n == c2->n)
            {
                lista=adaugaSfarsit(lista,c1->n);
                break;
            }
        }
    }
    return lista;
}

int main(void)
{
    clock_t start=0,end=0;
    double used=0;
    start=clock();
    FILE *fin1=NULL,*fin2=NULL;
    if((fin1=fopen(IN1,"r+"))==NULL)
    {
        printf("Eroare la deschidere fisier1\n");
        perror(NULL);
        exit(-1);
    }
    nod *lista1=NULL,*lista2=NULL,*lista3=NULL,*lista4=NULL;
    int n=0;
    while(fscanf(fin1,"%d",&n)==1)
    {
        lista1=adaugaSfarsit(lista1,n);
    }
    afisare(lista1,stdout);
    
    if((fin2=fopen(IN2,"r+"))==NULL)
    {
        printf("Eroare la deschidere fisier2\n");
        perror(NULL);
        exit(-1);
    }
    while(fscanf(fin2,"%d",&n)==1)
    {
        lista2=adaugaSfarsit(lista2,n);
    }
    afisare(lista2,stdout);

    lista3=reuniune(lista3,lista1,lista2);
    printf("Reuniunea listelor este:");
    afisare(lista3,stdout);
    fprintf(fin1,"\n");
    afisare(lista3,fin1);
    fprintf(fin2,"\n");
    afisare(lista3,fin2);
    lista4=intersectie(lista4,lista1,lista2);
    printf("Intersectia listelor este:");
    afisare(lista4,stdout);
    afisare(lista4,fin1);
    afisare(lista4,fin2);
    if(fclose(fin1))
    {
        printf("Eroare la inchidere fisier1\n");
        perror(NULL);
        eliberare(lista1);
        eliberare(lista2);
        eliberare(lista3);
        eliberare(lista4);
        exit(-1);
    }
    if(fclose(fin2))
    {
        printf("Eroare la inchidere fisier1\n");
        perror(NULL);
        eliberare(lista1);
        eliberare(lista2);
        eliberare(lista3);
        eliberare(lista4);
        exit(-1);
    }
    eliberare(lista1);
    eliberare(lista2);
    eliberare(lista3);
    end=clock();
    used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total time:%g\n",used);
    return 0;
}
