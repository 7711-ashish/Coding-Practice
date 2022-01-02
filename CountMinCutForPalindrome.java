// Given a string, find the minimum cuts needed to partition it such that each partition is a palindrome.

// For example,

// BABABCBADCD – The minimum cuts required are 2 as BAB|ABCBA|DCD.
// ABCBA – The minimum cuts required are 0 as ABCBA is already a palindrome.
// ABCD – The minimum cuts required are 3 as A|B|C|D.
public class CountMinCutForPalindrome {
    static boolean isPalindrome(String s, int i,int j){
        while(i<=j){
            if(s.charAt(i)!=s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    static int palinDromeCut(String s, int i, int j){
        if(i==j||isPalindrome(s,i,j))
            return 0;
        int min = Integer.MAX_VALUE;
        for(int k=i;k<=j-1;k++){
            int count = palinDromeCut(s,i,k)+palinDromeCut(s,k+1,j)+1;
            if(count<min){
                min=count;
            }
        }
        return min;
    }
    static int palinDromeCut(String s){
        int i=0;
        int j= s.length()-1;
        return palinDromeCut(s,i,j);
    }
    public static void main(String[] args){
        String s = "BABABCBADCD";
        System.out.println(palinDromeCut(s));
    }
}
