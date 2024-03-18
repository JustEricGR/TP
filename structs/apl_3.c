#include<stdio.h>
#include<string.h>
#define MAX 11

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
    char nume1[6];
    char nume2[15];
        
}Fisier;

void citire(Fisier v[MAX],unsigned int size)
{
    
    for(int i=0;i<size;i++)
    {
        unsigned int aux1=0,aux2=0,dim=0;
        scanf("%15s %d %d %d",v[i].nume,&dim,&aux1,&aux2);
        v[i].type1=aux1;
        v[i].type2=aux2;
        v[i].dimensiune=dim;
        switch(v[i].type1)
        {
            case 0:
                strcpy(v[i].nume1,".txt");
                break;
            case 1:
                strcpy(v[i].nume1,".docs");
                break;
            case 2:
                strcpy(v[i].nume1,".xls");
        }

        switch(v[i].type2)
        {
            case 0:
                strcpy(v[i].nume2,"normal");
                break;
            case 1:
                strcpy(v[i].nume2,"read-only");
                break;
        }
    }
    
    
}

void afisare(Fisier v[MAX],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("Nume fisier: %s; dimensiune: %d; extensie: %s; tip %s\n",v[i].nume,v[i].dimensiune,v[i].nume1,v[i].nume2);
    }
}

int main(void)
{
    unsigned int size=0;
    printf("Cate elemente sa se citeasca:");
    scanf("%d",&size);
    Fisier v[MAX];
    citire(v,size);
    afisare(v,size);
}