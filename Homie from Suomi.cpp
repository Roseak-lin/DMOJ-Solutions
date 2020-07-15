#include <bits/stdc++.h>
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <deque>

#pragma GCC optimize("Ofast")

typedef long long ll;

#define fi(x, y) for(int i = x; i < y; i++)
#define fj(x, y) for(int j = x; j < y; j++)
#define sc(n) scanf("%d", &n);

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    sc(n);sc(m);
    int spare = 0;
    int move = 0;
    fi(0,n) {
        int num;
        sc(num);
        if (spare < 0) {
            printf("-1\n");
            exit(0);
        }
        if (num - m < 0) {
            spare -= m - num;
            move += m - num;
        } else {
            spare += num - m;
        }
    }
    
    printf("%d\n", move);
    return 0;
}