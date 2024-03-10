#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define CUV_SIZE 256

typedef struct{
    int ident;
    char mes[CUV_SIZE];
}Mesaj;

Mesaj queue[MAX];
int front=0,rear=0;

void enqueue(char n[CUV_SIZE])
{
    if(rear==MAX-1)
    {
        printf("Coada este plina\n");
        exit(-1);
    }
    queue[rear].ident=rear;
    strcpy(queue[rear].mes,n);
    rear++;
}


Mesaj dequeue()
{
    if(rear==0 || front==rear)
    {
        printf("Coada este goala\n");
        exit(-1);
    }
    return queue[front++];
}


void display()
{
    if(rear==0 || rear<=front)
    {
        printf("Coada este goala\n");
        exit(-1);
    }
    for(int i=front;i<rear;i++)
    {
        printf("%s - %d\n",queue[i].mes,queue[i].ident);
    }
}

int main(void)
{
    int size=0;
    printf("Cate elemente sa fie transmise?");
    scanf("%d",&size);
    char v[size][CUV_SIZE];
    Mesaj new[MAX];
    printf("Introduceti cuvintele:\n");
    for(int i=0;i<size;i++)
    {
        scanf("%255s",v[i]);
        enqueue(v[i]);
        
    }

    for(int i=0;i<size;i++)
    {
        new[i]=dequeue();
    }

    for(int i=0;i<size;i++)
    {
        printf("%s - %d\n",new[i].mes,new[i].ident);
    }
    display();
}

