// Recursive Function

#include <stdio.h>

int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int power(int a, int b)
{
    if (b == 1)
        return a;
    else
        return a * power(a, b - 1);
}

int sumArray(int a[], int l)
{
    if (l == 0)
        return 0;
    else
        return a[l - 1] + sumArray(a, l - 1);
}

int fibTerm(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return fibTerm(n - 1) + fibTerm(n - 2);
}

int fibSum(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return fibSum(n - 1) + fibSum(n - 2) + 1;
}

int main()
{

    while (1)
    {
        int choice;
        printf("\nMENU:\n1. Factorial of a Number\n2. Powers of a Number\n3. Sum of an array\n4. Print nth Fibonacci Term\n5. Sum of Fibonacci series till n terms\n6. EXIT: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("For Factorial, Enter the Number: ");
            int n;
            scanf("%d", &n);
            printf("Factorial of %d is %d\n", n, factorial(n));
            break;
        }
        case 2:
        {
            printf("For Expression a^b, Enter a and b: ");
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d ^ %d = %d\n", a, b, power(a, b));
            break;
        }
        case 3:
        {
            printf("Enter the length of array: ");
            int l;
            scanf("%d", &l);
            int a[l];
            for (int i = 0; i < l; i++)
            {
                printf("Enter the number at %d index: ", i + 1);
                scanf("%d", &a[i]);
            }
            printf("Total Sum of the Array = %d\n", sumArray(a, l));
            break;
        }
        case 4:
        {
            printf("Enter the place whose Fibonacci Term you want to know: ");
            int n;
            scanf("%d", &n);
            printf("Fibonacci Term at place %d is %d\n", n, fibTerm(n));
            break;
        }
        case 5:
        {
            printf("Enter the place till where you want to know the sum of fibonacci numbers: ");
            int n;
            scanf("%d", &n);
            printf("Sum of Fibonacci %d Terms is %d\n", n, fibSum(n));
            break;
        }
        case 6:
        {
            return 0;
            break;
        }
        default:
        {
            printf("Invalid Input!!!");
            break;
        }
        }
    }
    return 0;
}