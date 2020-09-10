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
bool visited[1500][1500];
int main() {
    int n, h;
    sc(n);sc(h);
    int arr[n][n];
    fi(0, n) {
        fj(0, n) {
            sc(arr[i][j]);
        }
    }
    queue<pii> q;
    q.push(mp(0,0));
    while (!q.empty()) {
        pii p = q.front();
        // cout << p.first << " " << p.second << endl;
        q.pop();
        if (p.first == n - 1 && p.second == n - 1) {
            cout << "yes" << endl;
            return 0;
        }
        if (p.first - 1 >= 0 && !visited[p.first - 1][p.second] && abs(arr[p.first - 1][p.second] - arr[p.first][p.second]) <= h) {
            q.push(mp(p.first - 1, p.second));
            visited[p.first - 1][p.second] = true;
        }
        if (p.first + 1 < n && !visited[p.first + 1][p.second] && abs(arr[p.first + 1][p.second] - arr[p.first][p.second]) <= h) {
            q.push(mp(p.first + 1, p.second));
            visited[p.first + 1][p.second] = true;
        }
        if (p.second - 1 >= 0 && !visited[p.first][p.second - 1] && abs(arr[p.first][p.second - 1] - arr[p.first][p.second]) <= h) {
            q.push(mp(p.first, p.second - 1));
            visited[p.first][p.second] = true;
        }
        if (p.second + 1 < n && !visited[p.first][p.second + 1] && abs(arr[p.first][p.second + 1] - arr[p.first][p.second]) <= h) {
            q.push(mp(p.first, p.second + 1));
            visited[p.first][p.second + 1] = true;
        }
    }

    cout << "no" << endl;
    
    return 0;
}