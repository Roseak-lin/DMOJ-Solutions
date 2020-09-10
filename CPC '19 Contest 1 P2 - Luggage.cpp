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

// struct point
// {
//     int x, y, d;
//     point(int xx, int yy, int dd) {
//         y = xx;
//         x = yy;
//         d = dd;
//     }
// };
// // sorting maps by second element
// struct comp {
//     template <typename T>
//     bool operator()(const T &l, const T &r) const { 
//         if (l.second == r.second) { 
//             return l < r; 
//         }
//         return l.second > r.second; 
//     }
// };

/////////////////////////////////////////////////////////////////////////////////////////
int arr[200001];
int main() {
    int n, k;
    sc(n);sc(k);
    fi(0, n) {
        sc(arr[i]);
    }
    if (n == 1) {
        cout << 1 << endl;
        exit(0);
    }
    sort(arr, arr + n);
    int p1 = 0, p2 = 1, mx = 1;
    while (p2 != n) {
        if (arr[p2] - arr[p1] > k) {
            p1++;
            if (p1 == p2) {
                p2++;
            }
        }
        if (arr[p2 + 1] - arr[p1] <= k && p2 + 1 < n) {
            mx = max(mx, p2 + 1 - p1 + 1);
        }
        if (arr[p2] - arr[p1] <= k) {
            mx = max(p2 - p1 + 1, mx);
        }
        p2++;
    }
    cout << mx << endl;
    return 0;
}