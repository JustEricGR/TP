#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
    struct elem *urm;
    int n;
}elem;

elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(e==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    e->urm=urm;
    e->n=n;
    return e;
}

elem *adaugaSfarsit(elem *lista,int n)
{
    if(lista==NULL)
    {
        return nou(n,lista);
    }

    elem *c=NULL;
    for(c=lista;c->urm!=NULL;c=c->urm)
    {}
    c->urm=nou(n,NULL);
    return lista;
}

elem *stergere(elem *lista,int n)
{
    elem *pred=NULL,*crt=NULL;
    for(pred=NULL,crt=lista;crt;pred=crt,crt=crt->urm)
    {
        if(crt->n==n)
        {
            if(pred==NULL)
            {
                lista=lista->urm;
            }
            else
            {
                pred->urm=crt->urm;
            }
        }
    }        
    free(crt);
    return lista;
}

void afisare(elem *lista)
{
    for(elem *c=lista;c!=NULL;c=c->urm)
    {
        printf("%d ",c->n);
    }printf("\n");
}

elem *adaugaInceput(elem *lista,int n)
{
    return nou(n,lista);
}

void permutare(elem **lista,uint poz)
{
    uint size=0;
    for(elem *c=*lista;c!=NULL;c=c->urm)
    {
        size++;
    }
    int *numere=(int*)malloc((size-poz)*sizeof(int));
    if(numere==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    
    elem *c=*lista;
    for(uint i=0;i<poz;i++)
    {
        c=c->urm;
    }

    for(uint i=0;i<size-poz;i++)
    {
        numere[i]=c->n;
        *lista=stergere(*lista,numere[i]);
        c=c->urm;
    }


    for(uint i=0;i<size-poz;i++)
    {
        *lista=adaugaInceput(*lista,numere[i]);
    }
    free(numere);
}

void eliberare(elem *lista)
{
    elem *p=NULL;
    while(lista!=NULL)
    {
        p=lista->urm;
        free(lista);
        lista=p;
    }
}

int main(void)
{
    uint size=0;
    elem *lista=NULL;
    printf("Cate elemente sa se citeasca:");
    scanf("%d",&size);
    for(uint i=0;i<size;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista=adaugaSfarsit(lista,n);
    }

    afisare(lista);
    uint poz=0;
    printf("De la ce pozitie sa se permute:");
    scanf("%d",&poz);
    permutare(&lista,poz);
    afisare(lista);
    eliberare(lista);
}