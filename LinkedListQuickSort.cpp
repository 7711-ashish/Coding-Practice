#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct Node{
    int data;
    struck Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution{
    public:
        Node *partition(Node *head, Node *tail)
        {
            Node *pivot = head;
            Node *curr = head->next;
            Node *p = tail;
            while(curr!=tail)
            {
                if(curr->data<pivot->data)
                {
                    swap(prev->next->data,curr->data);
                    prev = prev->next;
                }
                curr = curr->next;
            }  
            swap(pivot->data,prev->data);
            return prev;

        }

        void QuickSortRecur(Node *head, Node *tail){
            if(head==NULL || head == tail || tail == NULL)
            {
                return;
            }
            node *pivot = partition(head,tail);
            QuickSortRecur(head,pivot);
            QuickSortRecur(pivot->next,tail);
        }
        
        Node *tailNode(Node *node)
        {
            Node *tail = node;
            while (tail->next!=NULL){
                tail = tail->next;
            }
            return tail;
        }
        void QuickSort(Node *head)
        {
            Node *tail= tailNode(head);
            QuickSortRecur(head,tail);
        }
}
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
        a = obj.QuickSort(a);
        printList(a);
    }
    return 0;
} 

