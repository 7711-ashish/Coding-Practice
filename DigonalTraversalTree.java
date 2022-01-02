import java.io.*;
import java.util.*;
public class DigonalTraversalTree{
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
    static void diigonalTraversalUtil(Node root,int d,TreeMap<Integer,Vector<Integer>>digonal){
        if(root == null)
            return;
        Vector<Integer>k = digonal.get(d);
        if(k == null){
            k = new Vector<Integer>();
            digonal.put(d,k);
        }
        else{
            k.add(root.data);
        }
        diigonalTraversalUtil(root.left,d+1,digonal);
        diigonalTraversalUtil(root.right,d,digonal);
    }
    static void digonalTravale(Node root)
    {
        TreeMap<Integer,Vector<Integer>>digonal = new TreeMap<Integer,Vector<Integer>>();
        diigonalTraversalUtil(root,0,digonal);
        for(Map.Entry<Integer,Vector<Integer>>entry : digonal.entrySet()){
            System.out.println(entry.getValue());
        }
    }
    public static void main(String []args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = null;
        while(n-->0){
            int data = sc.nextInt();
            Node node = new Node(data);
            if(root == null){
                root = node;
            }
            else{
                Node temp = root;
                while(true){
                    if(temp.data > data){
                        if(temp.left == null){
                            temp.left = node;
                            break;
                        }
                        else{
                            temp = temp.left;
                        }
                    }
                    else{
                        if(temp.right == null){
                            temp.right = node;
                            break;
                        }
                        else{
                            temp = temp.right;
                        }
                    }
                }
            }
        }
        digonalTravale(root);
    }
}