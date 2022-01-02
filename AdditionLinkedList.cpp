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


NODE* addList(NODE *head1, NODE *head2)
{
  first = reverse(first);
        second = reverse(second);
        Node* firsth = first;
        Node* secondh = second;
        int f=0,s=0;
        // count which linked list has greater element and label it as big and the 
        // other as small
    while(firsth->next!=NULL)
    {
            firsth = firsth->next;
            f++;
    }
    while(secondh->next!=NULL)
    {
            secondh = secondh->next;
            s++;
    }
        Node* big;
        Node* small;
        if(f>=s){
            big=first;
            small=second;
        }
        else {
            big=second;
            small=first;
        }
        // make temp node variable to traverse the linked list as 
        // as we have to return the original head of the linked list
        Node* big_head = big;
        // make a variable for carry
        int carry=0;
        while(big!=NULL and small!=NULL)
        {
            // perform the addition
            big_head->data += small->data+carry;
            // if the last node will have a double digit number then we have 
            // to move its second digit to a new node
            if(big_head->next==NULL)
            {
                carry = big_head->data/10;
                big_head->data = big_head->data%10; 
                if(carry>0){
                // make a new node and input the carry into it only when the carry 
                // is greater than 0. After this initialise carry to 0. Else
                // it will get added again in the nect iteration
                Node* temp = new Node(carry);
                big_head->next = temp;
                big_head=temp;
                carry=0;
                break;
                }
            }
            
            if(big_head->data>9)
            {
                carry = big_head->data/10;
                big_head->data = big_head->data%10; 
            }else carry=0;
            
            big_head = big_head->next;
            small = small->next;
        }
        // for traversing the rest of the linked list
        while(big_head!=NULL)
        {
            big_head->data += carry;
            if(big_head->next==NULL)
            {
                carry = big_head->data/10;
                big_head->data = big_head->data%10; 
                if(carry>0){
                Node* temp = new Node(carry);
                big_head->next = temp;
                big_head=temp;
                break;}
            }
            if(big_head->data>9)
            {
                carry = big_head->data/10;
                big_head->data = big_head->data%10; 
            }else carry=0;
            
            big_head = big_head->next;
        }
        // reverse the linked list again and return its head.
        big = reverse(big);
        return big;
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
    NODE *head1 = NULL;
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);
    push(&head1, 5);
    printf("Origanl Linked lISt");
    printList(head);
    printf("\n");
    printf("reverseLinkedList");
    printList(head);
}
