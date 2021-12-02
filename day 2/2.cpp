#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n = 1000;
    string s;
    long long x = 0, d = 0, c, aim = 0;
    for (int i = 0; i < n; i++) {
        cin >> s >> c;
        if (s == "down") aim+=c;
        if (s == "up") aim-=c;
        if (s == "forward") {
            x += c;
            d += c*aim;
        }
    }
    cout << x*d;
}