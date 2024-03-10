#include<stdio.h>

void citire(int v[50][50],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            scanf("%d",&v[i][j]);

        }
    }
}

void afisare(int v[50][50],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }
    printf("\n");
}

void interschimbare(int v[50][50],int size)
{
    int rez[50][50];
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i==j)
            {
                rez[i][j]=v[i][j];
            }
            else
            {
                rez[i][j]=v[j][i];
            }
        }
    }
    afisare(rez,size);

}


int main(void)
{
    int size=0;
    int v[50][50];
    scanf("%d",&size);
    citire(v,size);
    afisare(v,size);
    interschimbare(v,size);
}


/*| A1 | A0 | B1 | B0 | Out |
| 0  | 0  | 0  | 0  |  0  |
| 0  | 0  | 0  | 1  |  0  |
| 0  | 0  | 1  | 0  |  0  |
| 0  | 0  | 1  | 1  |  0  |
| 0  | 1  | 1  | 1  |  0  |
| 1  | 0  | 1  | 1  |  0  |
| 1  | 1  | 1  | 1  |  0  |
| 1  | 1  | 0  | 1  |  1  |
| 1  | 1  | 1  | 0  |  1  |
| 1  | 1  | 0  | 0  |  1  |
| 1  | 0  | 0  | 0  |  1  |
| 1  | 0  | 0  | 1  |  1  |
| 1  | 0  | 1  | 0  |  0  |
| 1  | 1  | 1  | 0  |  0  |
| 0  | 1  | 0  | 0  |  1  |
| 0  | 1  | 0  | 1  |  0  |
| 0  | 1  | 1  | 0  |  0  |*/

