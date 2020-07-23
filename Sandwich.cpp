#include <iostream>
#include <string>

using namespace std;

int main()
{
    int l;
    scanf("%i", &l);
    char s[l];
    scanf("%s", s);
    
    for (int i = l; i >= 0; i--) {
        if (s[i] == '1') {
            cout << i + 1 << endl;
        }
    }
    for (int i = 0; i < l; i++) {
        if (s[i] == '0') {
            cout << i + 1<< endl;
        }
    }
}