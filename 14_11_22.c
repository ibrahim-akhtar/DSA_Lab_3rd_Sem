//Binary Tree implementation using Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createNode (int d)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}

void inOrder (struct node * root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf ("%d\t", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct node * r = createNode (15); //root node
    struct node * r1 = createNode (25);
    struct node * r2 = createNode (35);
    struct node * s1 = createNode (50);
    struct node * s2 = createNode (60);
    struct node * s3 = createNode (100);

    r->left = r1;
    r->right = r2;

    r1->left = s1;

    r2->left = s2;
    r2->right = s3;

    //Binary Tree
    /*                  15
                       /  \
                      25  35
                     /   /  \
                    50  60  100             */

    printf("InOrder Traversal: ");
    inOrder(r);

    return 0;
}