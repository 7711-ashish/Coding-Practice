import java.util.Scanner;

public class AllocateNoOfPages{
    static boolean isPossible(int[]arr,int n,int m,int mid)
    {
        int currentsum =0;
        int stdReq = 1;
        for(int i = 0; i <n;i++){
        {
            if(arr[i]>mid)
                return false;
            if(currentsum+arr[i] > mid){
                stdReq++;
                currentsum=arr[i];
                if(stdReq>m)
                    return false;
            }
            else
             currentsum+=arr[i];
        }
        }
        return true;

    }
     public static int findpages(int[]arr, int n,int m)
    {
        int result = Integer.MAX_VALUE;
        long sum =0;
        if(n<m)
            return -1;
        for(int i=0;i<n;i++)
            sum += arr[i];
        
        int  start = 0,end = (int)sum;
        int mid =0;
        while(start<end)
        {
            mid = (start+end)/2;
            if(isPossible(arr,n,m,mid))
            {
                result= mid;
                end=mid-1;
            }
            else
                start = mid+1;
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = 0;
        int m=0;
        n = sc.nextInt();
        m = sc.nextInt();
        int []arr = new int[n];
        for(int i=0; i<n;i++) { 
            arr[i]= sc.nextInt();
        }
        System.out.println(findpages(arr,arr.length,m));
        sc.close();
    }
}