public class DoubleHelix {
    public static int countWaySum(int []arr1,int[]arr2,int n,int m){
        int result =0;
        int result1=0; 
        int result2=0;
        int j=0;
        for(int i=0;i<m;i++)
        {
            result2+=arr2[i];
            while(j<n && arr1[j]<arr2[i])
            {
                result1+=arr1[j];
                j++;
            }
            if(j<n && arr1[j]==arr2[i])
            {
                result1+=arr1[j];
                j++;
                result = Math.max(result1, result2);
                result1=0;
                result2=0;
            }
        }
        while(j<n){
            result1+=arr1[j];
            j++;
        }
    }
    public static void main(String[] args){

    }
}
