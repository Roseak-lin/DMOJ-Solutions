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

using namespace std;

int main() {
    ll n, m, k;
    scanf("%lld", &n);
    scanf("%lld", &m);
    scanf("%lld", &k);
    if (k == 0) {
        cout << 0 << endl;
        exit(0);
    }
    ll arr[n + 1];
    arr[0] = 0;
    ll diff[n + 2] = {0};
    diff[1] = m;
    fi(0, m) {
        int a, b;
        sc(a);sc(b);
        diff[a]--;
        diff[b + 1]++;
    }
    ll temp = 0;
    fi(1, n + 1) {
        arr[i] = diff[i] + arr[i - 1];
        temp += arr[i];
    }
    if (temp < k) {
        cout << "-1" << endl;
        exit(0);
    }
    // fi(1, n + 1) {
    //     cout << arr[i] << " ";
    // }
    int mini = INT_MAX, p1 = 1, p2 = 1;
    ll sum = arr[p1];
    while (p1 <= n) {
        while (sum < k && p2 < n) {
            sum += arr[p2 + 1];
            p2++;
        }
        // cout << p2 << " " << p1 << " " << sum << " " << p2 - p1 + 1 << endl;
        if (sum < k) {
            break;
        }
        mini = min(mini, p2 - p1 + 1);
        sum -= arr[p1];
        p1++;
    }
    printf("%d", mini != INT_MAX? mini : -1);
    return 0;
}