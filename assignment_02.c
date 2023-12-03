// Doubly Linked List

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    int key;

    struct node *next;
    struct node *prev;
};

struct node *head = NULL;   // will always point to first node
struct node *last = NULL;   // will always point to last node
struct node *current = NULL;

bool isEmpty()  // is list empty
{
    return head == NULL;
}

int length()
{
    int length = 0;
    struct node *current;

    for (current = head; current != NULL; current = current->next)
    {
        length++;
    }
    return length;
}

void displayForward()   // display the list in from first to last
{
    struct node *ptr = head;    // start from the beginning
    printf("\n[ "); // navigate till the end of the list
    while (ptr != NULL)
    {
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf(" ]");
}

void displayBackward()  // display the list from last to first (i.e; reverse order)
{
    struct node *ptr = last;    // start from the last
    printf("\n[ "); // navigate till the start of the list

    while (ptr != NULL)
    {
        printf("(%d,%d) ", ptr->key, ptr->data);    
        ptr = ptr->prev;
    }
    printf(" ]");
}

void insertFirst(int key, int data) // insert link at the first location
{
    struct node *link = (struct node *)malloc(sizeof(struct node)); // create a link
    link->key = key;
    link->data = data;

    if (isEmpty())
    {
        last = link;    // make it the last link
    }
    else
    {
        head->prev = link;  // update first prev link
    }

    link->next = head;      // point it to old first link
    head = link;    // point first to new first link
}

void insertLast(int key, int data)  // insert link at the last location
{

    // create a link
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;

    if (isEmpty())
    {
        last = link;    // make it the last link
    }
    else
    {
        last->next = link;  // make link a new last link
        link->prev = last; // mark old last node as prev of new link
    }
    last = link; // point last to new last node
}

struct node *deleteFirst()  // delete first item
{
    struct node *tempLink = head;   // save reference to first link
    if (head->next == NULL) // if only one link
    {
        last = NULL;
    }
    else
    {
        head->next->prev = NULL;
    }
    head = head->next;
    return tempLink;    // return the deleted link
}

struct node *deleteLast()   // delete link at the last location
{
    struct node *tempLink = last;   // save reference to last link
    if (head->next == NULL) // if only one link
    {
        head = NULL;
    }
    else
    {
        last->prev->next = NULL;
    }
    last = last->prev;
    return tempLink;    // return the deleted link
}

struct node *delete (int key)
{
    struct node *current = head;    // start from the first link
    struct node *previous = NULL;

    if (head == NULL)   // if list is empty
    {
        return NULL;
    }
    while (current->key != key) // navigate through list
    {

        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            previous = current; // store reference to current link
            current = current->next;    // move to next link
        }
    }

    if (current == head)
    {
        head = head->next;  // change first to point to next link
    }
    else
    {
        current->prev->next = current->next;    // bypass the current link
    }

    if (current == last)
    {
        last = current->prev;   // change last to point to prev link
    }
    else
    {
        current->next->prev = current->prev;
    }
    return current;
}

bool insertAfter(int key, int newKey, int data)
{
    struct node *current = head;    // start from the first link
    if (head == NULL)   // if list is empty
    {
        return false;
    }
    while (current->key != key) // navigate through list
    {        
        if (current->next == NULL)  // if it is last node
        {
            return false;
        }
        else
        {        
            current = current->next;    // move to next link
        }
    }

    struct node *newLink = (struct node *)malloc(sizeof(struct node));  // create a link
    newLink->key = newKey;
    newLink->data = data;

    if (current == last)
    {
        newLink->next = NULL;
        last = newLink;
    }
    else
    {
        newLink->next = current->next;
        current->next->prev = newLink;
    }

    newLink->prev = current;
    current->next = newLink;
    return true;
}

int main()
{
    insertFirst(1, 10);
    insertFirst(2, 20);
    insertFirst(3, 30);
    insertFirst(4, 1);
    insertFirst(5, 40);
    insertFirst(6, 56);

    printf("\nList (First to Last): ");
    displayForward();

    printf("\n");
    printf("\nList (Last to first): ");
    displayBackward();

    printf("\nList , after deleting first record: ");
    deleteFirst();
    displayForward();

    printf("\nList , after deleting last record: ");
    deleteLast();
    displayForward();

    printf("\nList , insert after key(4) : ");
    insertAfter(4, 7, 13);
    displayForward();

    printf("\nList  , after delete key(4) : ");
    delete (4);
    displayForward();

    // printf("\nMENU:\n1. Insert at Beginning\n2. Insert at End\n3. Insert at given Position\n");
    // printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from given Position\n");
    // printf("7. Search by ID\n8. Search by Name\n9. Print in Reverse Order\n10. Exit: ");
    // int choice;
    // scanf("%d", &choice);

    // switch (choice)
    // {
    // }
    return 0;
}