#include<stdio.h>
#include<stdarg.h>

int crescator(int n,char f,...)
{
    int rez[n];
    float rez1[n];
    va_list va;
    va_start(va,f);
    switch(f)
    {
        case 'd':
        {
            for(int i=0;i<n;i++)
            {
                rez[i]=va_arg(va,int);
            }

            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(rez[i]>rez[j])return 0;
                }
            }
        }
        case 'f':
        {
            for(int i=0;i<n;i++)
            {
                rez1[i]=va_arg(va,double);
            }

            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(rez1[i]>rez1[j])return 0;
                }
            }
        }
    }
    va_end(va);
    return 1;
}

int main(void)
{
    int size=0;
    char c=0;
    printf("Cate elemente sa se citeasca:");
    scanf("%d",&size);
    printf("Intoduceti litera d pt elemente int si f pt float:");
    scanf(" %c",&c);
    if(c=='d')
    {
        int v[size];
        for(int i=0;i<size;i++)
        {
            scanf("%d",&v[i]);
        }
        int flag=crescator(size,c,v[0],v[1],v[2],v[3]);
        if(flag)printf("Ordine crescatoare\n");
        else
            printf("Nu sunt\n");
    }
    if(c=='f')
    {
        float v[size];
        for(int i=0;i<size;i++)
        {
            scanf("%f",&v[i]);
        }
        int flag=crescator(size,c,v[0],v[1],v[2],v[3]);
        if(flag)printf("Ordine crescatoare\n");
        else
            printf("Nu sunt\n");
    }
    
}