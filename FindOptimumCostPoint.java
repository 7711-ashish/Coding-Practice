
public class FindOptimumCostPoint {
    static double sq(double x){ return((x)*(x));}
    static int EPS =(int)(1e-6)+1;
    static int N =5;
    static class point{
        int x,y;
        point(){}
        public point(int x, int y){
            this.x = x;
            this.y= y;
        }
    }
    static class line {
        int a, b, c;
 
        public line(int a, int b, int c)
        {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    };
    static double distace(double x, double y,point p){
        return Math.sqrt(sq(x-p.x)+sq(y-p.y));
    }
    static double compute(point p[], int n, line l, double x)
    {
        double res = 0;
        double y = -1*(l.c + l.a*x)/l.b;
        for(int i=0;i<n;i++)
        {
            res += distace(x,y,p[i]);
        }
        return res;
    }
    static double findOptimumCostUtil(point p[], int n, line l)
    {
        double low = -1e6;
        double high = 1e6;
        while((high-low)>EPS)
        {
            double mid1 = low + (high-low)/3;
            double mid2 = high - (high-low)/3;
            double dist1 = compute(p,n,l,mid1);
            double dist2 = compute(p,n,l,mid2);
            if(dist1<dist2)
                high=mid2;
            else    
                low = mid1;
        }
        return compute(p,n,l,(low+high)/2);
    }
    static double FindOptimumCost(int p[][], line l)
    {
        point []p1 = new point[N];
        for(int i=0;i<N;i++)
        {
            p1[i]= new point(p[i][0], p[i][1]);
        }
        return findOptimumCostUtil(p1, N, l);
    }
    public static void main(String[] args) {
        line l = new line(1, -1, -3);
        int points[][] = { { -3, -2 },
                           { -1, 0 },
                           { -1, 2 },
                           { 1, 2 },
                           { 3, 4 } };
        System.out.println(FindOptimumCost(points, l));
    }
}
