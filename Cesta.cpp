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

typedef long long ll;

#define fi(x, y) for(int i = x; i < y; i++)
#define fj(x, y) for(int j = x; j < y; j++)
#define sc(n) scanf("%d", &n);

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    string n;
    cin >> n;
    // sort(n.begin(), n.end());
    int temp = 0;
    bool flag = false;
    for (int i = 0; i < n.size(); i++) {
      temp += n[i] - 48;
      if (n[i] - 48 == 0) {
        flag = true;
      }
    }
    // cout << temp << endl;
    if (temp % 3 == 0 && flag) {
      sort(n.begin(), n.end());
      reverse(n.begin(), n.end());
      cout << n << endl;
    } else {
      printf("-1\n");
    }
    return 0;
}