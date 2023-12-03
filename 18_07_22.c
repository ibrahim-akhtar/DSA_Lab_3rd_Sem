// WAP to print 1D and 2D array
#include <stdio.h>

int main()
{
    while (1)
    {
        printf("Enter\n1 -> 1D Array\n2 -> 2D Array\n3 -> Exit : ");
        int c;
        scanf("%d", &c);

        switch (c)
        {
        case 1:
        {
            printf("Enter the size of 1D Array: ");
            int n;
            scanf("%d", &n);
            int a[n];
            for (int i = 0; i <= n - 1; i++)
            {
                printf("Enter Element No. %d of 1D Array: ", i + 1);
                scanf("%d", &a[i]);
            }

            printf("\nThe 1D Array you inputed is as follows:\n\n");
            for (int i = 0; i <= n - 1; i++)
            {
                printf("%d\n", a[i]);
            }
            break;
        }

        case 2:
        {
            int r, co;
            printf("Enter the Number of Rows of 2D Array: ");
            scanf("%d", &r);
            printf("Enter the Number of Columns of 2D Array: ");
            scanf("%d", &co);

            int b[r][co];

            for (int i = 0; i <= r - 1; i++)
            {
                for (int j = 0; j <= co - 1; j++)
                {
                    printf("Enter Element %dx%d of 2D Array: ", i + 1, j + 1);
                    scanf("%d", &b[i][j]);
                }
            }

            printf("\nThe 2D Array you inputed is as follows:\n\n");
            for (int i = 0; i <= r - 1; i++)
            {
                for (int j = 0; j <= co - 1; j++)
                {
                    printf("%d\t", b[i][j]);
                }
                printf("\n");
            }

            break;
        }
        case 3:
            return 0;
            break;

        default:
            printf("Wrong Input\n");
            break;
        }
    }

    return 0;
}