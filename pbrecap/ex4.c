#include<stdio.h>
#include<stdlib.h>
#define IN "DOMINO.IN"
#define OUT "ARANJARI.TXT"

typedef struct{
    int a,b;
}Domino;

int n=6,x=3;
Domino v[10];

Domino *citire(Domino *piese)
{
    FILE *fin=NULL;
    if((fin=fopen(IN,"r"))==NULL)
    {
        printf("Eroare la deschidere fisier in\n");
        perror(NULL);
        exit(-1);
    }
    piese=(Domino*)malloc(n*sizeof(Domino));
    if(piese==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%d %d\n",&piese[i].a,&piese[i].b);
    }
    if(fclose(fin))
    {
        printf("Eroare la inchidere fisier in\n");
        perror(NULL);
        free(piese);
        exit(-1);
    }
    return piese;
}

void afisare()
{
    for(int i=0;i<x;i++)
    {
        printf("%d %d ",v[i].a,v[i].b);
    }printf("\n");
}

Domino rotire(Domino d)
{
    int aux=0;
    aux=d.a;
    d.a=d.b;
    d.b=aux;
    return d;
}

int valid(int k)
{
    for(int i=0;i<k;i++)
    {
        if(v[i].a == v[k].a && v[i].b == v[k].b)return 0;
    }
    //int counter=0;
    // Domino pred={0,0};
    // pred.a=v[0].a;
    // pred.b=v[0].b;
    // for(int i=1;i<=k;i++)
    // {
    //     if(pred.b != v[i].a)return 0;
    //     pred.a=v[i].a;
    //     pred.b=v[i].b;
    // }
    return 1;
}

int solutie(int k)
{
    Domino pred={0,0};
    pred.a=v[0].a;
    pred.b=v[0].b;
    for(int i=1;i<=k;i++)
    {
        if(pred.b != v[i].a)return 0;
        pred.a=v[i].a;
        pred.b=v[i].b;
    }
    return k == x-1;
}

void back(int k,Domino *piese)
{
    for(int i=0;i<n;i++)
    {
        v[k].a=piese[i].a;
        v[k].b=piese[i].b;
        if(valid(k))
        {
            if(solutie(k))
            {
                afisare();
            }
            else
            {
                
                v[k]=rotire(v[k]);
                //printf("v[%d]:%d;%d\n",k,v[k].a,v[k].b);
                if(valid(k))
                {
                    if(solutie(k))
                    afisare();
                    else
                        back(k+1,piese);
                }
                
            }
        }
    }
}

int main(void)
{
    Domino *piese=NULL;
    piese=citire(piese);
    back(0,piese);
    free(piese);
}
