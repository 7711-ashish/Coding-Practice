import java.util.*;
import java.io.*;
public class TopViewTree {
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data=data;
        }
    }
    static void topView(Node root, int level, int hd, HashMap<Integer,Integer> map){
        if(root==null)
            return;
        if(!map.containsKey(hd)){
            map.put(hd, root.data);
        }
        topView(root.left, level+1, hd-1, map);
        topView(root.right, level+1, hd+1, map);
    }
    public static void main(String[] args) {
        Node tree = new Node(0);
        tree.left = new Node(1);
        tree.right = new Node(2);
        tree.left.left = new Node(3);
        tree.left.right = new Node(4);
        tree.right.left = new Node(5);
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        topView(tree, 0, 0, map);
        for(Map.Entry<Integer,Integer> entry:map.entrySet()){
            System.out.print(entry.getValue() + " ");
        }
    }
}
