import java.util.*;
public class LeftViewTree {
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
    static void leftview(ArrayList<node>list, node root,int level){
        if(root == null){
            return;
        }
        if(list.size()==level)
            list.add(root);
        leftview(list, root.left,level+1);
        leftview(list, root.right,level+1);
    }
    public static void main(String[] args)
    {
        node tree =createNode(0);
        tree.left = createNode(1);
        tree.right = createNode(2);
        tree.left.left = createNode(3);
        tree.left.right = createNode(4);
        tree.right.left = createNode(5);
        ArrayList<node>list = new ArrayList<node>();
        leftview(list, tree,0);
        for(node n:list){
            System.out.print(n.value + " ");
        }
        inorder(tree);
        
    }    
}
