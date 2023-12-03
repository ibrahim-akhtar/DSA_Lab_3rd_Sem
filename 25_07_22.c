// 1. insert element at any index
// 2. delete any element

#include <stdio.h>

void insert(int a[])
{
    // printf("%d", a[0]);
    int copy, i;
    int index, n;
    printf("Enter the Index at which you want to Insert the Number: ");
    scanf("%d", &index);
    printf("Enter the Number you want to Insert: ");
    scanf("%d", &n);
    int cn = n;

    i = index;
    while (a[i] != 0 && a[i - 1] != 0)
    {
        copy = a[i];
        a[i] = cn;
        cn = copy;
        i++;
    }
    copy = a[i];
    a[i] = cn;
    cn = copy;

    i = 0;
    while (a[i] != 0)
    {
        printf("%d\n", a[i]);
        i++;
    }
}

void delete (int a[])
{
    int n, index;
    printf("Enter the Number you want to Delete: ");
    scanf("%d", &n);
    int i = 0;
    while (a[i] != 0)
    {
        if (n == a[i])
        {
            index = i;
            break;
        }
        i++;
    }

    i = index;
    while (a[i] != 0)
    {
        a[i] = a[i+1];
        i++;
    }

    i = 0;
    while (a[i] != 0)
    {
        printf("%d\n", a[i]);
        i++;
    }
}

int main()
{
    int a[20] = {1, 2, 3, 4, 5};
    printf("Default Array:\n%d\n%d\n%d\n%d\n%d\n", a[0], a[1], a[2], a[3], a[4]);

    while (1)
    {
        printf("<<MENU>>\n1 -> To Insert an Number in Array\n2 -> To Delete an Number in Array\n3 -> Exit : ");
        int c;
        scanf("%d", &c);

        switch (c)
        {
        case 1:
        {
            insert(a);
            break;
        }

        case 2:
        {
            delete (a);
            break;
        }

        case 3:
        {
            return 0;
            break;
        }
        default:
        {
            printf("Wrong Input\n");
            break;
        }
        }
    }
}