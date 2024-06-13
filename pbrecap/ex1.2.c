#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define IN "tp.txt"
#define OUT "rezultate.out"

typedef struct Student{
    char nume[30];
    char prenume[30];
    uint notalab;
    uint notaexamen;
    uint notafinala;
    struct Student *urm;
}Student;

Student *nou(Student *lista,Student *v)
{
    if(lista==NULL)
    {
        lista=v;
        return lista;
    }

    Student *c=lista;
    for(;c->urm!=NULL;c=c->urm)
    {}
    c->urm=v;
    return lista;
}

Student *citire(Student *lista,Student *v)
{
    
    FILE *fin=NULL,*fout=NULL;
    if((fin=fopen(IN,"r"))==NULL)
    {
        printf("Eroare la deschidere fisier in\n");
        perror(NULL);
        exit(-1);
    }
    uint nrStudenti=0;
    Student aux;
    while(1)
    {
        if(fscanf(fin,"%29s %29s %d %d",aux.nume,aux.prenume,&aux.notalab,&aux.notaexamen)!=4)break;
        nrStudenti++;
        aux.notafinala=(aux.notalab+aux.notaexamen)/2;
        v=(Student*)malloc(sizeof(Student));
        if(v==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            exit(-1);
        }
        strcpy(v->nume,aux.nume);
        strcpy(v->prenume,aux.prenume);
        v->notalab=aux.notalab;
        v->notaexamen=aux.notaexamen;
        v->notafinala=aux.notafinala;
        v->urm=NULL;
        lista=nou(lista,v);
        //break;
    }
    if((fout=fopen(OUT,"wb"))==NULL)
    {
        printf("Eroare la deschidere fisier iesire\n");
        perror(NULL);
        exit(-1);
    }
    printf("nrstudenti:%d\n",nrStudenti);
    fwrite(&nrStudenti,1,sizeof(uint),fout);

    if(fclose(fout))
    {
        printf("Eroare la inchidere fisier out\n");
        perror(NULL);
        exit(-1);
    }

    if(fclose(fin))
    {
        printf("Eroare la inchidere fisier in\n");
        perror(NULL);
        exit(-1);
    }
    return lista;
}

void afisare(Student *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%s - %d\n",lista->nume,lista->notafinala);
    }
}

void eliberare(Student *lista)
{
    Student *p=NULL;
    while(lista)
    {
        p=lista->urm;
        free(lista);
        lista=p;
    }
}

int main(void)
{
    Student *lista=NULL,*v=NULL;
    lista=citire(lista,v);
    afisare(lista);
    eliberare(lista);
}