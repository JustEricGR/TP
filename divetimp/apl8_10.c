#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int a,b;
}IntervalMasurare;

typedef struct{
    int a,b;
}IntervalLuminare;

IntervalMasurare *citire1(IntervalMasurare *v,uint nrMasuratori)
{
    v=(IntervalMasurare*)malloc(nrMasuratori*sizeof(IntervalMasurare));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(uint i=0;i<nrMasuratori;i++)
    {
        scanf("%d %d",&v[i].a,&v[i].b);
    }
    return v;
}

IntervalLuminare *citire2(IntervalLuminare *v,uint nrProiectoare)
{
    v=(IntervalLuminare*)malloc(nrProiectoare*sizeof(IntervalLuminare));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(uint i=0;i<nrProiectoare;i++)
    {
        scanf("%d %d",&v[i].a,&v[i].b);
    }
    return v;
}

void calcul(IntervalMasurare *v1,uint nrMasuratori,IntervalLuminare *v2,uint nrProiectoare)
{
    for(uint i=0;i<nrMasuratori;i++)
    {
        uint a=v1[i].a,b=v1[i].b,c=0,d=0;
        uint max=0;
        for(uint j=0;j<nrProiectoare;j++)
        {
            c=v2[j].a;
            d=v2[j].b;
            uint len=0;
            // printf("a=%d b=%d c=%d d=%d\n",a,b,c,d);
            // if(a<=c && d<=b)len=d-c;
            // else if(c<a && d<b)len=d-a;
            // else if(c<a && b<d)len=b-a;
            // else if(a<c && b<d)len=b-c;
            // else if(a==c && b<d)len=b-c;
            // else if(a==c && b>d)len=d-c;
            // else if(a<c && b==d)len=b-c;
            // else if(a>c && b==d)len=b-a;
            // else len=0;
            int start = 0;
            if(a>c)start=a;
            else start=c;
            int end = 0;
            if(b<d)end=b;
            else end=d;

            if (start < end) 
            {
                len = end - start;
                if (len > max) 
                {
                    max = len;
                }
            }
            if(len>max)max=len;
        }
        printf("%d\n",max);
    }
}

int main(void)
{
    uint nrMasuratori=0,nrProiectoare=0;
    IntervalMasurare *v1=NULL;
    IntervalLuminare *v2=NULL;
    scanf("%d %d",&nrProiectoare,&nrMasuratori);
    
    v2=citire2(v2,nrProiectoare);
    v1=citire1(v1,nrMasuratori);
    // for(uint i=0;i<nrProiectoare;i++)
    // {
    //     printf("%d %d\n",v1[i].a,v1[i].b);
    // }
    // for(uint i=0;i<nrMasuratori;i++)
    // {
    //     printf("%d %d\n",v1[i].a,v1[i].b);
    // }

    calcul(v1,nrMasuratori,v2,nrProiectoare);
    free(v1);
    free(v2);
}