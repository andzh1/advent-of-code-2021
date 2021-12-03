#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n = 1000;
    int k = 12;
    int g [k], eps [k];
    int pow2 = 1;
    string input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    for (int i = 0; i < 12; i++) {
        int k0 = 0, k1 = 0;
        for (int j = 0; j < n; j++) {
            (input[j][i] == '0')? k0++ : k1++;
        }
        (k0 > k1)? g[i] = 0 : g[i] = 1;
        (k0 > k1)? eps[i] = 1 : eps[i] = 0;
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 11; i > -1; i--) {
        ans1 += g[i]*pow2;
        ans2 += eps[i]*pow2;
        pow2 *= 2;
    }
    cout << ans1 * ans2;
}