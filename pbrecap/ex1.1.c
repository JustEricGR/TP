#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

typedef enum{
    CEAI,
    IMBRACAMINTE,
    PODOABE,
    SUVENIRURI
}Magazin;

typedef union{
    char tara[30];
    char gen[15];
    uint nrkarate;
    uint pret;
}Caracteristici;

typedef struct Bazar{
    char tip[30];
    Magazin type;
    Caracteristici caract;
    uint nrmagazin;
    char nume[30];
    uint dimensiune;
    struct Bazar *urm;
}Bazar;

Bazar *citire(Bazar *v)
{
    v=(Bazar*)malloc(sizeof(Bazar));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    printf("Introduceti tipul magazinului:");
    scanf("%29s",v->tip);
    if(!strcasecmp(v->tip,"ceai"))v->type=0;
    else if(!strcasecmp(v->tip,"imbracaminte"))v->type=1;
    else if(!strcasecmp(v->tip,"podoabe"))v->type=2;
    else if(!strcasecmp(v->tip,"suveniruri"))v->type=3;
    else exit(-1);
    switch(v->type)
    {
        case CEAI:
        {
            printf("Introduceti tara de origine a ceaiului:");
            scanf("%29s",v->caract.tara);
            break;
        }
        case IMBRACAMINTE:
        {
            printf("Scrieti daca imbracamintea e pt barbati, femei sau copii:");
            scanf("%14s",v->caract.gen);
            break;
        }
        case PODOABE:
        {
            printf("Scrieti cate karate au podoabele din magazin:");
            scanf("%d",&v->caract.nrkarate);
            break;
        }
        case SUVENIRURI:
        {
            printf("Introduceti pretul celui mai scump produs:");
            scanf("%d",&v->caract.pret);
            break;
        }
        default:
        {
            printf("Nedeterminat\n");
            break;
        }
    }
    srand(time(NULL));
    v->nrmagazin=rand()%5000;
    printf("Introduceti numele magazinului:");
    scanf("%29s",v->nume);
    v->dimensiune=rand()%100;
    v->urm=NULL;
    return v;
}

Bazar *nou(Bazar *lista,Bazar *nod)
{
    if(lista==NULL)
    {
        lista=nod;
        return lista;
    }
    Bazar *c=lista;
    for(;c->urm!=NULL;c=c->urm)
    {}
    c->urm=nod;
    return lista;
}

void afisare(Bazar *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("Tip magazin:%s, ",lista->tip);
        switch(lista->type)
        {
            case CEAI:
            {
                lista->caract.tara[0]=toupper(lista->caract.tara[0]);
                printf("tara de origine a ceaiului:%s, ",lista->caract.tara);
                break;
            }
            case IMBRACAMINTE:
            {
                printf("pentru %s, ",lista->caract.gen);
                break;
            }
            case PODOABE:
            {
                printf("nr de karate:%d, ",lista->caract.nrkarate);
                break;
            }
            case SUVENIRURI:
            {
                printf("cel mai scump produs:%d, ",lista->caract.pret);
                break;
            }
        }
        printf("nr magazinului:%d, ",lista->nrmagazin);
        printf("numele magazinului:%s, ",lista->nume);
        printf("dimensiunea:%d.\n",lista->dimensiune);
    }
}

void eliberare(Bazar *lista)
{
    Bazar *p=NULL;
    while(lista)
    {
        p=lista->urm;
        free(lista);
        lista=p;
    }
}

int main(void)
{
    int size=0;
    Bazar *lista=NULL;
    printf("Cate magazine sunt:");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        Bazar *aux=NULL;
        aux=citire(aux);
        lista=nou(lista,aux);
    }
    afisare(lista);
    eliberare(lista);
    return 0;
}