#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n = 1000;
    string s;
    int x = 0, d = 0, c;
    for (int i = 0; i < n; i++) {
        cin >> s >> c;
        if (s == "down") d += c;
        if (s == "up") d -= c;
        if (s == "forward") {
            x += c;
        }
    }
    cout << x*d;
}