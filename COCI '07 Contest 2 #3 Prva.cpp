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

typedef long long ll;

template <typename T> void sc(T &number) { bool negative = false; register int c; number = 0;  c = getchar(); if (c=='-') { negative = true;  c = getchar(); } for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48; if (negative) number *= -1; }

#define fi(x, y) for(int i = x; i < y; i++)
#define fj(x, y) for(int j = x; j < y; j++)
#define mp make_pair
#define MOD 1000000007
#define endl "\n"
#define print2dArr(a,r,c) cout << #a << ":\n"; for(int i = 0; i < r; i++) { for(int j = 0; j < c; j++) { cout << a[i][j] << " "; } cout << endl;}
#define pi 2 * asin(1.0)
#define elif else if
#define pii pair<int, int>
#define pq priority_queue
#define tie cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

using namespace std;

struct point
{
    int x, y;
    point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////
char arr[20][20];
vector<string> v;
int main() {
    int r, c;
    sc(r);sc(c);
    queue<pii> q;
    set<string> s;
    fi(0, r) {
        fj(0, c) {
            cin >> arr[i][j];
            if (i == 0 || j == 0 && arr[i][j] != '#') {
                q.push(mp(i, j));
            } elif (arr[i - 1][j] == '#' || arr[i][j - 1] == '#' && arr[i][j] != '#') {
                q.push(mp(i, j));
            }
        }
    }
    while (!q.empty()) {
        pii i = q.front();
        q.pop();
        if (i.first == 0 || i.second == 0) {
            if (i.first == 0) {
                int y = 0;
                string temp = "";
                while (arr[y][i.second] != '#' && y < r) {
                    temp += arr[y][i.second];
                    y++;
                }
                if (temp.length() >= 2) s.insert(temp);
            }
            if (i.second == 0) {
                int x = 0;
                string temp = "";
                while (arr[i.first][x] != '#' && x < c) {
                    temp += arr[i.first][x];
                    x++;
                }
                if (temp.length() >= 2) s.insert(temp);
            }
        } else {
            if (arr[i.first - 1][i.second] == '#') {
                int y = i.first;
                string temp = "";
                while (arr[y][i.second] != '#' && y < r) {
                    temp += arr[y][i.second];
                    y++;
                }
                if (temp.length() >= 2) s.insert(temp);
            }
            if (arr[i.first][i.second - 1] == '#') {
                int x = i.second;
                string temp = "";
                while (arr[i.first][x] != '#' && x < c) {
                    temp += arr[i.first][x];
                    x++;
                }
                if (temp.length() >= 2) s.insert(temp);
            }
        }
    }

    for (string st : s) {
        cout << st << endl;
        break;
    }

    return 0;
}