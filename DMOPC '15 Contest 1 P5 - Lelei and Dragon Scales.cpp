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

/////////////////////////////////////////////////////////////////////////////////////////
#define max(a,b) a>b ? a : b

int pre[251][251];
int main() {
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
    int w, h, n;
    cin >> w >> h >> n;
    int maxScale = 0;
    int arr[h + 1][w + 1] = {0};
    fi(1, h + 1) {
        fj(1, w + 1) {
            cin >> arr[i][j];
        }
    }
    int pre[h + 1][w + 1] = {0};
    pre[1][1] = arr[1][1];
    fi(0, w + 1) {
        pre[0][i] = 0;
    }
    fi(2, h + 1) {
        pre[i][1] = pre[i - 1][1] + arr[i][1];
    }
    fi(2, w + 1) {
        pre[1][i] = pre[1][i - 1] + arr[1][i];
    }

    fi(2, h + 1) {
        fj(2, w + 1) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + arr[i][j];
        }
    }
    fi(1, h + 1) {
        fj(1, w + 1) {
            for (int k = 1; k <= i; k++) {
                maxScale = max(maxScale, pre[i][j] - pre[i - k][j] - (j - (n/k) > 0 ? pre[i][j - (n / k)] : 0) + (j - (n/k) > 0 ? pre[i - k][j - (n / k)] : 0));
            }
        }
    }
    cout << maxScale << endl;
    return 0;
}