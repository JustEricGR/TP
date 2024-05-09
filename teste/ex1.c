#include<stdio.h>
#include<stdlib.h>

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

nod *cautare(lista l,int n)
{
    nod *c=NULL;
    for(c=l.prim;c;c=c->urm)
    {
        if(c->n == n)
        {
            return c;
        }
    }
    return NULL;
}

void stergere(lista *l,nod *n)
{
    if(n->pred)
    {
        n->pred->urm=n->urm;
    }
    else
    {
        l->prim=n->urm;
    }
    if(n->urm)
    {
        n->urm->pred=n->pred;
    }
    else
    {
        l->ultim=n->pred;
    }
    free(n);
}

// void ordonare(lista *l)
// {
//     nod *aux=NULL;
//     uint flag=0;
//     for(nod *c=l->prim;c->urm!=NULL;c=c->urm)
//     {
//         for(nod *c1=c->urm;c1;c1=c1->urm)
//         {
//             if(c->n > c1->n)
//             {
//                 aux=nod_nou(c->n);
//                 stergere(l,c);
//                 nod *c2=c1;
//                 while((c2->n < c->n) || c2==NULL)
//                 {
//                     if((c2->n < c->n) && c2->urm)
//                     {
//                         //adauga(l,aux);
//                         aux->urm=c2->urm;
//                         aux->pred=c2;
//                         c2->urm=aux;
//                         flag++;
//                         afisare(*l);
//                         break;
//                     }
//                     else if(c2->urm==NULL)
//                     {
//                         aux->pred=l->ultim;
//                         l->ultim->urm=aux;
//                         aux->urm=NULL;
//                         flag++;
//                         afisare(*l);
//                         break;
//                     }
//                     c2=c2->urm;
                    
//                 }
//                 if(flag)break;
//             }
//         }
//     }
// }

void ordonare(lista *l)
{
    nod *aux=NULL;
    uint flag=0;
    for(nod *c=l->prim;c->urm!=NULL;c=c->urm)
    {
        for(nod *c1=c->urm;c1;c1=c1->urm)
        {
            if(c->n > c1->n)
            {
                aux=nod_nou(c->n);
                stergere(l,c);
                nod *c2=c1;
                while((c2->n < c->n) || c2==NULL)
                {
                    if(c2->n < c->n)
                    {
                        if(c2->urm)
                        {
                            aux->urm=c2->urm;
                            aux->pred=c2;
                            c2->urm=aux;
                            flag++;
                            break;
                        }
                        else
                        {
                            adauga(l,aux);
                            flag++;
                            break;
                        }
                        
                    }
                    
                    
                    
                }
                if(flag)break;
            }
        }
    }
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

int main(void)
{
    uint size=0;
    lista l;
    lista_init(&l);
    printf("Cate elemente are lista:");
    scanf("%d",&size);
    for(uint i=0;i<size;i++)
    {
        int nr=0;
        nod *n=NULL;
        scanf("%d",&nr);
        n=nod_nou(nr);
        adauga(&l,n);
    }
    afisare(l);
    ordonare(&l);
    afisare(l);
    eliberare(&l);
}