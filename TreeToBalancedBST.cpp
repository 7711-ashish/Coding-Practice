#include<iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

void storeBSTNodes(Node *root, vector<Node*> &nodes)
{ 
    if(root==NULL)
        return;
    storeBSTNodes(root->, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}

Node *BuildComBSTUtil(vector<Node*> &nodes, int start, int end)
{ 
    if(start>end)   
        return NULL;
    int mid = (start+end)/2;
    Node *root = nodes[mid];

    root->left = BuildComBSTUtil(nodes, start, mid-1);
    root->right = BuildComBSTUtil(nodes, mid+1, end);
    return root;
}

Node *BuildComBST(Node *root){
    vector<Node*> nodes;
    storeBSTNodes(root, nodes);
    int start=0,end = nodes.size()-1;
    return BuildComBSTUtil(nodes, start, end);
}
Node *newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void preOrder(Node *root)
{
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->left->left = newNode(5);
    root->left->left->left->left = newNode(6);
    root->left->left->left->left->left = newNode(7);
    root->left->left->left->left->left->left = newNode(8);
    Node *root1 = BuildComBST(root);
    cout<<"Preorder Traversal Of complete tree";
    preOrder(root1);
    return 0;
}
