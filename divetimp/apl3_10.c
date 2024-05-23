#include<stdio.h>
#include<stdlib.h>

int *citire(int *v,uint size)
{
    v=(int*)malloc(size*sizeof(int));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    for(uint i=0;i<size;i++)
    {
        scanf("%d",&v[i]);
    }
    return v;
}

void afisare(int *v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

// int comparare(int *v1,uint size1,uint *size,int *v2,uint size2)
// {
//     uint flag=0;
//     int *aux=(int*)malloc(*size*sizeof(int));
//     for(uint i=0;i<size2;i++)
//     {
//         if(*size==1)
//         {
//             if(v1[*size-1]==v2[i])
//             {
//                 flag++;
//                 continue;
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//         if(v2[i]<v1[*size])
//         {
//             uint adder=0;
//             for(int i=0;i<*size;i++)
//             {
//                 aux[adder++]=v2[i];
//             } 
//             afisare(aux,*size);
//             *size=*size/2;
//             return comparare(v1,size1,size,aux,*size);
//         }
//         else
//         {
//             uint adder=0;
//             for(int i=*size;i<size1;i++)
//             {
//                 aux[adder++]=v2[i];
//             } 
//             afisare(aux,*size);
//             *size=*size/2;
//             return comparare(v1,size1,size,aux,*size);
//         }
//     }
//     return flag==size1;
// }

// int *binsearch(int *orig,int *v,uint *size,int n)
// {
//     int *v1=(int*)malloc((*size/2+1)*sizeof(int));

//     if(*size==1)
//     {
//         if(v[*size-1]==n)
//         {
//             return v;
//         }
//         else
//             return NULL;
//     }
//     else
//     {
//         if(v[*size/2]>n)
//         {
//             for(uint i=0;i<*size/2;i++)
//             {
//                 v1[i]=v[i];
//             } 
//             *size=*size/2;
//             return binsearch(v1,size,n);
//         }
//         else
//         {
//             uint adder=0;
//             for(uint i=*size/2;i<*size;i++)
//             {
//                 v1[adder++]=v[i];
//             }
//             *size=*size/2;
//             return binsearch(v1,size,n);
//         }
//     }
    
    
// }

int cmp(const void *e1,const void *e2)
{
    int *v1=(int*)e1;
    int *v2=(int*)e2;
    return *v1-*v2;
}

int binsearch(int *v,uint a,uint b,int nr)
{
    if(a>b)
    {
        return 0;
    }

    uint mid=a+(b-a)/2;

    if(v[mid]==nr)
    {
        return 1;
    }
    else if(v[mid]<nr)
    {
        return binsearch(v,a,mid-1,nr);
    }
    else
    {
        return binsearch(v,mid+1,b,nr);
    }

}

int comparare(int *v1,uint size1,int *v2,uint size2)
{
    for(uint i=0;i<size1;i++)
    {
        if(binsearch(v2,0,size2-1,v1[i]))
        {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    uint size1=0,size2=0;
    int *v1=NULL,*v2=NULL;
    printf("Cate elemente are primul vector:");
    scanf("%d",&size1);
    v1=citire(v1,size1);
    afisare(v1,size1);
    //uint size=size1/2;
    qsort(v1,size1,sizeof(int),cmp);
    printf("Cate elemente are al doilea vector:");
    scanf("%d",&size2);
    v2=citire(v2,size2);
    afisare(v2,size2);
    qsort(v2,size2,sizeof(int),cmp);
    if(comparare(v1,size1,v2,size2))
    {
        printf("Toate elementele sunt egale\n");
    }
    else
    {
        printf("Exista elemente care nu sunt egale\n");
    }
    free(v1);
    free(v2);
}