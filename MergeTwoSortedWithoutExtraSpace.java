import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

// Time COmplexity = O(n+m)*log(n+m);
//Space 1

public class MergeTwoSortedWithoutExtraSpace {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int  n = sc.nextInt();
        int m = sc.nextInt();
        int [] arr1= new int[n];
        int []arr2 = new int[m];
        for(int i=0;i<n;i++){
            arr1[i] = sc.nextInt();
        }
        for(int i=0;i<n;i++){
            arr2[i] = sc.nextInt();
        }
        int i=n-1;
        int j=0;
        while(i>=0 &&j<m){
            if(arr1[i]>arr2[j]){
                int temp=arr1[i];
                arr1[i]=arr2[j];
                arr2[j]=temp;
                i--;
                j++;
            }
            else{
                break;
            }
        }
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        sc.close();
    }
}
