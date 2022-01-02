// Reverse a doubly linked list in groups of given size
#include <iostream>
using namespace std;
class Node
{
    public:
        Node *next;
        int data;
        Node *prev;
        Node(int x)
        {
            prev = NULL;
            data = x;
            next = NULL;
        }
}
void insertAtHead(int x, Node *head)
{
    Node *node = new Node(x);
    if(head == NULL)
    {
        head = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
    return;
}
void insertAtTail(int x, Node* head)
{
    Node *node = new Node(x);
    if(head == NULL)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
    return;
}
void display(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<"\n";
}
void rotateByN(Node *head, int n)
{
    if(head == NULL)
    {
        return NULL;
    }
    int count = 0;
    Node *temp , *current = head, *newHead;
    while(current != NULL && count < n)
    {
        newHead = current;
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
        count++;
    }

    if(count >= n){
        Node *rest = rotateByN(current, n);
        head->next = rest;
        if(rest != NULL)
        {
            rest->prev = head;
        }
    }
    return newHead;
}

int main()
{
    Node *head = NULL;
    insertAtHead(1, head);
    insertAtHead(2, head);
    insertAtHead(3, head);
    insertAtHead(4, head);
    insertAtHead(5, head);
    insertAtHead(6, head);
    display(&head);
    rotateByN(&head, 2);
    display(&head);
    return 0;
}