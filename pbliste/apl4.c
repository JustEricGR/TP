#include<stdio.h>
#include<stdlib.h>

int cond(int n)
{
    return n%2==0;
}

typedef struct nod{
    int n;
    struct nod *pred;
    struct nod *urm;
}nod;

nod *nod_nou(int n)
{
    nod *e=(nod*)malloc(sizeof(nod));
    if(e==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    e->n=n;
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


void adaugare(lista *l,nod *n)
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

void interschimbare(lista *l,uint size)
{
    nod *c=l->prim;
    for(uint i=0;i<size;i+=2)
    {
        nod *c1=c->urm;
        int aux=c->n;
        c->n = c1->n;
        c1->n = aux;
        c=c->urm->urm;
    }
}

void afisare(lista l)
{
    for(nod *n1=l.prim;n1;n1=n1->urm)
    {
        printf("%d ",n1->n);
    }printf("\n");
}

void eliberare(lista *l)
{
    nod *p=NULL,*urm=NULL;
    for(p=l->prim;p;p=urm)
    {
        urm=p->urm;
        free(p);
    }
    lista_init(l);
}

int main(void)
{
    uint size=0;
    lista l;
    lista_init(&l);
    printf("Cate elemente sa aiba lista:");
    scanf("%d",&size);
    int (*fct)(int)=cond;
    if(!fct(size))
    {
        printf("Nu este nr par\n");
        return 0;
    }

    else
    {
        for(uint i=0;i<size;i++)
        {
            nod *n=NULL;
            int nr=0;
            scanf("%d",&nr);
            n=nod_nou(nr);
            adaugare(&l,n);
        }
        afisare(l);
        interschimbare(&l,size);
        afisare(l);
        eliberare(&l);
    }
    
}