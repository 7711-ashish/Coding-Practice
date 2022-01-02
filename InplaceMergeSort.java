//it is a shell sort approach usig gap method

public class InplaceMergeSort {
    static int nextGap(int gap) {
        if (gap < 1) {
            return 1;
        }
        return (int)Math.ceil(gap /2.0);
    }
    static void swap(int []nums,int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }



    // Merging the subarrays using shell sorting
    // Time Complexity: O(nlog n)
    // Space Complexity: O(1)
    static void InplaceMerge(int[] nums,int start,int end)
    {
        int gap = end - start+1;
        for(gap = nextGap(gap); gap > 0; gap = nextGap(gap))
        {
            for(int i = start; i+gap<= end; i++)
            {
                int j = i+gap;
                if(nums[j] < nums[i])
                {
                    swap(nums,i,j);
                }
            }
        }
    }


    // merge sort makes log n recursive calls
    // and each time calls merge()
    // which takes nlog n steps
    // Time Complexity: O(n*log n + 2((n/2)*log(n/2)) +
    // 4((n/4)*log(n/4)) +.....+ 1)
    // Time Complexity: O(logn*(n*log n))
    // i.e. O(n*(logn)^2)
    // Space Complexity: O(1)
    static void mergSort(int[] nums,int start,int end)
    {
        if(start==end)
        {
            return;
        }
            int mid = (start+end)/2;
            mergSort(nums,start,mid);
            mergSort(nums,mid+1,end);
            InplaceMerge(nums,start,end);
        
    }
    public static void main(String[] args) {
        int[] nums = {1,2,3,4,5,6,7,8,9,10};
        mergSort(nums,0,nums.length-1);
        for(int i = 0; i<nums.length; i++)
        {
            System.out.print(nums[i]+" ");
        }
    }
}
