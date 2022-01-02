#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}NODE;
static void reverseLinkedList(NODE *head);
{
    NODE *prev = NULL;
    NODE *curr = head;
    NODE *next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}


void push(NODE **head, int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
void printList(NODE *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
void main()
{
    NODE *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printf("Origanl Linked lISt");
    printList(head);
    printf("\n");
    printf("reverseLinkedList");
    printList(head);
}
