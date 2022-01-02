import java.util.Scanner;
public class MIddleOfThree {
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c= in.nextInt();
        int d = Math.max(a, Math.max(b, c));
        int e= Math.min(a, Math.min(b, c));
        int ans= (a+b+c)-(d+e);
        System.out.println(ans);
        in.close();
    }
}
