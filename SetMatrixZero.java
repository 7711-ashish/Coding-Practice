/*

Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1
Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.

*/

import java.util.*;
import java.io.*;
public class SetMatrixZero {
    static void setToZero(int[][]A){
        int m=A.length,n=A[0].length;
    int r1=0,c1=0;
    for(int i=0;i<n;i++){
        if(A[0][i]==0){
            r1=1;
            break;
        }
    }
    for(int i=0;i<m;i++){
        if(A[i][0]==0){
            c1=1;
            break;
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(A[i][j]==0){
                A[i][0]=0;
                A[0][j]=0;
            }
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(A[i][0]==0||A[0][j]==0)
             A[i][j]=0;
        }
    }
    if(r1==1){
        for(int i=0;i<n;i++)
         A[0][i]=0;
    }    
    if(c1==1){
        for(int i=0;i<m;i++)
         A[i][0]=0;
    }
    }
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int n=5,w=5;
        int [][]matrix = new int [n][w];
        for(int i=0;i<n;i++){
            for(int j=0;j<w;j++){
                matrix[i][j]= sc.nextInt();
            }
        }
        setToZero(matrix);
        for(int i=0;i<n;i++){
            for(int j=0;j<w;j++){
                System.out.print(matrix[i][j]+" ");
            }
            System.out.println();
        }
        sc.close();
    }

}
