#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    int n = 500;
    int width = 1000;
    int field[width][width];
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            field[i][j] = 0;
        }
    }
    // string input[n];
    for (int i = 0; i < n; i++) {
        string a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        string s1, s2, s3, s4;
        int ip = 0;
        while(a1[ip] != ',') {
            s1.push_back(a1[ip]);
            ip++;
        }
        ip++;
        while(ip < a1.length()) {
            s2.push_back(a1[ip]);
            ip++;
        }
        ip=0;
        while(a3[ip] != ',') {
            s3.push_back(a3[ip]);
            ip++;
        }
        ip++;
        while(ip < a3.length()) {
            s4.push_back(a3[ip]);
            ip++;
        }
        if (!(s1 == s3 || s2 == s4)) continue;
        if (s1 == s3) {
            int x = stoi(s1);
            int y1 = stoi(s2);
            int y2 = stoi(s4);
            for (int i = min(y1, y2); i <= max(y1, y2); i++) field[x][i]++;
        } else {
            int x1 = stoi(s1);
            int y1 = stoi(s2);
            int x2 = stoi(s3);
            for (int i = min(x1, x2); i <= max(x1, x2); i++) field[i][y1]++;
        }

    }
    int ans = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            ans += (field[i][j] >= 2);
        }
    }
    cout << ans;

}