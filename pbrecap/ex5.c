#include<stdio.h>

unsigned char v[10],valori[2]={'(',')'};
int n;

void afisare()
{
    for(int i=0;i<n;i++)
    {
        printf("%c ",v[i]);
    }printf("\n");
}

int valid(int k)
{
    // unsigned char counter1=0,counter2=0;
    // for(int i=0;i<n;i++)
    // {
    //     if(v[i]=='(')counter1++;
    //     else if(v[i]==')')counter2++;
    // }
    // printf("counter1:%d counter2:%d\n",counter1,counter2);
    // return counter1 == counter2;
    return 1;
}

int solutie(int k)
{
    unsigned char counter1=0,counter2=0;
    for(int i=0;i<=k;i++)
    {
        if(v[i]=='(')counter1++;
        else if(v[i]==')')counter2++;
        if(counter2>counter1)return 0;
    }
    return k == n-1 && counter1 == counter2;
}

void back(int k)
{
    for(int i=0;i<2;i++)
    {
        if(k>=n)return;
        v[k]=valori[i];
        if(valid(k))
        {
            if(solutie(k))
            {
                afisare();
            }
            else
            {
                back(k+1);
            }
        }
    }
}

int main(void)
{
    printf("Cate elemente sa aiba permutarea(nr par):");
    scanf("%d",&n);
    back(0);
}