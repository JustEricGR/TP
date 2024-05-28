#include<stdio.h>
#include<stdlib.h>

int v[10],n=0,volumFinal=0;

int *citire(int *volume)
{
    volume=(int*)malloc(n*sizeof(int));
    if(volume==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&volume[i]);
    }
    return volume;
}

void afisare(int k)
{
    for(int i=0;i<=k;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

int valid(int k)
{
    int suma=0;
    for(int i=0;i<=k;i++)
    {
        suma+=v[i];
    }

    for(int i=0;i<k;i++)
    {
        if(v[i]==v[k])return 0;
    }
    return suma<=volumFinal;
}

int solutie(int k)
{
    int suma=0;
    for(int i=0;i<=k;i++)
    {
        suma+=v[i];
    }
    return suma==volumFinal;
}

void back(int k,int *volume)
{
    for(int i=0;i<n;i++)
    {
        v[k]=volume[i];
        if(valid(k))
        {
            if(solutie(k))
            {
                afisare(k);
            }
            else
            {
                back(k+1,volume);
            }
        }
    }
}

int main(void)
{
    printf("Cate obiecte sunt:");
    scanf("%d",&n);
    int *volume=NULL;
    volume=citire(volume);
    printf("Ce volum trebuie umplut:");
    scanf("%d",&volumFinal);
    back(0,volume);
    free(volume);
}