import java.util.*;
public class SwapCount {
    public static long countSwaps(String s) {
        long count = 0;
        Vector<Integer> v = new Vector<Integer>();
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i) == '[') {
                v.add(i);
            }
        }
        long sum=0;
        int p=0;
        char[]S = s.toCharArray();
        for(int i=-0;i<S.length;i++) {
            if(S[i] == '[') {
                count++;
                p++;
        }
        else if(S[i] == ']'){
            --count;
        }
        if(count < 0) {
            sum += v.get(p)-i;
            p=0;
        }
        }
    }
}
