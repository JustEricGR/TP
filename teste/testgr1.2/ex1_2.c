#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<math.h>

uint *patrat(uint n,...)
{
    uint *rez=(uint*)malloc(n*sizeof(uint));
    if(rez==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    va_list va;
    va_start(va,n);
    for(uint i=0;i<n;i++)
    {
        rez[i]=pow(va_arg(va,int),2);
    }
    return rez;
}

void afisare(uint *v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

int main(void)
{
    uint *rez=patrat(5,4,7,9,5,11);
    afisare(rez,5);
    free(rez);

}