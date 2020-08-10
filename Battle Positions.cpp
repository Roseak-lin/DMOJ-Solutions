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

int main() {
    int s, n, j;
    sc(s);sc(n);sc(j);
    int diff[s + 1] = {};
    while (j--) {
        int xi, xf, k;
        sc(xi);sc(xf);sc(k);
        diff[xi] += k;
        diff[xf + 1] -= k;
    }
    int bad = 0;
    fi(1, s + 1) {
        diff[i] += diff[i - 1];
        if (diff[i] < n) {
            bad++;
        }
    }
    printf("%d", bad);
    return 0;
}