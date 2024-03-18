#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define file_path "inventar.bin"

typedef enum{
    INTRODUCERE,
    AFISARE_COND,
    AFISARE,
    SALVARE
}opt;

typedef enum{
    CARTE,
    REVISTA
}type;

typedef union{
    char isbn[14];
    uint an;
}caracteristica;

typedef struct{
    char titlu[50];
    char autor[40];
    uint nr_exemplare;
    uint pret;
    uint nr_pagini;
    uint greutate;
    char tip[20];
    type t;
    caracteristica caract;
}Produs;


void citire(Produs *v,uint size)
{
    srand(time(NULL));
    for(uint i=0;i<size;i++)
    {
        uint opt=0;
        printf("Introduceti titlul cartii %d:",i+1);
        scanf("%49s",v[i].titlu);
        printf("Introduceti autorul cartii %d:",i+1);
        scanf("%39s",v[i].autor);
        v[i].nr_exemplare=rand()%10000;
        v[i].pret=rand()%500;
        v[i].nr_pagini=rand()%1000;
        v[i].greutate=rand()%5000;
        printf("Introduceti 0 daca produsul e carte si 1 daca e revista:");
        scanf("%d",&opt);
        v[i].t=opt;
        switch(v[i].t)
        {
            case CARTE:
            {
                strcpy(v[i].tip,"carte");
                printf("Introduceti isbn-ul:");
                scanf("%13s",v[i].caract.isbn);
                break;
            }
            case REVISTA:
            {
                strcpy(v[i].tip,"revista");
                printf("Introduceti anul aparitiei:");
                scanf("%d",&v[i].caract.an);
                break;
            }
        }
    }

}

void inserare(Produs *v,Produs *aux,uint size,uint size1)
{
    uint lungime=size+size1;
    uint j=0;
    
    for(uint i=size;i<lungime;i++)
    {
        v[i]=aux[j++];
    }
}

void afisare(Produs *v,uint size,FILE *f)
{
    for(uint i=0;i<size;i++)
    {
        if(!strcasecmp(v[i].tip,"carte"))
            fprintf(f,"%s - %s - %d - %d - %d - %d - %s - %s\n",v[i].titlu,v[i].autor,v[i].nr_exemplare,v[i].pret,v[i].nr_pagini,v[i].greutate,v[i].tip,v[i].caract.isbn);
        else
            fprintf(f,"%s - %s - %d - %d - %d - %d - %s - %d\n",v[i].titlu,v[i].autor,v[i].nr_exemplare,v[i].pret,v[i].nr_pagini,v[i].greutate,v[i].tip,v[i].caract.an);

    }
}

void conditie(Produs *v,uint size)
{
    Produs *rez=NULL;
    uint new=0;
    rez=(Produs*)malloc(size*sizeof(Produs));
    if(rez==NULL)
    {
        printf("Eroare la alocare pt rezultat\n");
        perror(NULL);
        exit(-1);
    }
    for(uint i=0;i<size;i++)
    {
        if(v[i].pret>100)
        {
            rez[new++]=v[i];
        }
    }
    rez=(Produs*)realloc(rez,new*sizeof(Produs));
    afisare(rez,new,stdout);
    free(rez);
}

int main(void)
{
    FILE *fout=NULL;
    uint size=0;
    printf("Cate elemente sa fie introduse initial:");
    scanf("%d",&size);
    Produs *v=NULL;
    v=(Produs*)malloc(size*sizeof(Produs));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v,size);

    if((fout=fopen(file_path,"wb"))==NULL)
    {
        printf("Nu s-a putut deschide fisierul de rezultate\n");
        perror(NULL);
        free(v);
        exit(-1);
    }
    while(1)
    {
        opt optiune;
        uint o=0,size1=0;
        printf("Scrieti 0 daca doriti sa introduceti produse, 1 daca doriti sa afisati produsele sub 100 de lei, 2 daca vreti sa afisati toate publicatiile si 3 daca vreti ca datele sa fie introduse intr un fisier binar: ");
        scanf("%d",&o);
        optiune=o;
        switch(optiune)
        {
            case INTRODUCERE:
            {
                printf("Cate elemente vreti sa adaugati:");
                scanf("%d",&size1);
                Produs *aux=(Produs*)malloc(size1*sizeof(Produs));
                if(aux==NULL)
                {
                    printf("Nu s a putut aloca o variabila auxiliara\n");
                    perror(NULL);
                    exit(-1);
                }
                citire(aux,size1);
                Produs *temp=(Produs*)realloc(v,(size+size1)*sizeof(Produs));
                if(temp==NULL)
                {
                    printf("Eroare la realocare\n");
                    perror(NULL);
                    exit(-1);
                }
                v=temp;
                inserare(v,aux,size,size1);
                free(aux);
                size+=size1;
                break;
            }
            case AFISARE_COND:
            {
                conditie(v,size);
                break;
            }
            case AFISARE:
            {
                afisare(v,size,stdout);
                break;
            }
            case SALVARE:
            {
                afisare(v,size,fout);
                if(fclose(fout)!=0)
                {
                    printf("Nu se poate inchide fisierul\n");
                    perror(NULL);
                    free(v);
                    exit(-1);
                }
                free(v);
                return 0;
                break;
            }
        }
    }
}