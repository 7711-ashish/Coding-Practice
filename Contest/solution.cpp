#include<bits/stdc++.h>
using namespace std;

#define ll                          long long
#define ld                          long double
#define endl                        "\n"
#define Endl                        "\n"
#define pb                          push_back
#define mp                          make_pair
#define ff                          first
#define ss                          second
#define loop(i,a,b)                 for(ll i=a;i<b;i++)
#define loop2(i,a,b)                 for(ll i=a;i<b;i+=2)
#define rloop(i,a,b)                for(ll i=a;i>=b;i--)
#define fill(a,v)                   memset(a, v, sizeof a)
#define all(a)                      a.begin(), a.end()
#define rall(vec)                   vec.rbegin(),vec.rend()
#define sortv(a)                    sort(a.begin(),a.end())
#define set_bits(a)                 __builtin_popcount(a)
#define fast_io                     ios_base::sync_with_stdio(false);\
                                    cin.tie(NULL)


// -------------------------------code starts here--------------------------------- //
void solve()
{
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast_io;
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}