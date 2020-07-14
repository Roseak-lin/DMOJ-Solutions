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

/////////////////////////////////////////////////////////////////////////////////////////
int sum(string s) {
    int sum = 0;
    fi(0, s.length()) {
        sum += (int) s[i] - 48;
    }
    return sum;
}
int main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    int q;
    cin >> q;
    fi(0, q) {
        ll n, m;
        cin >> n >> m;
        string s = to_string(m);
        if (m < 10) {
            cout << m << endl;
            continue;
        } else if (n == m) {
            cout << m << endl;
            continue;
        } else if (m == 10) {
            cout << "9" << endl;
        } else {
            string num = "";
            fi(0, s.length()) {
                num += "9";
            }
            int p = 0;
            bool flag = false;
            while (stoll(num) > m) {
                num[p]--;
                if (stoll(num) < n) {
                    p++;
                    num[p - 1]++;
                    flag = true;
                    continue;
                }
                if ((int) num[0] == 48) {
                    num.erase(0, 1);
                    break;
                }
            }
            cout << sum(num) << endl;
        }

    }
    return 0;
}