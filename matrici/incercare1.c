#include<stdio.h>
#define M 10
#define N 2

void citire(int a[N][M])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void afisare(int v[][M],int m,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }printf("\n");

}

/*int main(void)
{
    int m=0,n=0;
    printf("Dati nr1:");
    scanf("%d",&n);
    printf("Dati nr2:");
    scanf("%d",&m);
    //int v[n][m];
    int v[N][M];
    citire(v);
    afisare(v,n,m);

}*/

int main() {
int a[10][10], nr_linii, nr_coloane;
scanf("%d",&nr_linii);
scanf("%d",&nr_coloane);
// daca se citesc nr_linii=2 si nr_coloane=3
for(int i=0; i<nr_linii; i++)
{
    for(int j=0;j<nr_coloane;j++)
        a[i][j]=i+j;

}
    
    afisare(a, nr_linii, nr_coloane);
    printf("\n");
afisare(a, 10, 10);
return 0;
}