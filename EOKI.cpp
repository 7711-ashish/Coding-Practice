#include<bits/stdc++.h>

using namespace std;

#define ll                          long long
#define mod                         1000000007
#define f                           first
#define s                           second
#define pb                          push_back
#define mk                          make_pair
#define gcd(a,b)                    __gcd(a,b)
#define lcm(a,b)                    a/gcd(a,b)*b
#define fast_io                     ios_base::sync_with_stdio(false);\
                                    cin.tie(NULL)
#define PI                          3.1415926535897932384626
#define INF                         1e18
#define NINF                        -1e18

bool flg = false;

const int dir4[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

const int dir8[8][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}, {1, 1}, {1, -1}, { -1, 1}, { -1, -1}};

/--------------------------------------------------------code starts here--------------------------------------------------------------/


void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


bool isPossible(ll arr[], ll no, ll woodreq, ll height) {
    ll amt = 0;
    for (ll i = 0; i < no; i++) {
        if (arr[i] >= height)
            amt += (arr[i] - height);
    }
    if (amt >= woodreq)return true;
    return false;
}



int main()
{
    fast_io;
    // file();
    ll no , woodreq;
    cin >> no >> woodreq;
    ll arr[no];
    ll minHei = 0 , maxHei = NINF;
    ll ans = -1;
    for (ll i = 0; i < no; i++) {
        cin >> arr[i];
        maxHei = max(maxHei , arr[i]);
    }

    while (minHei <= maxHei) {
        ll height = minHei + (maxHei - minHei) / 2;
        if (isPossible(arr, no, woodreq, height)) {
            ans = height;
            minHei = height + 1;
        }
        else {
            maxHei = height - 1;
        }
    }
    cout << ans;
    return 0;
}