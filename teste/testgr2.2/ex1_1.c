#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

float *medie(int n,...)
{
    va_list va;
    va_start(va,n);
    float *rez=(float*)malloc(n*sizeof(float));
    if(rez==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        rez[i]=va_arg(va,double)/n;
    }
    va_end(va);
    return rez;
}

void afisare(float *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%.2f ",v[i]);
    }printf("\n");
}

int main(void)
{
    float *v=medie(4,44.0,10.0,9.0,5.0);
    afisare(v,4);
    free(v);
}