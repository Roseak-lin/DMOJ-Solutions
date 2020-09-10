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

int arr[1000002];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m, c;
    bool hasOne = false;
    cin >> n >> m >> c;
    deque<int> q1, q2;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int i = 0;
    for (; i < m; i++) {
        while (!q1.empty() && arr[i] <= arr[q1.back()]) {
            q1.pop_back();
        }
        while (!q2.empty() && arr[i] >= arr[q2.back()]) {
            q2.pop_back();
        }
        q2.push_back(i);
        q1.push_back(i);
    }
    for (; i < n; i++) {
        if (arr[q2.front()] - arr[q1.front()] <= c) {
            hasOne = true;
            cout << i - m + 1 << endl;
        }
        while (!q1.empty() && q1.front() <= i - m) {
            q1.pop_front();
        }
        while (!q2.empty() && q2.front() <= i - m) {
            q2.pop_front();
        }
        while (!q1.empty() && arr[i] <= arr[q1.back()]) {
            q1.pop_back();
        }
        while (!q2.empty() && arr[i] >= arr[q2.back()]) {
            q2.pop_back();
        }
        q2.push_back(i);
        q1.push_back(i);
    }
    if (arr[q2.front()] - arr[q1.front()] <= c) {
        hasOne = true;
        cout << i - m + 1 << endl;
    }
    if (!hasOne) {
        cout << "NONE" << endl;
    }
    return 0;
}