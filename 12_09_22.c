//Singly Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void listTraversal (struct node * p)
{
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

struct node * insertAtBeginning (struct node * head, int x)
{
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data= x;
    ptr -> next = head;
    return ptr;
}

struct node * insertAtEnd (struct node * head, int x)
{
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = x;
    ptr -> next = NULL;
    struct node * copy = head;
    while (copy->next != NULL)
    {
        copy = copy->next;
    }
    copy->next = ptr;
    return head;
}

struct node * insertAtPosition (struct node * head, int x, int pos)
{
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = x;
    struct node * copy = head;
    int i = 1;
    while (i < pos-1)
    {
        copy = copy->next;
        i++;
    }
    ptr->next = copy->next;
    copy->next = ptr;
    return head;
}

struct node * deleteAtBeginning(struct node * head)
{
    struct node * copy = head;
    head = head->next;
    free (copy);
    return head;
}

struct node * deleteAtEnd(struct node * head)
{
    struct node * copy = head;
    struct node * copy2 = head->next;
    while (copy2->next != NULL)
    {
        copy = copy->next;
        copy2 = copy->next;
    }
    copy->next = NULL;
    free(copy2);
    return head;
}

struct node * deleteAtPosition(struct node * head, int pos)
{
    struct node * copy = head;
    int i = 1;
    while (i < pos-1)
    {
        copy = copy->next;
        i++;
    }
    struct node * copy2 = copy->next;
    copy->next = copy2->next;
    free(copy2);
    return head;
}

int main()
{
    struct node * head = (struct node*)malloc(sizeof(struct node));
    struct node * h2 = (struct node*)malloc(sizeof(struct node));
    struct node * h3 = (struct node*)malloc(sizeof(struct node));

    head->data = 10;
    head->next = h2;
    h2->data = 100;
    h2->next = h3;
    h3->data = 1000;
    h3->next = NULL;

    while (1)
    {
        printf("\nMENU 1:\n1. To Insert\n2. To Delete\n3. EXIT: ");
        int c1;
        scanf("%d", &c1);
        switch (c1)
        {
            case 1:
            {
                printf("\nMENU 2: (To Insert at the)\n1. Beginning\n2. End\n3. Given Position: ");
                int c2;
                scanf("%d", &c2);
                switch (c2)
                {
                    case 1:
                        {
                            printf("Initial List: ");
                            listTraversal(head);
                            printf("\nEnter the Number you want to Insert at the Beginning: ");
                            int x;
                            scanf("%d", &x);
                            head = insertAtBeginning(head, x);
                            printf("After Insertion List: ");
                            listTraversal(head);
                            continue;
                        }
                    case 2:
                        {
                            printf("Initial List: ");
                            listTraversal(head);
                            printf("\nEnter the Number you want to Insert at the End: ");
                            int x;
                            scanf("%d", &x);
                            head = insertAtEnd(head, x);
                            printf("After Insertion List: ");
                            listTraversal(head);
                            continue;
                        }
                    case 3:
                        {
                            printf("Initial List: ");
                            listTraversal(head);
                            printf("\nEnter the Number you want to Insert: ");
                            int x,pos;
                            scanf("%d", &x);
                            printf("Enter the position(2 onwards) you want to Insert at: ");
                            scanf("%d", &pos);
                            head = insertAtPosition(head, x, pos);
                            printf("After Insertion List: ");
                            listTraversal(head);
                            continue;
                        }
                        default:
                            printf("Invalid Input!!!\n");
                            continue;
                }
            }
            case 2:
            {
                printf("\nMENU 2: (To Delete at the)\n1. Beginning\n2. End\n3. Given Position: ");
                int c2;
                scanf("%d", &c2);
                switch (c2)
                {
                    case 1:
                        {
                            printf("Initial List: ");
                            listTraversal(head);
                            head = deleteAtBeginning(head);
                            printf("After Deletion List: ");
                            listTraversal(head);
                            continue;
                        }
                    case 2:
                        {
                            printf("Initial List: ");
                            listTraversal(head);
                            head = deleteAtEnd(head);
                            printf("After Deletion List: ");
                            listTraversal(head);
                            continue;
                        }
                    case 3:
                        {
                            printf("Initial List: ");
                            listTraversal(head);
                            printf("Enter the position(2 onwards) you want to Delete at: ");
                            int pos;
                            scanf("%d", &pos);
                            head = deleteAtPosition(head, pos);
                            printf("After Deletion List: ");
                            listTraversal(head);
                            continue;
                        }
                        default:
                            printf("Invalid Input!!!\n");
                            continue;
                }
            }
            case 3:
                return 0;
                break;
            default:
                printf("Invalid Input!!!");
                break;
        }
    }
}