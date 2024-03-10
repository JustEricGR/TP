// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

void eliberare(int **v,int size)
{
    for(int i=0;i<size;i++)free(v[i]);
    free(v);
}

void citire(int **v,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        v[i]=(int*)malloc(n*sizeof(int));
        if(v[i]==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            exit(-1);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }
}

void afisare(int **v,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }printf("\n");
}

void inmultire(int **v1,int size11,int size12,int **v2,int size22)
{
    int **rez=NULL;
    rez=(int**)malloc(size11*sizeof(int*));
    if(rez==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size11;i++)
    {
        rez[i]=(int*)malloc(size22*sizeof(int));
        if(rez[i]==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            exit(-1);
        }
        for(int j=0;j<size22;j++)
        {
            rez[i][j]=0;
            for(int k=0;k<size12;k++)
            {
                
                rez[i][j]+=v1[i][k]*v2[k][j];
                
            }
        }
    }
    afisare(rez,size11,size22);
    eliberare(rez,size11);
}

int main(void) {
    int size11=0, size12=0,size22=0;
    printf("Nr de linii pt matricea1:");
    scanf("%d",&size11);
    printf("Nr de coloane pt matricea1:");
    scanf("%d",&size12);
    int **v1=NULL;
    v1=(int**)malloc(size11*sizeof(int*));
    if(v1==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v1,size11,size12);
    afisare(v1,size11,size12);
    
    printf("Nr de coloane din matricea2:");
    scanf("%d",&size22);
    int **v2=NULL;
    v2=(int**)malloc(size12*sizeof(int*));
    if(v2==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v2,size12,size22);
    afisare(v2,size12,size22);
    
    printf("Inmultirea este egala cu:\n");
    inmultire(v1,size11,size12,v2,size22);
    
    eliberare(v1,size11);
    eliberare(v2,size12);
    return 0;
}