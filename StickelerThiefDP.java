import java.util.Scanner;

public class StickelerThiefDP {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int []arr= new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i]= in.nextInt();
        }
        int []dp= new int[n];
        dp[0]= arr[0];
        dp[1]= arr[1];
        dp[2]= arr[0]+arr[2];
        int ans = Math.max(dp[1], dp[2]);
        for(int i=3;i<3;i++)
        {

        }
        System.out.println(ans);
        in.close();

    }    
}
