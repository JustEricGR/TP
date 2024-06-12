#include<stdio.h>
#include<stdlib.h>

typedef struct nod{
    unsigned char nr;
    struct nod *urm;
}nod;

nod *nou(int nr,nod *urm)
{
    nod *e=(nod*)malloc(sizeof(nod));
    if(e==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    e->nr=nr;
    e->urm=urm;
    return e;
}

nod *adaugaSfarsit(nod *lista,int nr)
{
    if(lista==NULL)
    {
        return nou(nr,NULL);
    }

    nod *c=lista;
    for(;c->urm!=NULL;c=c->urm)
    {}
    c->urm=nou(nr,NULL);
    return lista;
}

void afisare(nod *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%c ",lista->nr);
    }printf("\n");
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

int verificare(nod *lista)
{
    nod *c=lista;
    uint counter=1;
    switch(c->nr)
    {
        case '(':
        {
            for(;c;c=c->urm)
            {
                if(counter==5 && c->nr != ')')return 0;
                else if(counter==9 && c->nr != '-')return 0;
                if(counter>13)return 0;
                counter++; 
            }
            return 1;
        }
        default:
        {
            for(;c;c=c->urm)
            {
                if(counter==4 && c->nr != '-')return 0;
                else if(counter==8 && c->nr != '-')return 0;
                if(counter>13)return 0;
                counter++;
            }
            return 1;
        }
    }
}

int main(void)
{
    nod *lista=NULL;
    unsigned char n=0;
    while(scanf("%c",&n)==1)
    {
        lista=adaugaSfarsit(lista,n);
    }
    afisare(lista);
    int flag=0;
    flag=verificare(lista);
    if(!flag)printf("Nu respecta formatul\n");
    else printf("Respecta unul dintre formate\n");
    eliberare(lista);
}