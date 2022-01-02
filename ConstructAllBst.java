import java.util.*;
public class ConstructAllBst {
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
    static ArrayList<node> construct(int start, int end){
        ArrayList<node>list = new ArrayList<node>();
        if(start > end){
            list.add(null);
            return list;
        }
        for(int i = start; i <= end; i++){
            ArrayList<node>left = construct(start, i-1);
            ArrayList<node>right = construct(i+1, end);
            for(node l:left){
                for(node r:right){
                    node root = createNode(i);
                    root.left = l;
                    root.right = r;
                    list.add(root);
                }
            }
        }
        return list;
    }
    public static void main(String[] args)
    {
        node tree =createNode(0);
        tree.left = createNode(1);
        tree.right = createNode(2);
        tree.left.left = createNode(3);
        tree.left.right = createNode(4);
        tree.right.left = createNode(5);
        
    }    
}
