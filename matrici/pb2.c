#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int x1,x2;    
}Coord;

void eliberare(char **v,int size)
{
    for(int i=0;i<size;i++)free(v[i]);
    free(v);
}



void citire(char **v,int size)
{
    for(int i=0;i<size;i++)
    {
        v[i]=(char*)malloc((size+1)*sizeof(char));
        if(v[i]==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            eliberare(v,size);
            exit(-1);
        }
        
        for(int j=0;j<size;j++)
        {
            scanf(" %c",&v[i][j]);
            
        }
        
        v[i][size]='\0';
       
    }
}

void afisare(char **v,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%4c",v[i][j]);
        }printf("\n");
    }printf("\n");
}

//functie care inverseaza o linie dintr o matrice

char *strrev(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return str;
}

//functie de cautare a stringului pe o linie normala, transmite prin referinta coordonatele spre vectorul de structura corespunzator din functia procesare

void cautareLinie(char *line, int size,int *newSize,int *poz, char *s, Coord *coordonate1)
{
    int lungime=strlen(s);
    for(int i=0;i<=size-lungime;i++)
    {
        if(!strncasecmp(line+i,s,lungime))
        {
            coordonate1[*newSize].x1=*poz;
            coordonate1[*newSize].x2=i;
            (*newSize)++;
            break;
            
        }
    }
}

//functie de cautare a stringului pe o linie inversata, transmite prin referinta coordonatele spre vectorul de structura corespunzator din functia procesare


void cautareLinieRev(char *line, int size,int *newSize, int *poz, char *s, Coord *coordonate1)
{
    int lungime=strlen(s);
    for(int i=0;i<=size-lungime;i++)
    {
        if(!strncasecmp(line+i,s,lungime))
        {
            coordonate1[*newSize].x1=*poz;
            coordonate1[*newSize].x2=lungime-i;
            (*newSize)++;
            break;
            
        }
    }
    
}

