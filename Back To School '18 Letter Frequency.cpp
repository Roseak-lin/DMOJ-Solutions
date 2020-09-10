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
int freq[26][1000001];
int q;
int main() {
    tie;
    string s;
    getline(cin, s);
    cin >> q;
    if (s[0] != ' ') freq[s[0] - 97][0] = 1;
    fi(1, (int)s.length()) {
        if (s[i] != ' ') freq[s[i] - 97][i] = freq[s[i] - 97][i - 1] + 1;
        fj(0, 26) {
            if (s[i] - 97 == j) continue;
            freq[j][i] = freq[j][i - 1];
        }
    }

    while(q--) {
        int n, m;
        char c;
        cin >> n >> m;
        cin >> c;
        if (m == 1) {
            cout << freq[c - 97][m - 1] << endl;
        } else {
            cout << freq[c - 97][m - 1] - freq[c - 97][n - 2] << endl;
        }
    }
    return 0;
}