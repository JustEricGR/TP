#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void citire(char *orase[],int size)
{
    for(int i=0;i<size;i++)
    {
        orase[i] = (char *)malloc(20 * sizeof(char));
        if (orase[i] == NULL) {
            printf("Eroare la alocare\n");
            perror(NULL);
            exit(-1);
        }

        printf("Oras %d:",i);
        scanf("%19s",orase[i]);

    }
}

void afisare(char *v[],int size)
{
    for(int i=0;i<size;i++)
    {
        puts(v[i]);
    }
}

void afisare1(int **v,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }
}

void distanta(int **v,int size)
{
    int m=size,n=size;
    //int **v=NULL;
    v=(int**)malloc(size*sizeof(int*));
    if (v == NULL) 
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    int v1[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&v1[i]); 
    }

    for(int i=0;i<size;i++)
    {
        
        v[i]=(int*)malloc(size*sizeof(int));
        if (v[i] == NULL) 
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            exit(-1);
        }
            for(int j=0;j<size;j++)
            {
                v[i][j]=v[j][i];

                if(i==j)
                {
                    v[i][j]=0;
                }
                else
                {
                    /*v[0][j]=v1[j];
                    v[i][j]=v[j][i];*/
                    //scanf("%d",&v[i][j]);
                    v[][j]

                }
                
                
            }
        
    }
    /*for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }*/
    afisare1(v,size);
}



int main(void)
{
    int size=0;
    printf("Dimensiune:");
    scanf("%d",&size);
    char *v[size];
    int **v1=NULL;
    v1 = (int **)malloc(size * sizeof(int *));
    if (v1 == NULL) {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    for (int i = 0; i < size; i++) {
        v1[i] = (int *)malloc(size * sizeof(int));
        if (v1[i] == NULL) {
            printf("Eroare la alocare\n");
            perror(NULL);
            exit(-1);
        }
    }
    citire(v,size);
    afisare(v,size);
        
    distanta(v1,size);
    //afisare1(v1,size);
    for(int i=0;i<size;i++)
    {
        free(v[i]);
        free(v1[i]);
    }
    free(v1);
        
}