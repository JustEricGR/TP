#include<stdio.h>
#include<stdlib.h>

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

void afisare(nod *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
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

nod *stergere(nod *lista,nod *n1)
{
    nod *crt=NULL,*prev=NULL;
    for(crt=lista;crt;prev=crt,crt=crt->urm)
    {
        if(crt->n == n1->n)
        {
            if(prev)
            {
                prev->urm=crt->urm;
                free(crt);
                crt=prev;
            }
            else
            {
                
                crt=lista->urm;
                free(lista);
                lista=crt;
            }
        }
    }
    return lista;
}

nod *inversare(nod *lista,uint size)
{
    
    nod *pivot=lista,*next=lista->urm;
    //nod *prim=pivot;
    for(int i=0;i<size-1;i++)
    {
        pivot->urm=next->urm;
        int aux=next->n;
        lista=stergere(lista,next);
        lista=nou(aux,lista);
        next=pivot->urm;
    }
    return lista;
    
}

int main(void)
{
    nod *lista=NULL;
    uint size=0;
    printf("Cate elemente are lista:");
    scanf("%d",&size);
    for(uint i=0;i<size;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista=adaugaSfarsit(lista,n);
    }
    afisare(lista);
    lista=inversare(lista,size);
    afisare(lista);
    eliberare(lista);
}