#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    long long n = 200;
    int answer = 0;
    for (long long i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < 11; j++) {
            cin >> s;
        }
        for (int j = 0; j < 4; ++j) {
            cin >> s;
            if (s.size() == 2 || s.size() == 3 || s.size() == 4 || s.size() == 7) answer++;
        }
    }
    cout << answer;
    
}