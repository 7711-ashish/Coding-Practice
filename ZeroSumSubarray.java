import java.io.*;
import java.util.*;
public class ZeroSumSubarray {
    public static void main(String []args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); 
        long[] a = new long[n];
        for(int i = 0; i < n; i++)
        {
            a[i] = sc.nextLong();
        }
        HashMap<int,int>mp=new HashMap<>();
        long sum =0, cnt=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum == 0)
                cnt++;

            
            
        }
        sc.close();
    }
}
