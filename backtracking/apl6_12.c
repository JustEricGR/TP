#include<stdio.h>

int v[20],n=0;

typedef enum{
    CASA,
    BLOC,
    GRADINA,
    ATELIER
}Cladire;

void printCladire(int nr)
{
    switch(nr)
    {
        case CASA:
        {
            printf("casa ");
            break;
        }
        case BLOC:
        {
            printf("bloc ");
            break;
        }
        case GRADINA:
        {
            printf("gradina ");
            break;
        }
        case ATELIER:
        {
            printf("atelier ");
            break;
        }
        default:
        {
            printf("casa ");
            break;
        }
    }
}

void afisare()
{
    for(int i=0;i<n;i++)
    {
        printCladire(v[i]);
    }printf("\n");
}

int valid(int k,int size1,int size2,int size3,int size4)
{
    int counter1=0,counter2=0,counter3=0,counter4=0;
    for(int i=0;i<=k;i++)
    {
        if(v[i]==0)counter1++;
        else if(v[i]==1)counter2++;
        else if(v[i]==2)counter3++;
        else if(v[i]==3)counter4++;
    }

    return size1 >= counter1 && size2 >= counter2 && size3 >= counter3 && size4 >= counter4;
}

int solutie(int k,int size1,int size2,int size3,int size4)
{
    int counter1=0,counter2=0,counter3=0,counter4=0;
    for(int i=0;i<=k;i++)
    {
        if(v[i]==0)counter1++;
        else if(v[i]==1)counter2++;
        else if(v[i]==2)counter3++;
        else if(v[i]==3)counter4++;
    }
    int prev=v[0];
    for(int i=1;i<=k;i++)
    {
        if((prev == 0 && v[i] == 3) || (prev == 3 && v[i] == 0))return 0;
        else if(((prev == 1 && v[i] == 2) || (prev == 2 && v[i] == 1)) || (prev == 1 && v[i] == 3) || (prev == 3 && v[i] == 1))return 0;
        else prev=v[i];
    }

    return size1 == counter1 && size2 == counter2 && size3 == counter3 && size4 == counter4 && k == n-1;
    //return k == n-1;
}

void back(int k,int size1,int size2,int size3,int size4)
{
    for(int i=0;i<4;i++)
    {
        v[k]=i;
        if(valid(k,size1,size2,size3,size4))
        {
            
            if(solutie(k,size1,size2,size3,size4))
            {
                afisare();
            }
            else
            {
                back(k+1,size1,size2,size3,size4);
            }
        }
    }
}

int main(void)
{
    int size1=0,size2=0,size3=0,size4=0;
    printf("Cate case sunt:");
    scanf("%d",&size1);
    printf("Cate blocuri sunt:");
    scanf("%d",&size2);
    printf("Cate gradini sunt:");
    scanf("%d",&size3);
    printf("Cate ateliere sunt:");
    scanf("%d",&size4);
    n=size1+size2+size3+size4;
    back(0,size1,size2,size3,size4);
}

