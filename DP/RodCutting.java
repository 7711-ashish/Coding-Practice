package DP;
import java.io.*;
import java.util.*;
public class RodCutting {
    public static int rodCuttingMax(int []length, int []price, int n, int l)
    {
        int t[][]  = new int[n+1][l+1];
        for(int i=0;i<+1;i++)
        {
            for(int j=0;j<=l;j++)
            {
                if(i==0 || j==0)
                {
                    t[i][j]=0;
                }
                else if(length[i-1]<=j)
                {
                    t[i][j]=Math.max(price[i-1]+t[i-1][j-length[i-1]],t[i-1][j]);
                }
                else
                {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][l];
    }
    public static void main(String[]args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int l = sc.nextInt();
        int []length = new int[n];
        int []price = new int[n];
        for(int i=0;i<n;i++)
        {
            length[i] = sc.nextInt();
            price[i] = sc.nextInt();
        }
        System.out.println(rodCuttingMax(length, price, n, l));
        sc.close();
    }
}
