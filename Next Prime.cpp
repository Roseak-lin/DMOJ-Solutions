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
#pragma warn -rvl

#define f(x, y) for(int i = y; i < x; i++)
#define ll long long
#define sc(n) scanf("%d", &n);

using namespace std;

int main() {
    cin.tie(0);
    int n;
    sc(n);
    if (n == 1) {
        cout << 2 << endl;
        exit(0);
    }
    int t = n;
    bool f = false;
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            f = true;
            break;
        }
    }
    if (!f) {
        cout << n << endl;
        exit(0);
    }
    for (int i = n + 1; i < INFINITY; i++) {
        int temp = i;
        bool flag = false;
        for (int j = 2; j <= sqrt(temp); j++) {
            if (i % j == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << i << endl;
            exit(0);
        }
    }

    return 0;
}