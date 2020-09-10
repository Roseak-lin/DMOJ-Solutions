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
#define elif else if 
#define pii pair<int, int>
#define pq priority_queue 

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

int arr[1000];
/////////////////////////////////////////////////////////////////////////////////////////
int main() {
    cout.tie(0);cin.tie(0);
    int n;
    sc(n);
    int minN = INT_MAX, maxN = INT_MIN, i1, i2;
    fi(0, n) {
        sc(arr[i]);
        if (arr[i] < minN) {
            minN = arr[i];
            i1 = i;
        }
        if (arr[i] > maxN) {
            maxN = arr[i];
            i2 = i;
        }
    }
    bool flag = true;
    if (i1 < i2) {
        fi(i1 + 1, i2 + 1) {
            if (arr[i] <= arr[i - 1]) {
                flag = false;
                break;
            }
        }
    } else {
        fi(i2 + 1, i1 + 1) {
            if (arr[i] <= arr[i - 1]) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        printf("%d\n", arr[i2] - arr[i1]);
    } else {
        printf("unknown\n");
    }

    return 0;
}