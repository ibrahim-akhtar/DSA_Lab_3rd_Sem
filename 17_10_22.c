// Complete Binary Tree - Array Representation

#include <stdio.h>

int power(int a, int b)
{
    if (b == 1)
        return a;
    else
        return a * power(a, b - 1);
}

int main()
{
    printf("In order to implement complete binary tree make sure to insert all the numbers present in its node\n");
    printf("\nEnter the height of root node from its leaf nodes(0-4): ");
    int h;
    scanf("%d", &h);

    int tn = power(2, h) - 1;
    int tree[tn];

    while (1)
    {
        printf("MENU:\n1. Insert Node\n2. Info of the Node\n3. Display Total No. of Nodes\n4. Exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("The Loop will run %d times in order to input number (i.e. till index 0 - %d)\n", tn, tn - 1);
            for (int i = 0; i < tn; i++)
            {
                printf("Enter Number at %d index of binary tree: ", i);
                scanf("%d", &tree[i]);
            }
            printf("\nYou've Entered all the numbers to the nodes. Try not to repeat it again\n\n");
            break;
        }
        case 2:
        {
            printf("Enter the index of node(b/w 0 to %d), you want the information off: ", tn - 1);
            int in;
            scanf("%d", &in);

            printf("Value present at index %d is %d\n", in, tree[in]);
            if (in <= power(2, h - 1))
            {
                printf("Children of the index %d are present at indices %d and %d\n", in, (2 * in) + 1, (2 * in) + 2);
                printf("Values present at %d is %d and at %d is %d\n", (2 * in) + 1, tree[(2 * in) + 1], (2 * in) + 2, tree[(2 * in) + 2]);
            }
            else
                printf("%d index contains a Leaf Node, hence no roots\n", in);

            if (in == 0)
                printf("Since its the Root Node it, it doesn't have an Parent\n");
            else if (in % 2 == 1)
            {
                printf("Parent node of %d is present at index %d\n", tree[in], in / 2);
                printf("Value at Parent Node %d\n", tree[in / 2]);
            }
            else if (in % 2 == 0)
            {
                printf("Parent node of %d is present at index %d\n", tree[in], (in - 1) / 2);
                printf("Value at Parent Node %d\n", tree[(in - 1) / 2]);
            }
            break;
        }
        case 3:
            printf("Total Number of nodes: %d\n", tn);
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Invalid Input!!!\n");
            break;
        }
    }
    return 0;
}