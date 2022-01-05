// { Driver Code Starts
//
/*
Algorithm: buildTree() 
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick the next element in the next recursive call. 
2) Create a new tree node tNode with the data as the picked element. 
3) Find the picked element's index in Inorder. Let the index be inIndex. 
4) Call buildTree for elements before inIndex and make the built tree as a left subtree of tNode. 
5) Call buildTree for elements after inIndex and make the built tree as a right subtree of tNode. 
6) return tNode.
*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int index=0;
    int search(int in[], int start, int end,int value)
    {
        for(int i=start; i<=end;i++)
        {
            if(in[i]==value)
            {
                return i;
            }
        }
        return -1;
    }
    Node* buildBST(int in[],int pre[], int start, int end)
    {
        if(start > end) return NULL;
        int value = pre[index];
        index++;
        Node *node = new Node(value);
        int  position = search(in, start, end, value);
        if(start==end) return node;
        node->left=buildBST(in,pre,start, position-1);
        node->right=buildBST(in,pre,position+1,end);
        return node;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        Node *node = buildBST(in,pre,0,n-1);
        return node;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends