#include <bits/stdc++.h>
#include <algorithm> 
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (arr[j-1] > arr[j]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                for (int x = 0; x < n; x++) {
                    printf("%d ", arr[x]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}