#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<cassert>
#include<assert.h>
#include<cmath>
#include<random>
#include<vector>
#include<bitset>
#include<set>
#include<memory>
#include<numeric>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<list>
#include<deque>
#include<stack>
#include<sstream>
#include<math.h>
#include <ctype.h>

typedef long long ll;

template <typename T> void sc(T &number) { bool negative = false; register int c; number = 0;  c = getchar(); if (c=='-') { negative = true;  c = getchar(); } for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48; if (negative) number *= -1; }

#pragma GCC optimize ("Ofast")

#define fi(x, y) for(int i = x; i < y; i++)
#define fj(x, y) for(int j = x; j < y; j++)
#define mp make_pair
#define MOD 1000000007
#define endl "\n"
#define print2dArr(a,r,c) cout << #a << ":\n"; for(int i = 0; i < r; i++) { for(int j = 0; j < c; j++) { cout << a[i][j] << " "; } cout << endl;}
#define pi 2 * asin(1.0)
#define elif else if
#define pii pair<int, int>
#define pq priority_queue
#define tie cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

using namespace std;

struct point
{
    int x, y;
    point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////
ll n, v[5001], p[5001], votes = 0, dp[5001][5001], m = __LONG_LONG_MAX__;
int main() {
    sc(n);
    // val = p, cost = v
    fi(1, n + 1) {
        sc(v[i]);sc(p[i]);
        v[i] = v[i] / 2 + 1;
        votes += p[i];
    }
    memset(dp, 0x3f3f3f3f, sizeof dp);
    dp[0][0] = 0;
    fi(1, n + 1) {
        fj(0, 5001) {
            dp[i][j] = dp[i - 1][j];
            if (j - p[i] >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - p[i]] + v[i]);
            }
        }
    }
    
    fi(0, 5001) {
        if (i > votes - i) {
            m = min(m, dp[n][i]);
        }
    }
    cout << m << endl;
    
    return 0;
}