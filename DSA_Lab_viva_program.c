//Implement Circular Queue
#include<stdio.h>
#include<stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int * arr;
};

int isFull(struct circularQueue * q)
{
    if ((q->r+1)%q->size == q->f)  
        return 1;
    else 
        return 0;
}

void enQueue(struct circularQueue * q, int num)
{
    if (isFull(q))
        printf("Queue is Full\n");
    else
    {
        q->r = (q->r+1) % q->size; //Circular Increment
        q->arr[q->r] = num;
        printf("%d added to the Circular Queue at Index %d\n",n, q->r);
    }
}

int main()
{
    struct circularQueue q;
    q.size = 7;
    q.f = 0; q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    while(1)
    {
        printf("\nMENU:\n1. Enqueue\n2. Dequeue\n3. Print Front & Rear Element\n4. Total No. of Elements\n5. Display\n6. Exit : ");
        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("Enter the number you want to enqueue: ");
                int num;
                scanf("%d", &num);
                enQueue(&q, num);
            }
        }

    }
    return 0;
}