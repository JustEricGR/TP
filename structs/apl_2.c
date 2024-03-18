#include<stdio.h>
#include<string.h>

typedef struct{
    char nume[16];
    unsigned int dimensiune:4;
    unsigned int type1:2;
    enum{
        txt,
        docs,
        xls
    }extensie;
    unsigned int type2:1;
        
}Fisier;

void citire(Fisier v)
{
    unsigned int aux1=0,aux2=0,dim=0;
    char extensie[6]="", tip[15]="";
    scanf("%15s %d %d %d",v.nume,&dim,&aux1,&aux2);
    v.type1=aux1;
    v.type2=aux2;
    v.dimensiune=dim;
    switch(v.type1)
    {
        case 0:
            strcpy(extensie,".txt");
            break;
        case 1:
            strcpy(extensie,".docs");
            break;
        case 2:
            strcpy(extensie,".xls");
    }

    switch(v.type2)
    {
        case 0:
            strcpy(tip,"normal");
            break;
        case 1:
            strcpy(tip,"read-only");
            break;
    }
    printf("Nume fisier: %s ,dimensiune: %d extensie: %s tip %s\n",v.nume,v.dimensiune,extensie,tip);
}

int main(void)
{
    Fisier v;
    citire(v);
}