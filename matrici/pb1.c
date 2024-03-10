#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int x1;
    int y1;
    int x2;
    int y2;
}Coord;

void eliberare(int **v,int size)
{
    for(int i=0;i<size;i++)free(v[i]);
    free(v);
}

void eliberareVect(int ***v,int size1,int size2)
{
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            free(v[i][j]);
        }
        free(v[i]);
    }
    free(v);
}

void citire(int **v,int size)
{
    for(int i=0;i<size;i++)
    {
        v[i]=(int*)malloc(size*sizeof(int));
        if(v[i]==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            eliberare(v,size);
            exit(-1);
        }
        for(int j=0;j<size;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }
}

void afisare(int **v,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }printf("\n");
}


void extractSubmatrices(int **v1, int size1, int **v2, int size2) 
{
    Coord *coordonate=NULL;
    int lungime=(size1-size2+1)*(size1-size2+1);
    int ***matrix = (int ***)malloc(lungime  * sizeof(int**));

    if (matrix == NULL) {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    //matrix este un vector de matrici in care retinem toate submatricile de size2 care sunt incluse in matricea mare v1 de size1

    coordonate=(Coord*)malloc(lungime*sizeof(Coord));
    if(coordonate==NULL)
    {
        printf("Eroare la alocare structura\n");
        perror(NULL);
        exit(-1);
    }
    //cream un vector de coordonate pt a retine coordonatele inceputului si finalului fiecarei submatrici

    for (int i = 0; i < lungime; i++) {
        matrix[i] = (int **)malloc(size2 * sizeof(int*));

        if (matrix[i] == NULL) {
            printf("Eroare la alocare\n");
            perror(NULL);
            exit(-1);
        }

        for (int j = 0; j < size2; j++) {
            coordonate[i].x1=0;
            coordonate[i].y1=0;
            coordonate[i].x2=0;
            coordonate[i].y2=0;
            matrix[i][j] = (int *)malloc(size2 * sizeof(int));

            if (matrix[i][j] == NULL) {
                printf("Eroare la alocare\n");
                perror(NULL);
                exit(-1);
            }

            for (int k = 0; k < size2; k++) 
            {
                if(k==0)
                {
                    coordonate[i].x1=i / (size1 - size2 + 1) ;
                    coordonate[i].y1=i % (size1 - size2 + 1) ;
                }
                
                matrix[i][j][k] = v1[i / (size1 - size2 + 1) + j][i % (size1 - size2 + 1) + k];
                
                if(k==(size2-1) && j==(size2-1))
                {
                    coordonate[i].x2=i / (size1 - size2 + 1) + j;
                    coordonate[i].y2=i % (size1 - size2 + 1) + k;
                }
            }
        }
        //afisam toate submatrcile
        afisare(matrix[i], size2);
    }
    

    //comparam matricea v2 cu fiecare submatrice extrasa si care e acum in vectorul matrix
    int adder=0;
    Coord rez[lungime];
    memset(rez,0,lungime*sizeof(Coord));
    //se face un vector rez in care memoram coordonatele tuturor aparitiilor matricei2
    for(int i=0;i<lungime;i++)
    {
        for(int j=0;j<size2;j++)
        {
            for(int k=0;k<size2;k++)
            {
                if(matrix[i][j][k]==v2[j][k])
                {
                    rez[adder].x1=coordonate[i].x1;
                    rez[adder].y1=coordonate[i].y1;
                    rez[adder].x2=coordonate[i].x2;
                    rez[adder].y2=coordonate[i].y2;
                    adder++;
                }
            }
        }
                
    }
    adder/=size2;

    if(adder>0)
    {
        for(int i=0;i<adder;i++)
        {
            printf("Coordonatele la care se gaseste matricea2 sunt:(%d,%d);(%d,%d)\n",rez[i].x1,rez[i].y1,rez[i].x2,rez[i].y2);
        }
    }
    else
        printf("Nu s a gasit matricea2 in matricea1\n");

    

    //afisareCoord(coordonate,lungime);
    free(coordonate);
    eliberareVect(matrix, lungime, size2);
}




int main(void)
{
    int **v1=NULL,**v2=NULL;
    int size1=0,size2=0;
    printf("Introduceti dimensiunile a doua matrici tinand cont ca prima trebuie sa fie mai mare decat a doua\n");
    //dimensiunea primei matrici trebuie sa fie mai mare decat dimensiunea celei de a doua matrici
    printf("Dimensiunea pt matricea 1:");
    scanf("%d",&size1);
    

    v1=(int**)malloc(size1*sizeof(int*));
    if(v1==NULL)
    {
        printf("Eroare la alocare in main\n");
        perror(NULL);
        eliberare(v1,size1);
        exit(-1);
    }

    citire(v1,size1);
    afisare(v1,size1);
    

    printf("Dimensiunea pt matricea 2:");
    scanf("%d",&size2);

    v2=(int**)malloc(size2*sizeof(int*));
    if(v2==NULL)
    {
        printf("Eroare la alocare in main\n");
        perror(NULL);
        eliberare(v2,size2);
        exit(-1);
    }

    

    citire(v2,size2);
    afisare(v2,size2);

    
    if(size1>size2)
    {
        extractSubmatrices(v1,size1,v2,size2);
    }

    else
    {
        printf("Date incorecte\n");
    }
    

    eliberare(v1,size1);
    eliberare(v2,size2);
}
