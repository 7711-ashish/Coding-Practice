#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *head=NULL;
NODE *tail=NULL;
static void reverseLinkInSize(NODE *head,int k)
{
    NODE *curr  = NULL;
    int counter=0;
    NODE *prev = NULL;
    while(curr!=NULL && counter<k)
    {
        NODE *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        counter++;
    }
    if(curr!=NULL)
        head->next = reverseLinkInSize(curr,k);
    return prev;
}

