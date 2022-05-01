#include<iostream>
#include <list>
#include <limits.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};
Node * newNode(int data){
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int ans = INT_MIN;
int findLargestSum(Node *root){
    if(root==NULL)
        return 0;
    int sum = root->data+findLargestSum(root->left)+findLargestSum(root->right);
    ans = max(ans,sum);

    return sum;
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
    cout<<findLargestSum(root);
    cout<<ans;
    return 0;
}