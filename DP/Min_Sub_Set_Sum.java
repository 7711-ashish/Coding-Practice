package DP;
import java.util.*;
public class Min_Sub_Set_Sum {
    static ArrayList<Integer> isSubsetPoss(int[] array,int n, int sum)
    {
        boolean[][]isSubset = new boolean[n][sum+1];
        for(int i=0;i<n;i++)
        {
            isSubset[i][0] = true;
        }
        for(int i=0;i<sum+1;i++)
        {
            isSubset[0][i] = false;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(array[i]<=j)
                {
                    isSubset[i][j] = isSubset[i-1][j] || isSubset[i-1][j-array[i]];
                }
                else
                {
                    isSubset[i][j] = isSubset[i-1][j];
                }
            }
        }
        ArrayList<Integer> result = new ArrayList<Integer>();
        for(int i=0;i<=sum;i++)
        {
            if(isSubset[n-1][i])
            {
                result.add(i);
            }
        }
        return result;
    }
    static int MinSubSetSum(int[] arr,int n )
    {
        int range = 0;
        for(int i=0;i<n;i++)
        {
            range = range + arr[i];
        }
        ArrayList<Integer> result = isSubsetPoss(arr,n,range);
        int min = Integer.MAX_VALUE;
        for(int i=0;i<result.size();i++)
        {
            if(result.get(i)<min)
            {
                min = result.get(i);
            }
        }
        return min;
    }
    public static void main(String[] args)
    {
        int[] arr = {1,2,3,4,5,6,7,8,9,10};
        int n = arr.length;
        System.out.println(MinSubSetSum(arr,n));
    }
}
