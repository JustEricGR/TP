#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 11
#define file_path "memorie.txt"

typedef enum{
    TXT,
    DOCS,
    XLS
}extensie;

typedef enum{
    NORMAL,
    READ_ONLY
}prop;

typedef struct{
    char nume[16];
    unsigned int dimensiune:10;
    extensie ex;
    char nume1[6];
    prop proprietate;
    char nume2[15];
        
}Fisier;

void citire(Fisier v[MAX],uint size)
{
    srand(time(NULL));
    
    for(uint i=0;i<size;i++)
    {
        uint aux1=0,aux2=0,dim=0;
        printf("Introduceti numele fisierului %d:",i+1);
        scanf("%15s",v[i].nume);
        dim=rand()%1024;
        v[i].dimensiune=dim;
        printf("Introduceti 0 pt fisier .txt, 1 pt .docs, 2 pt .xls:");
        scanf("%d",&aux1);
        v[i].ex=aux1;
        switch(v[i].ex)
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
        printf("Introduceti 0 pt fisier normal si 1 pt read-only:");
        scanf("%d",&aux2);
        v[i].proprietate=aux2;
        switch(v[i].proprietate)
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

void afisare(Fisier v[MAX],uint size,FILE *f)
{
    for(uint i=0;i<size;i++)
    {
        fprintf(f,"Nume fisier: %s; dimensiune: %d; extensie: %s; tip %s\n",v[i].nume,v[i].dimensiune,v[i].nume1,v[i].nume2);
    }
}

int main(void)
{
    unsigned int size=0;
    printf("Cate elemente sa se citeasca:");
    scanf("%d",&size);
    Fisier v[MAX];
    citire(v,size);
    FILE *fout=NULL;
    if((fout=fopen(file_path,"w"))==NULL)
    {
        printf("Nu s-a putut deschide fisierul");
        perror(NULL);
        exit(-1);
    }
    afisare(v,size,fout);
    if(fclose(fout)!=0)
    {
        printf("Nu s-a putut inchide fisierul\n");
        perror(NULL);
        exit(-1);
    }
}