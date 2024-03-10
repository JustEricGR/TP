#include<stdio.h>
#include<stdlib.h>

int ordonare(const void *elem1,const void *elem2)
{
    const float *v1=(const float*) elem1;
    const float *v2=(const float*) elem2;
    if(*v1<*v2)return -1;
    if(*v1>*v2)return 1;
    return 0;
}

void citire(float *v,int size)
{
    for(int i=0;i<size;i++)
    {
        scanf("%g",&v[i]);
    }
}

void afisare(float *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%g ",v[i]);
    }printf("\n");
}

int main(void)
{
    int size=0;
    float val=0;
    printf("Introduceti dimensiunea vectorului:");
    scanf("%d",&size);
    float *v=NULL;
    v=(float*)malloc(size*sizeof(float));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v,size);
    qsort(v,size,sizeof(float),ordonare);
    afisare(v,size);
    printf("Dati o valoare care sa fie cautata:");
    scanf("%g",&val);
    int *rez=(int*)bsearch(&val,v,size,sizeof(float),ordonare);
    if(rez!=NULL)
    {
        printf("Valoarea %g a fost gasita la %p\n",val,rez);
    }
    else
    {
        printf("Nu s a gasit\n");
    }
    free(v);
}