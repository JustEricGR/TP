#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX];
int front=0,rear=0;

void enqueue(int n)
{
    if(rear==MAX-1)
    {
        printf("Coada este plina\n");
        exit(-1);
    }
    queue[rear++]=n;

}

void display()
{
    if(rear==0)
    {
        printf("Coada este goala\n");
        exit(-1);
    }
    for(int i=front;i<rear;i++)
    {
        printf("%d ",queue[i]);
    }printf("\n");
}

int dequeue()
{
    if(rear==0 || front=rear)
    {
        printf("Coada este goala\n");
        return -1;
    }
    return queue[front++];
}

int main(void)
{
    int size=0;
    printf("Introduceti dimensiunea cozii:");
    scanf("%d",&size);
    int v[size];
    printf("Introduceti elementele\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&v[i]);
        enqueue(v[i]);

    }
    display();
    printf("%d\n",dequeue());
    display();
}