#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct nod{
    uint n;
    struct nod *pred;
    struct nod *urm;
}nod;

nod *nod_nou(uint nr)
{
    nod *e=(nod*)malloc(sizeof(nod));
    if(e==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    e->n=nr;
    return e;
}

typedef struct{
    nod *prim;
    nod *ultim;
}lista;

void lista_init(lista *l)
{
    l->prim=l->ultim=NULL;
}

void adauga(lista *l,nod *n)
{
    n->pred=l->ultim;
    if(l->ultim)
    {
        l->ultim->urm=n;
    }
    else
    {
        l->prim=n;
    }
    l->ultim=n;
    n->urm=NULL;
}

void afisare(lista l)
{
    for(nod *c=l.prim;c;c=c->urm)
    {
        printf("%d ",c->n);
    }printf("\n");
}

void eliberare(lista *l)
{
    nod *c=NULL,*urm=NULL;
    for(c=l->prim;c;c=urm)
    {
        urm=c->urm;
        free(c);
    }
}


uint compunere(lista l,uint size)
{
    uint parcurg=size/2;
    uint exp=parcurg-1;
    uint a=0,b=0;
    nod *c1=l.prim,*c2=l.ultim;

    for(uint i=0;i<parcurg;i++)
    {
        a+=pow(10,exp--)*c1->n;
        c1=c1->urm;
    }
    exp=parcurg-1;
    for(uint i=0;i<parcurg;i++)
    {
        b+=pow(10,exp--)*c2->n;
        c2=c2->pred;
    }
    
    return a==b;
}

int main(void)
{
    uint size=0;
    lista l;
    lista_init(&l);
    printf("Cate elemente are lista:");
    scanf("%d",&size);
    for(uint i=0;i<size;i++)
    {
        uint nr=0;
        nod *n=NULL;
        scanf("%d",&nr);
        if((nr/10)!=0)
        {
            printf("Numarul trebuie sa fie mai mic decat 10\n");
            eliberare(&l);
            return 0;
        }
        n=nod_nou(nr);
        adauga(&l,n);
    }

    afisare(l);
    uint flag=compunere(l,size);
    if(flag)
    {
        printf("Este palindrom\n");
    }
    else
    {
        printf("Nu este palindrom\n");
    }
    eliberare(&l);
}