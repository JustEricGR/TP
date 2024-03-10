#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int codPers;
    int codPrieten[20];
}friend;

//am modificat putin cerinta

int *citire(friend *v,int nrPers)
{
    int *nrPrieteni=NULL;
    nrPrieteni=(int*)malloc(nrPers*sizeof(int));
    if(nrPrieteni==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<nrPers;i++)
    {
        v[i].codPers=i+1;
        printf("Cati prieteni are %d?",v[i].codPers);
        scanf("%d",&nrPrieteni[i]);
        
        printf("Introduceti %d numere care sunt codul prietenului\n",nrPrieteni[i]);

        printf("Prietenii lui %d sunt:",v[i].codPers);
        for(int j=0;j<nrPrieteni[i];j++)
        {
            scanf("%d",&v[i].codPrieten[j]);
        }
    }
    return nrPrieteni;

}

void afisare(friend *v,int nrPers,int *nrPrieteni)
{
    
    for(int i=0;i<nrPers;i++)
    {
        for(int j=0;j<nrPrieteni[i];j++)
        {
            printf("%4d",v[i].codPrieten[j]);
        }printf("\n");
    }printf("\n");
}

int main(void)
{
    int nrPers=0;
    printf("Cate persoane sunt?");
    scanf("%d",&nrPers);
    friend *v=NULL;
    v=(friend*)malloc(nrPers*sizeof(friend));
        if(v==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            exit(-1);
        }
    int *nrPrieteni=NULL;
    nrPrieteni=citire(v,nrPers);
    afisare(v,nrPers,nrPrieteni);
    free(v);
    free(nrPrieteni);
    
    

}