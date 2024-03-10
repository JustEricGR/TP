#include<stdio.h>
#include<stdlib.h>

int cond(int n)
{
    return n%2==0;
}


void filter(int *v,int size,int *newSize,int (*fct)(int))
{
    for(int i=0;i<size;i++)
    {
        if(!fct(v[i]))
        {
            for(int j=i+1;j<size;j++)
            {
                v[j-1]=v[j];
            }
            size--;
            i--;
        }
    }
    *newSize=size;

}

void citire(int *v, int size)
{
    for(int i=0;i<size;i++)
    {
        scanf("%d",&v[i]);
    }
}

void afisare(int *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}


int main(void)
{
    int size=0,newSize=0;
    printf("Introduceti marimea vectorului:");
    scanf("%d",&size);
    int *v=NULL;
    v=(int*)malloc(size*sizeof(int));
    if(v==NULL)
    {
        printf("Eroare la afisare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v,size);
    filter(v,size,&newSize,cond);
    afisare(v,newSize);
    free(v);
}