#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    long long n = 100;
    long long strlen = 100;
    long long answer = 0;
    string input[n];
    for (int i = 0; i < n; ++i) cin >> input[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < strlen; ++j) {
            if ((i == 0 || input[i][j] < input[i-1][j]) && 
            (j == 0 || input[i][j] < input[i][j - 1]) && 
            (j == strlen-1 || input[i][j] < input[i][j + 1]) && 
            (i == strlen-1 || input[i][j] < input[i + 1][j])) {
                answer += 1 + input[i][j] - '0';
            }
        }
    }

    cout << answer;
    
    
}