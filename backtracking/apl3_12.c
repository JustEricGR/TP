#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define CHUNK 30

int v[10],n=0,x=0;

int nrcif(int *counter,int n)
{
    if(n<10)
    {
        return *counter+1;
    }
    else
    {
        *counter+=1;
        return nrcif(counter,n/10);
    }
    
}

int *formare(int n,int size,int *index,int *cifre)
{
    if(*index == size || n<10)
    {
        cifre[*index]=n;
        return cifre;
    }
    else
    {
        cifre[*index]=n%10;
        *index+=1;
        return formare(n/10,size,index,cifre);
    }
}

int *inserare(int *numere,int *index,int counter,int k,int *current_size)
{
    int putere=0;
    if(*index>=*current_size)
    {
        *current_size+=CHUNK;
        numere=(int*)realloc(numere,*current_size*sizeof(int));
    }
    numere[*index]=0;
    for(int i=0;i<=k;i++)
    {
        numere[*index]+=v[i]*pow(10,putere++);
    }
    *index+=1;
    return numere;

}

void afisare(int size)
{
    for(int i=0;i<(size-x);i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

int solutie(int k,int size)
{
    return k == size-x-1;
}

void back(int k,int *cifre,int size,int *numere,int *index,int *current_size)
{
    for(int i=0;i<size;i++)
    {
        v[k]=cifre[i];
        if(solutie(k,size))
        {
            numere=inserare(numere,index,size,k,current_size);
            
            //afisare(size);
        }
        else
        {
            back(k+1,cifre,size,numere,index,current_size);
        }
    }
}

int maxim(int *v,int size)
{
    int max=v[0];
    for(int i=1;i<size;i++)
    {
        if(v[i]>max)max=v[i];
        
    }
    return max;
}

int main(void)
{
    int *cifre=NULL,*numere=NULL;
    printf("Dati un nr:");
    scanf("%d",&n);
    int counter=0,index=0,current_size=0;
    counter=nrcif(&counter,n);
    cifre=(int*)malloc(counter*sizeof(int));
    if(cifre==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    cifre=formare(n,counter,&index,cifre);
    printf("Cate cifre sa se elimine din nr initial:");
    scanf("%d",&x);
    
    // for(int i=0;i<counter;i++)
    // {
    //     printf("%d ",cifre[i]);
    // }printf("\n");
    index=0;
    numere=(int*)malloc(CHUNK*sizeof(int));
    if(numere==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    back(0,cifre,counter,numere,&index,&current_size);
    for(int i=0;i<index;i++)
    {
        printf("%d ",numere[i]);
    }printf("\n");

    int max=0;
    max=maxim(numere,index);
    printf("Nr maxim este:%d\n",max);
    free(cifre);
    free(numere);
}