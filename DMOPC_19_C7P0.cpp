#include <bits/stdc++.h>
#include <algorithm> 
#include <array>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <math.h>

using namespace std;

int main() {
    cin.tie(0), cout.tie(0);
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    // cout << a + b << " " << (a+b+c+d)/4 << " " << (a + b + d) / 3 << endl;
    printf("%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n", (a+b)/2, (a+c)/2, (a+d)/2, (b+c)/2, (b+d)/2, (c+d)/2, (a+c+b)/3, (a+b+d)/3, (a+c+d)/3, (b+c+d)/3,(a+b+c+d)/4);
    return 0;
}