public class KnapSack01 {
    static long KnapSack01Util(int value[], int weights[], int n, int w ){
        int [][]dp = new int[n+1][w+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=w;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            int W = weights[i-1];
            int V = value[i-1];
            for(int j=0;j<=w;j++)
            {
                if(j<W){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=Math.max(dp[i-1][j],dp[i-1][j-W]+V);
                }
            }
        }
        return dp[n][w];
    }
    public static void main(String[] args)
    {
        int value[] = {60, 100, 120};
        int weights[] = {10, 20, 30};
        int n = value.length;
        int w = 50;
        System.out.println(KnapSack01Util(value, weights, n, w));
    }
}
