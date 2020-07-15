#include <bits/stdc++.h>
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <deque>
#include <cmath>

#pragma GCC optimize("Ofast")

typedef long long ll;

#define fi(x, y) for(int i = x; i < y; i++)
#define fj(x, y) for(int j = x; j < y; j++)
#define sc(n) scanf("%d", &n);
#define mp make_pair

using namespace std;

bool prime(int n) {
    int t = sqrt(n);
    fi(2,t + 1) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    int n, d;
    sc(n);sc(d);
    int arr[n];
    fi(0,n) {
        sc(arr[i]);
    }
    int m = INT_MAX;
    if (d < 0) {
        
        fi(0,n) {
            int temp = 0;
            int dist = 0;
            while (dist > d) {
                dist -= arr[i];
                temp++;
            }
            // cout << dist << endl;
            if (dist == d) {
                m = min(temp, m);
            }
        }
    } else {
        fi(0,n) {
            int temp = 0;
            int dist = 0;
            while (dist < d) {
                dist += arr[i];
                temp++;
            }
            if (dist == d) {
                m = min(temp, m);
            }
        }
    }

    if (m == INT_MAX) {
        printf("This is not the best time for a trip.");
    } else {
        printf("%d", m);
    }
    return 0;
}