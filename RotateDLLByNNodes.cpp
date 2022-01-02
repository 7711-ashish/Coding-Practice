#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
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
        return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->prev = temp;
    int count = 1;
    while(count < n)
    {
        head = head->next;
        temp= temp->next;
        count++;
    }
    temp->next = NULL;
    head->prev = NULL;
}
int main()
{
    Node *head = NULL;
    insertAtTail(1, head);
    insertAtTail(2, head);
    insertAtTail(3, head);
    insertAtTail(4, head);
    insertAtTail(5, head);
    insertAtTail(6, head);

    int n = 2;
    display(&head);
    rotateByN(&head, n);
    display(&head);
    return 0;
}
