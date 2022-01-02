#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node next;
}NODE;
NODE *reverseLinkInSizeIterative(NODE *head,int k)
{
	NODE *curr= head;
	NODE *prev_First = NULL;
	bool isFirst = true;
	while(curr!=NULL)
	{
		NODE *first = curr;
		NODE *prev = NULL;
		int count=0;
		while(curr != NULL && count<k)
		{
			NODE *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr=next;
			count++;
		}
		if(isFirst)
		{
			head = prev;
			isFirst = false;
		}
		else{
			prev_First->next = prev;
		}
		prev_First = first
	}
	return head;
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
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    printf("Origanl Linked lISt");
    printList(head);
    int k =3;
    NODE *res = reverseLinkInSizeIterative(head,k);
    printf("\n");
    printf("reverseLinkedList");
    printList(res);
}

		