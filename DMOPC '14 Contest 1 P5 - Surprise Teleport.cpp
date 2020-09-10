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
#include<numeric>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<list>
#include<deque>
#include<stack>
#include<sstream>
#include<math.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")

typedef long long ll;

#define fi(x, y) for(int i = x; i < y; i++)
#define fj(x, y) for(int j = x; j < y; j++)
#define sc(n) scanf("%d", &n);
#define mp make_pair
#define MOD 1000000007
#define endl "\n"
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int __i__=0;__i__<r;__i__++){for(int __j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}

using namespace std;

struct point
{
    int x, y, d;
    point(int xx, int yy, int dd) {
        x = xx;
        y = yy;
        d = dd;
    }
};


int main() {
    int n, m, sx, sy, ex, ey, t;
    sc(n);sc(m);sc(sy);sc(sx);sc(ey);sc(ex);
    char grid[n][m] = {};
    fi(0, n) {
        fj(0, m) {
            cin >> grid[i][j];
        }
    }
    sc(t);
    fi(0, t) {
        int x, y;
        sc(y);sc(x);
        grid[y][x] = 'T';
    }

    queue<point> q;
    q.push(point(sx, sy, 0));
    int mini, min2 = INT_MAX;
    bool visited[n][m] = {false};
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, d = q.front().d;
        q.pop();
        if (grid[y][x] == 'T') {
            min2 = min(min2, d);
        }
        if (x == ex && y == ey) {
            mini = d;
            break;
        }
        if (x >= m || y >= n || y < 0 || x < 0 || visited[y][x] || grid[y][x] == 'X') {
            continue;
        } else {
            visited[y][x] = true;
            q.push(point(x + 1, y, d + 1));
            q.push(point(x - 1, y, d + 1));
            q.push(point(x, y - 1, d + 1));
            q.push(point(x, y + 1, d + 1));
        }
    }
    printf("%d", mini - min2);
    
    return 0;
}