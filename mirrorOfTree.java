class mirrorOfTree{
    static class node{
        int value;
        node left;
        node right;
    }
    static node createNode(int value){
        node n = new node();
        n.value = value;
        n.left = null;
        n.right = null;
        return n;
    }
    static void inorder(node root){
        if(root == null){
            return;
        }
        inorder(root.left);
        System.out.print(root.value + " ");
        inorder(root.right);
    }
    static node mir(node mirror)
    {
        if(mirror == null)
        {
            return null;
        }
        node temp = createNode(mirror.value);
        temp.left = mir(mirror.right);
        temp.right = mir(mirror.left);
        return temp;
    }
    public static void main(String[] args)
    {
        node tree =createNode(0);
        tree.left = createNode(1);
        tree.right = createNode(2);
        tree.left.left = createNode(3);
        tree.left.right = createNode(4);
        tree.right.left = createNode(5);
        inorder(tree);
        System.out.println();
        node mirror = mir(tree);
        inorder(mirror);
    }
}