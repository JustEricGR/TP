#include<stdio.h>
#include<stdlib.h>

int cond(int n)
{
    return n%2==0;
}

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
    nod *c=NULL;
    for(c=lista;c->urm!=NULL;c=c->urm)
    {}
    c->urm=nou(n,NULL);
    return lista;
}

void afisare(nod *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
    }printf("\n");
}

nod *stergere(nod *lista,int (*fct)(int))
{
    nod *pred=NULL,*crt=NULL;
    for(pred=NULL,crt=lista;crt;pred=crt,crt=crt->urm)
    {
        if(fct(crt->n))
        {
            if(pred==NULL)
            {
                lista=lista->urm;
            }
            else
            {
                pred->urm=crt->urm;
                free(crt);
                crt=pred;
            }
            
        }
        
    }
    
    return lista;
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

int main(void)
{
    uint size=0;
    nod *lista=NULL;
    printf("Cate elemente are lista:");
    scanf("%d",&size);
    for(uint i=0;i<size;i++)
    {
        int nr=0;
        scanf("%d",&nr);
        lista=adaugaSfarsit(lista,nr);
    }

    afisare(lista);
    lista=stergere(lista,cond);
    afisare(lista);
    eliberare(lista);
}