void procesare(char **v,int size,char *s)
{
    int sizeLine=0, sizeLineRev=0, sizeCol=0,sizeColRev=0;//vor fi dimensiunile vectorilor de coordonate declarati mai jos
    Coord *coordonate1=NULL, *coordonate2=NULL, *coordonate3=NULL, *coordonate4=NULL;
    char **vectLinie=NULL, **vectColoana=NULL, **vectLinieRev=NULL, **vectColoanaRev=NULL;
    char aux1[2]="",aux2[2]="";
    vectLinie=(char**)malloc(size*sizeof(char*));
    if(vectLinie==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    vectColoana=(char**)malloc(size*sizeof(char*));
    if(vectColoana==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    vectLinieRev=(char**)malloc(size*sizeof(char*));
    if(vectLinie==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    vectColoanaRev=(char**)malloc(size*sizeof(char*));
    if(vectColoana==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    //declaram un vector de stringuri linii si unul coloane
    //declaram astfel pentru a putea compara fiecare vector de stringuri cu stringul cerut

    //cream 4 vectori de structura, cate unul pt fiecare directie de cautare
    //alocam pt fiecare structura numarul maxim de elemente pe care il poate avea(pornim de la premisa ca vom gasi pe fiecare rand si coloana stringul cautat)

    coordonate1=(Coord*)malloc(size*sizeof(Coord));
    if(coordonate1==NULL)
    {
        printf("Eroare la alocare structura\n");
        perror(NULL);
        exit(-1);
    }
    
    coordonate2=(Coord*)malloc(size*sizeof(Coord));
    if(coordonate2==NULL)
    {
        printf("Eroare la alocare structura\n");
        perror(NULL);
        exit(-1);
    }

    coordonate3=(Coord*)malloc(size*sizeof(Coord));
    if(coordonate1==NULL)
    {
        printf("Eroare la alocare structura\n");
        perror(NULL);
        exit(-1);
    }

    coordonate4=(Coord*)malloc(size*sizeof(Coord));
    if(coordonate1==NULL)
    {
        printf("Eroare la alocare structura\n");
        perror(NULL);
        exit(-1);
    }

    for(int i=0;i<size;i++)
    {
        memset(coordonate1,0,sizeof(Coord));
        memset(coordonate2,0,sizeof(Coord));
        memset(coordonate3,0,sizeof(Coord));
        memset(coordonate4,0,sizeof(Coord));
        vectLinie[i]=(char*)malloc((size+1)*sizeof(char));
        if(vectLinie[i]==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            eliberare(v,size);
            exit(-1);
        }

        vectColoana[i]=(char*)malloc((size+1)*sizeof(char));
        if(vectColoana[i]==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            eliberare(v,size);
            exit(-1);
        }
        strcpy(vectLinie[i],"");
        strcpy(vectColoana[i],"");
        for(int j=0;j<size;j++)
        {
            
            
            sprintf(aux1,"%c",v[i][j]);
            strcat(vectLinie[i],aux1);
            
            sprintf(aux2,"%c",v[j][i]);
            strcat(vectColoana[i],aux2);
            
            
        }
    }

    //pentru fiecare dintre cele 4 cautari updatam marimea vectorului de coordonate pasand functiei de cautare fiecare tip de size
    //transmit prin referinta i la fiecare functie de cautare pentru a seta eficient linia sau coloana in care se gaseste stringul

    for(int i=0;i<size;i++)
    {
        cautareLinie(vectLinie[i],size,&sizeLine,&i,s,coordonate1);
    }

    for(int i=0;i<size;i++)
    {
        vectLinieRev[i]=(char*)malloc((size+1)*sizeof(char));
        if(vectLinieRev[i]==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            eliberare(v,size);
            exit(-1);
        }
        strcpy(vectLinieRev[i],strrev(vectLinie[i]));
        cautareLinieRev(vectLinieRev[i],size,&sizeLineRev,&i,s,coordonate2);
    }


    for(int i=0;i<sizeLine;i++)
    {
        printf("Cuvantul se gaseste pe linia %d incepand de la %d spre dreapta\n",coordonate1[i].x1,coordonate1[i].x2);
    }


    for(int i=0;i<sizeLineRev;i++)
    {
        printf("Cuvantul se gaseste pe linia %d incepand de la %d spre stanga\n",coordonate2[i].x1,coordonate2[i].x2);
    }


    for(int i=0;i<size;i++)
    {
        cautareLinie(vectColoana[i],size,&sizeCol,&i,s,coordonate3);
    }

    for(int i=0;i<size;i++)
    {
        vectColoanaRev[i]=(char*)malloc((size+1)*sizeof(char));
        if(vectColoanaRev[i]==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            eliberare(v,size);
            exit(-1);
        }
        strcpy(vectColoanaRev[i],strrev(vectColoana[i]));
        cautareLinieRev(vectColoanaRev[i],size,&sizeColRev,&i,s,coordonate4);
    }

    //aici ar functiona cate un realloc pt fiecare vector de coordonate acum ca am dimensiunea lor reala


    for(int i=0;i<sizeCol;i++)
    {
        printf("Cuvantul se gaseste pe coloana %d incepand de la %d in jos\n",coordonate3[i].x1,coordonate3[i].x2);
    }


    for(int i=0;i<sizeColRev;i++)
    {
        printf("Cuvantul se gaseste pe coloana %d incepand de la %d in sus\n",coordonate4[i].x1,coordonate4[i].x2);
    }  

    if(sizeLine==0 && sizeLineRev==0 && sizeCol==0 && sizeColRev==0)printf("Nu s a gasit cuvantul nicaieri\n");
    else printf("Succes, s a gasit de %d ori\n",sizeCol+sizeColRev+sizeLine+sizeLineRev);

    free(coordonate1);
    free(coordonate2);
    free(coordonate3);
    free(coordonate4);
    eliberare(vectLinie,size);
    eliberare(vectColoana,size);
    eliberare(vectLinieRev,size);
    eliberare(vectColoanaRev,size);
}

int main(void)
{
    char **v=NULL;
    int size=0;
    char s[10]="";
    printf("Dimensiunea matricei de caractere:");
    scanf("%d",&size);
    v=(char**)malloc(size*sizeof(char*));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v,size);
    afisare(v,size);
    printf("Dati un string\n");
    scanf("%9s",s);
    procesare(v,size,s);
    eliberare(v,size);
}

