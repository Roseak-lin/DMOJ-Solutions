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

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    set<string> v;
    fi(0,n) {
        string s;
        cin >> s;
        v.insert(s);
    }
    int count = 0;
    fi(0,m) {
        int t;
        sc(t);
        bool flag = true;
        fj(0,t) {   
            string s;
            cin >> s;
            if (!std::count(v.begin(), v.end(), s)) {
                flag = false;
            }
        }
        if (flag == true) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}