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
short arr[10002][10002];
int main() {
    int n, m;
    sc(n);sc(m);

    while (m--) {
        int x, y, w, h;
        sc(x);sc(y);sc(w);sc(h);
        y++;x++;
        arr[y][x]++;
        arr[y + h][x]--;
        arr[y][x + w]--;
        arr[y + h][x + w]--;
    }
    int count = 0;

    fi(1, n + 1) {
        fj(1, n + 1) {
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            if (arr[i][j] % 2 == 0) {
                count++;
            }
        }
    }
    cout << n * n - count << endl;
    // fi(0, n) {
    //     fj(0, n) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return 0;
}