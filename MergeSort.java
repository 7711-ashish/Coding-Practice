import java.io.*;
import java.util.*;
public class MergeSort {
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
    public static void mergeSortArray(int []arr,int l,int mid,int r)
    {
        int start2 = mid+1;
        if(arr[mid]<arr[start2])
        {
            return;
        }
        while(l<=mid && start2<=r)
        {
            if(arr[l]<arr[start2])
            {
                l++;
            }
            else
            {
                int temp = arr[start2];
                for(int i=start2-1;i>=l;i--)
                {
                    arr[i+1]=arr[i];
                }
                arr[l]=temp;
                l++;
                mid++;
                start2++;
            }
        }
    }
    public static void mergeSort(int[] arr,int l,int r){
        if(l<r) 
        {
            int mid = l +(r-l)/2 ;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            mergeSortArray(arr,l,mid,r);
        }
    }
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n =  sc.nextInt();
        int []arr= new int[n];
        for(int i=0; i<n;i++)
        {
            arr[i] = sc.nextInt();
        }
        mergeSort(arr,0,arr.length-1);
        for(int i=0;i<n;i++)
            System.out.println(arr[i]);
    }
}
