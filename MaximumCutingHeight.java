import java.util.*;
import java.io.*;

public class MaximumCutingHeight {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static boolean isPossible(ArrayList<Long>v, long mid, long m)
    {
        long sum = 0;
        for(int i=0;i<v.size();i++){
            if (mid <= v.get(i)) {
                sum += v.get(i) - mid;
            }
            if (sum ==m) {
                return true;
            }
        }
        return false;
    }
    public static long findMaxCut(ArrayList<Long>arr,Long n ,long m)
    {
        long result =0;
        long mid =0;
        long low =0;
        long high = arr.get((int)(n-1));
        while(low<high){
            mid = low+(high-low)/2;
            if(isPossible(arr,mid,m)){
                if(result<mid)
                    result = mid;
                high= mid-1;
                break;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        long n = sc.nextLong();
        long t = n;
        long m = sc.nextLong();
        ArrayList<Long> arr = new ArrayList<Long>();
        while(t-- >0)
        {
            long x = sc.nextLong();
            arr.add(x);
        }
        Collections.sort(arr); 
        System.out.println(arr.toString());
        System.out.println(findMaxCut(arr,n,m));
    }
}
