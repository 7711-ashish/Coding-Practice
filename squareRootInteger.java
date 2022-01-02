// import java.io.*;
import java.util.*;

class squareRootInteger{
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int n= in.nextInt();
        int count=0;
        for(int i=1;i*i<n;i++){
            
               count++; 
        }
        System.out.println(count);
        in.close();
    }
}

//time complexity is O(sqrt(n)) where n is the rangein which we have find the total no of perfect square numbers