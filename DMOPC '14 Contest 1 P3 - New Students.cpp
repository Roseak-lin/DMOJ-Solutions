#include <bits/stdc++.h>

using namespace std;

int main() {
    int i, s, students, n;
    double sum;
    scanf("%d", &i);
    students = i;
    while (i--) {
        scanf("%d", &n);
        sum += n;
    }
    scanf("%d", &s);
    while (s--) {
        students++;
        scanf("%d", &n);
        sum += n;
        printf("%.3f\n", sum / students);
    }
    return 0;
}