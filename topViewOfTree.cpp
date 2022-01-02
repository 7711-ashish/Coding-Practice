#include<iostream> 
#include<bits/stdc++.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
}NODE;
NODE *head = null;
void push (int data)
{
    NODE *temp = head
    if(head == null)
    {
        head = new NODE(data);
        return;
    }
    else if(head->data > data)
    {
        if(head->left == null)
        {
            head->left = new NODE(data);
            return;
        }
        else
        {
            push(data, head->left);
        }
    }
    else
    {
        if(head->right == null)
        {
            head->right = new NODE(data);
            return;
        }
        else
        {
            push(data, head->right);
        }
    }
    
}