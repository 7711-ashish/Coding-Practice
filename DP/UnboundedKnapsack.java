package DP;
import java.io.*;
import java.util.*;
public class UnboundedKnapsack {
    public static int unbounded_knapsack(int []ar, int weights)
    {
        int t[][]  = new int[ar.length+1][weights+1];
       
        for(int i=0;i<=ar.length;i++)
        {
            for(int j=0;j<=weights;j++)
            {
                if(i==0 || j==0)
                {
                    t[i][j]=0;
                }
                else if(ar[i-1]<=j)
                {
                    t[i][j]=Math.max(ar[i-1]+t[i-1][j-ar[i-1]],t[i-1][j]);
                }
                else
                {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[ar.length-1][weights];
    }
    public static void main(String[]args)
    {
        Scanner sc = new Scanner(System.in);
        
        
        
        sc.close();
    }
}