//Circular Queue

#include<stdio.h>
#include<stdlib.h>

struct cirQueue
{
    int size;
    int f;
    int r;
    int * arr;
};

void queueTraversal (struct cirQueue * q)
{
    int front = q->f;
    int rear = q->r;
    if (front == rear)
        printf("Queue is Empty\n");
    else if (front < rear)
    {
        while (front < rear)
        {
            front++;
            printf("Element at Index %d is %d\n",front ,q->arr[front]);
        }
    }
    else if (rear < front)
    {
        while (front < q->size-1)
        {
            front++;
            printf("Element at Index %d is %d\n", front,q->arr[front]);
        }
        int i = 0;
        while (i <= rear)
        {
            printf("Element at Index %d is %d\n", i,q->arr[i]);
            i++;
        }
    }
}

int isFull(struct cirQueue * q)
{
    if ((q->r+1)%q->size == q->f)
        return 1;
    else 
        return 0;
}

void enQueue(struct cirQueue * q, int n)
{
    if (isFull(q))
        printf("Queue is Full\n");
    else
    {
        q->r = (q->r+1) % q->size; //Circular Increment
        q->arr[q->r] = n;
        printf("%d added to the Circular Queue at Index %d\n",n, q->r);
    }
}

int isEmpty(struct cirQueue * q)
{
    if (q->r == q->f)
        return 1;
    else 
        return 0;
}

void deQueue(struct cirQueue *q)
{
    if (isEmpty(q))
        printf("Queue is Empty\n");
    else
    {
        q->f = (q->f+1)%q->size; //Circular Increment
        printf("%d present at index %d been Deleted from the Queue\n", q->arr[q->f], q->f);
    }
}

int main()
{
    struct cirQueue q;
    q.size = 7;
    q.f = 0; q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    while (1)
    {
        printf("\nMENU:\n1. enQueue\n2. deQueue\n3. isEmpty\n4. isFull\n5. queueTraversal\n6. Exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("Enter the number you want to Insert in Queue: ");
                int n;
                scanf("%d", &n);
                enQueue(&q, n);
                break;
            }
            case 2:
            {
                deQueue(&q);
                break;
            }
            case 3:
            {
                if (isEmpty(&q))
                    printf("Queue is Empty\n");
                else
                    printf("Queue is NOT Empty\n");
                break;
            }
            case 4:
            {
                if (isFull(&q))
                    printf("Queue is Full\n");
                else
                    printf("Queue is NOT Full\n");
                break;
            }
            case 5:
            {
                queueTraversal(&q);
                break;
            }
            case 6:
                return 0;
                break;
            default:
                printf("Invalid Input!!!");
                break;
        }
    }

    return 0;
}