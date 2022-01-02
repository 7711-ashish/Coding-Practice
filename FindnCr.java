public class FindnCr {
    static int mod = 1e9+7;
    static int findnCrUtil(int n, int r) {
        if (r == 0 || r == n)
            return 1;
        return (findnCrUtil(n - 1, r - 1) + findnCrUtil(n - 1, r));
    }
}
