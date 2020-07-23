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
#include <ctype.h>

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
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int i = 0; i < r; i++){for(int j = 0; j < c; j++){cout<<a[i][j]<<" ";}cout<<endl;}
#define pi 2 * asin(1.0)

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

set<string> v;

void solve() {
    string s;
    cin >> s;
    string f, e;

    if (s.find('+') > s.length()) {
        f = s.substr(0, s.find('@') + 1);
        e = s.substr(s.find('@') + 1, s.length());
    } else { 
        f = s.substr(0, s.find('+'));
        e = s.substr(s.find('@'), s.length());
    }
    while (f.find('.') <= s.length()) {
        f.erase(f.find('.'), 1);
    }
    transform(e.begin(), e.end(), e.begin(), ::tolower); 
    transform(f.begin(), f.end(), f.begin(), ::tolower); 
    s = f + e;
    v.insert(s);
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ecoo - emails
    fi(0, 10) {
        int n;
        cin >> n;
        fj(0, n) {
            solve();
        }
        cout << v.size() << endl;
        v.clear();
    }
    
    return 0;
}