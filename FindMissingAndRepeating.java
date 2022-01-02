
import java.util.*;
public class FindMissingAndRepeating {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[]arr= new int[n+1];
        Arrays.fill(arr,0);       
        for(int io = 1; io < n+1; io++) {
            arr[io]= sc.nextInt();
        }
        boolean present[] = new boolean[n+1];
        int repeating=0,missing=0;
        Arrays.fill(present,false);
        for(int i = 1; i < n+1; i++) {
            if(present[arr[i]]==true)
                repeating = arr[i];
            present[arr[i]] = true;
        }
        for(int i = 1; i < n+1; i++) {
            if(present[i]==false)
                {
                    missing = i;
                    break;
                }
        }
        System.out.println("Reapeating" + repeating + "Missing"+ missing);
        sc.close();
    }
}
//Above solution uses extra space 