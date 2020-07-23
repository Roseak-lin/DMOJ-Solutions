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
/////////////////////////////////////////////////////////////////////////////////////////
void sc(int &number) { bool negative = false; register int c; number = 0;  c = getchar(); if (c=='-') { negative = true;  c = getchar(); } for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48; if (negative) number *= -1; } 

queue<pii> q;
bool visited[10000001];
int main() {
    int s, e;
    pii curr;
    sc(s);sc(e);
    if (s == e) {
        printf("0");
        return 0;
    }
    if (s % 2 == 0) {
        q.push(mp(s / 2, 1));
    }
    q.push(mp(s - 3, 1)); 
    q.push(mp(s - 1, 1));
    q.push(mp(3 * s, 1));
    while (!q.empty()) {
        curr = q.front();
        q.pop();
        // cout << curr.first << " " << curr.second << endl;
        if (curr.first <= 0 || curr.first > 10000000 || visited[curr.first]) {
            continue;
        }
        if (curr.first == e) {
            printf("%d\n", curr.second);
            break;
        }
        
        visited[curr.first] = true;
        if (curr.first % 2 == 0) {
            q.push(mp(curr.first / 2, curr.second + 1));
            if (curr.first / 2 == e) {
                printf("%d\n", curr.second + 1);
                break;
            }
        }
        q.push(mp(curr.first - 1, curr.second + 1));
        if (curr.first - 1 == e) {
            printf("%d\n", curr.second + 1);
            break;
        }
        q.push(mp(curr.first - 3, curr.second + 1));
        if (curr.first - 3 == e) {
            printf("%d\n", curr.second + 1);
            break;
        }
        q.push(mp(3 * curr.first, curr.second + 1));
        if (curr.first * 3 == e) {
            printf("%d\n", curr.second + 1);
            break;
        }
    }
    
    return 0;
}