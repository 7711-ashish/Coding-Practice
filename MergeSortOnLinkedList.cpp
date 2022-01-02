// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:

    Node *middleNode(Node *head) {
        // This is a "method-only" submission.
        // You only need to complete this method.
        Node *slow = head;
        Node *fast = head;
        while(fast != NULL && fast->next != 
        NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *merge(Node *head1, Node *head2) {
        // This is a "method-only" submission.
        // You only need to complete this method.
        Node *head = NULL;
        Node *temp = createNode(-1);
        head = temp;
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        // if(head1->data <= head2->data){
        //     head = head1;
        //     head1 = head1->next;
        // }
        // else{
        //     head = head2;
        //     head2 = head2->next;
        // }
        
        while(head1 != NULL && head2 != NULL){
            if(head1->data <= head2->data){
                temp->next = head1;
                head1 = head1->next;
            }
            else{
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        if(head1 == NULL){
            temp->next = head2;
        }
        else{
            temp->next = head1;
        }
        return head->next;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        Node *mid = middleNode(head);
        Node *mid_next = mid->next;
        mid->next = NULL;
        return merge(mergeSort(head), mergeSort(mid_next));
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends