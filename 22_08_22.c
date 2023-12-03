// Stack ADT

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *s, int val)
{
    if (isFull(s))
        printf("Stack OverFlow\n");
    else
    {
        s->top++;
        s->arr[s->top] = val;
        printf("%d has been pushed into the stack\n", val);
    }
}

void pop(struct stack *s)
{
    if (isEmpty(s))
        printf("Stack UnderFlow\n");
    else
    {
        int v = s->arr[s->top];
        // free(s->arr[s->top]);
        s->top--;
        printf("%d has been popped out of the stack\n", v);
    }
}

void peek(struct stack *s, int pos)
{
    if ((s->top - pos + 1) < 0)
    {
        printf("Invalid Position\n");
    }
    else
    {
        printf("%d is the number at position %d in the stack\n", s->arr[s->top - pos + 1], pos);
    }
}

int main()
{
    struct stack *s;                                  // created a structure pointer(stores the address of the structure)
    s = (struct stack *)malloc(sizeof(struct stack)); //(created an instance of structure)
    s->size = 10;                                     // size of stack
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int)); // assigning heap memory for array(stack) of integers

    while (1)
    {
        printf("MENU\n1. PUSH\n2. POP\n3. isEmpty\n4. isFull\n5. PEEK\n6. EXIT: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the number you want to push: ");
            int n;
            scanf("%d", &n);
            push(s, n);
            break;
        }
        case 2:
        {
            pop(s);
            break;
        }

        case 3:
        {
            if (isEmpty(s))
                printf("Stack UnderFlow\n");
            else
                printf("Stack is NOT Empty\n");
            break;
        }
        case 4:
        {
            if (isFull(s))
                printf("Stack OverFlow\n");
            else
                printf("Stack is NOT Full\n");
            break;
        }
        case 5:
        {
            if (isEmpty(s))
                printf("Stack UnderFlow\n");
            else
            {
                for (int i = 1; i <= s->top + 1; i++)
                    peek(s, i);
            }
            break;
        }
        case 6:
        {
            return 0;
            break;
        }
        default:
        {
            printf("Wrong Input!!!\n");
            break;
        }
        }
    }
    return 0;
}