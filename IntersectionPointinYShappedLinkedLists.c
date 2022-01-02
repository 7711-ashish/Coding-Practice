#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int IntersectionPointinYShappedLinkedLists(Node *head1, Node *head2)
{
    int count1 = 0, count2 = 0;
    Node *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    if (count1 > count2)
    {
        int diff = count1 - count2;
        while (diff--)
        {
            temp1 = temp1->next;
        }
    }
    else
    {
        int diff = count2 - count1;
        while (diff--)
        {
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
        {
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
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
    NODE *head2 = NULL;
    push(&head2, 1);
    push(&head2, 2);
    push(&head2, 3);
    int abs = IntersectionPointinYShappedLinkedLists(head, head2);
    printf("Origanl Linked lISt");
    printList(head);
    printList(head2);
    printf("\nIntersection Point is %d", abs);
}
