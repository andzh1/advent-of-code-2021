#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n = 2000;
    int x;
    int input[n];
    int ans = 0;
    int cursum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        input[i] = x;
    }
    for (int i = 0; i < 3; ++i) cursum += input[i];
    for (int i = 3; i < n; ++i) {
        int newsum = cursum + input[i] - input[i-3];
        if (newsum > cursum) ans++;
        cursum = newsum;
    }
    cout << ans;

}
