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
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int i = 0; i < r; i++){for(int j = 0; j < c; j++){cout<<grid[i][j]<<" ";}cout<<endl;}
#define pi 2 * asin(1.0)
#define elif else if 
#define pii pair<int, int>


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
int main() {
    int l[3], w[3], t = 0;
    fi(0, 3) {
        cin >> l[i] >> w[i];
        t += l[i] * w[i];
    }
    if ((int) sqrt(t) * (int) sqrt(t) != t) {
        cout << "NO" << endl;
        exit(0);
    }
    int index;
    fi(0, 3) {
        if (l[i] == sqrt(t)) {
            index = i;
            break;
        } else if (w[i] == sqrt(t)) {
            index = i;
            break;
        }
    }
    fi(0, 3) {
        if (i == index) {
            continue;
        }
        fj(0, 3) {
            if (j == index || j == i) continue;
            // cout << l[i] << " " << w[i] << " " << l[j] << " " << w[j] << endl;
            if (l[i] == l[j]) {
                if (w[i] + w[j] == w[index]) cout << "YES" << endl, exit(0);
            } else if (w[i] == w[j]) {
                if (l[i] + l[j] == w[index]) cout << "YES" << endl, exit(0);    
            } else if (w[i] == l[j]) {
                if (l[i] + w[j] == w[index]) cout << "YES" << endl, exit(0);
            } else if (w[j] == l[i]) {
                if (w[i] + l[j] == w[index]) cout << "YES" << endl, exit(0);
            }

            if (l[i] + l[j] == l[index] && w[i] + w[j] ==  2 * abs(w[index] - l[index])) {
                cout << "YES" << endl;
                exit(0);
            } else if (w[i] + l[j] == l[index] && l[i] + w[j] ==  2 * abs(w[index] - l[index])) {
                cout << "YES" << endl;
                exit(0);
            } else if (w[j] + l[i] == l[index] && l[j] + w[i] ==  2 * abs(w[index] - l[index])) {
                cout << "YES" << endl;
                exit(0);
            } else if (w[i] + w[j] == l[index] && l[i] + l[j] ==  2 * abs(w[index] - l[index])) {
                cout << "YES" << endl;
                exit(0);
            }
            break;
        }
        break;
    }
    cout << "NO" << endl;
    return 0;
}