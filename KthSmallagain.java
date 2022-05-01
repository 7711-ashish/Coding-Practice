import java.io.*;
import java.util.*;
import javafx.util.Pair;


public class KthSmallagain {
    
    static void solve()
    {
        Scanner sc = new Scanner(System.in);
        int n=0,q=0;
        n = sc.nextInt();
        q= sc.nextInt();
        ArrayList<Pair<Integer,Integer>>arr = new ArrayList<Pair<Integer,Integer>>();
        for(int i=0;i<n;i++){
            int l=0,m=0;
            l= sc.nextInt();
            m = sc.nextInt();
            arr.add(new Pair<Integer,Integer>(l,m));
        }
        Arrays.sort(arr);
        int idx= 0;
        for(int i=1;i<n;i++)
        {
            if(arr.get(idx).getValue()>=arr.get(idx).getKey()){
                arr.get(idx).setValue(max(arr.get(idx).getValue(),arr.get(i).getValue()));
            }
            else{
                idx++;
                arr.get(idx).setKey(arr.get(i).getKey());
                arr.get(idx).setValue(arr.get(i).getValue()); 
            }
        }
        while(q-->0)
        {
            int  k =0;
            k = sc.nextInt();
            int ans = -1;
            for(int i=0;i<idx;i++){
                if(arr.get(i).getValue()-arr.get(i).getKey()+1>=k){
                    ans = arr.get(i).getKey()+k-1;
                    break;
                }
                else{
                    k-= arr.get(i).getValue()-arr.get(i).getKey()+1;
                }
            }
            System.out.println(ans);

        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- >0)
        {
            solve();
        }
        sc.close();
    }
}
