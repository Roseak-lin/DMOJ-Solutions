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

#define f(x, y) for(int i = y; i < x; i++)
#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
	int activities;
	cin >> activities;
	int v[activities][3];
	f (activities, 0) {
		int a,b,c;
		cin >> a >> b >> c;
		v[i][0] = a;
		v[i][1] = b;
		v[i][2] = c;
	}
	int dp[activities][3];
	dp[0][0] = v[0][0];
	dp[0][1] = v[0][1];
	dp[0][2] = v[0][2];
	f (activities, 1) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				dp[i][j] = max(dp[i - 1][1] + v[i][j], dp[i - 1][2] + v[i][j]);
			} else if (j == 1) {
				dp[i][j] = max(dp[i - 1][0] + v[i][j], dp[i - 1][2] + v[i][j]);
			} else {
				dp[i][j] = max(dp[i - 1][1] + v[i][j], dp[i - 1][0] + v[i][j]);
			}
		}
	}
	// cout << endl;
	// f (activities, 0) {
	// 	for (int j = 0; j < 3; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << max(dp[activities - 1][0], max(dp[activities - 1][1], dp[activities - 1][2])) << endl;
	return 0;
}