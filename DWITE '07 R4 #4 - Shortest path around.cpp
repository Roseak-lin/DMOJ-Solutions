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
    int x, y, d;
    point(int xx, int yy, int dd) {
        y = xx;
        x = yy;
        d = dd;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////
char arr[10][10];
string hold;
void solve() {
    queue<point> q;
    bool visited[10][10];
    memset(visited, 0, sizeof visited);
    fi(0, 10) {
        fj(0, 10) {
            cin >> arr[i][j];
            if (q.size() != 1 && arr[i][j] == 'X') {
                q.push(point(i, j, 0));
                visited[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        point p = q.front();
        q.pop();
        if (arr[p.y][p.x] == '#') continue;
        if (arr[p.y][p.x] == 'X' && p.d != 0) {
            cout << p.d << endl;
            return;
        }
        if (p.x - 1 > -1 && !visited[p.y][p.x - 1]) {
            q.push(point(p.y, p.x - 1, p.d + 1));
            visited[p.y][p.x - 1] = true;
        }
        if (p.x - 1 > -1 && p.y - 1 > -1 && !visited[p.y - 1][p.x - 1]) {
            q.push(point(p.y - 1, p.x - 1, p.d + 1));
            visited[p.y - 1][p.x - 1] = true;
        }
        if (p.y - 1 > -1 && !visited[p.y - 1][p.x]) {
            q.push(point(p.y - 1, p.x, p.d + 1));
            visited[p.y - 1][p.x] = true;
        }
        if (p.x + 1 < 10 && p.y - 1 > -1 && !visited[p.y - 1][p.x + 1]) {
            q.push(point(p.y - 1, p.x + 1, p.d + 1));
            visited[p.y - 1][p.x + 1] = true;
        }
        if (p.x + 1 < 10 && !visited[p.y][p.x + 1]) {
            q.push(point(p.y, p.x + 1, p.d + 1));
            visited[p.y][p.x + 1] = true;
        }
        if (p.x + 1 < 10 && p.y + 1 < 10 && !visited[p.y + 1][p.x + 1]) {
            q.push(point(p.y + 1, p.x + 1, p.d + 1));
            visited[p.y + 1][p.x + 1] = true;
        }
        if (p.y + 1 < 10 && !visited[p.y + 1][p.x]) {
            q.push(point(p.y + 1, p.x, p.d + 1));
            visited[p.y + 1][p.x] = true;
        }
        if (p.x - 1 > -1 && p.y + 1 < 10 && !visited[p.y + 1][p.x - 1]) {
            q.push(point(p.y + 1, p.x - 1, p.d + 1));
            visited[p.y + 1][p.x - 1] = true;
        }
    }
    
}

int main() {
    tie;
    fi(0, 5) {
        solve();
        cin >> hold;
    }
    return 0;
}