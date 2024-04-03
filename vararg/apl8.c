#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>

int cmp(const void *e1,const void *e2)
{
    int v1=*(int*)e1;
    int v2=*(int*)e2;
    if(v1>v2)return 1;
    else if(v1<v2)return -1;
    else
        return 0;
}


int *sortare(int n,...)
{
    int *v=(int*)malloc(n*sizeof(int));
    va_list va;
    va_start(va,n);
    for(int i=0;i<n;i++)
    {
        v[i]=va_arg(va,int);

    }
    va_end(va);
    qsort(v,n,sizeof(int),cmp);
    return v;
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
    int size=0;
    printf("Cate elemenete sa se citeasca:");
    scanf("%d",&size);
    int *v=(int*)malloc(size*sizeof(int));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size;i++)
    {
        scanf("%d",&v[i]);
    }
    int *rez=sortare(size,v[0],v[1],v[2],v[3]);
    afisare(rez,size);
    free(rez);
}