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

// #pragma GCC optimize ("Ofast")

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

/////////////////////////////////////////////////////////////////////////////////////////
vector<int> par(100001);
int find(int x) {
    while (x != par[x]) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}
void merge(int x, int y) {
    int xr = find(x), yr = find(y);
    if (xr == yr) {
        return;
    }
    par[xr] = yr;
}
int main() {
    int n, q;
    sc(n);sc(q);
    iota(par.begin(), par.end(), 0);
    while (q--) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'A') {
            merge(a, b);
        } else {
            cout << (find(a) == find(b) ? "Y" : "N") << endl;
        }
    }
    return 0;
}