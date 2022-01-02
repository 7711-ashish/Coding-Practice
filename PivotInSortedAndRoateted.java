import java.util.Scanner;

public class PivotInSortedAndRoateted {
    public static int pivotInSortedAndRoateted(int []arr, int low,int high,int lowerBound,int upperBound)
    {
        int mid = low + (high - low) / 2;
     
    if (mid == lowerBound) {
        if (mid == upperBound) {
            // Only 1 element
            return mid;
        } else if (arr[mid] >= arr[mid + 1]) {
            // Pivot is the greater element
            return mid;
        }
    } else if (mid == upperBound) {
        if (arr[mid] >= arr[mid - 1]) {
            // Pivot is the greater element
            return mid;
        }
    } else {
        if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1]) {
            // Mid value is the pivot
            return mid;
        } else if (arr[mid] > arr[high]) {
            // The Pivot is in the second half
            return pivotInSortedAndRoateted(arr, mid + 1, high, lowerBound, upperBound);
        } else if (arr[mid] < arr[high]) {
            // The Pivot is in the first half
            return pivotInSortedAndRoateted(arr, low, mid - 1, lowerBound, upperBound);
        }
    }
     
    return -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t= sc.nextInt();
        while(t-->0)
        {
            int  n= sc.nextInt();
            int arr[]= new int[n];
            for(int i=0;i<n;i++)
            {
                arr[i] = sc.nextInt();
            }
            int ans = pivotInSortedAndRoateted(arr,0,n,0,0);
            System.out.println(ans);
        }
        sc.close();
    }
}
