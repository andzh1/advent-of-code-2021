#include <bits/stdc++.h>

using namespace std;

const auto n = 10;

void incrementAll(int input[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            input[i][j]++;
        }   
    }
}

void setAll(bool arr[n][n], bool value){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = false;
        }   
    }
}

bool forall(bool arr[n][n]) {
    bool all = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            all = arr[i][j] && all;
            if (!all) break;
        }   
    }
    return all;
}

bool exists(bool arr[n][n]) {
    bool all = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            all = arr[i][j] || all;
            if (all) break;
        }   
    }
    return all;
}
int count(bool arr[n][n]) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(arr[i][j]) cnt += 1;
        }   
    }
    return cnt;
}
// 
int invalidFlashForward(int input[n][n]) {
    bool flashed[n][n];
    setAll(flashed, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(input[i][j] > 9) {
                flashed[i][j] = true;
                input[i][j] = INT32_MIN;
                for (int k = -1; k <= 1; k++)
                    for (int l = -1; l <= 1; l++)
                    if(k != 0 || l != 0) {
                        auto ii = i + k;
                        auto jj = j + l;
                        if (ii >= 0 && ii < n && jj >= 0 && jj < n)
                        input[ii][jj] ++;
                    }
                // if (i > 0                  ) input[i - 1][j    ]++;
                // if (i > 0     && j > 0     ) input[i - 1][j - 1]++;
                // if (             j > 0     ) input[i    ][j - 1]++;
                // if (i < n - 1 && j > 0     ) input[i + 1][j - 1]++;
                // if (i < n - 1              ) input[i + 1][j    ]++;
                // if (i < n - 1 &&  j < n - 1) input[i + 1][j + 1]++;
                // if (              j < n - 1) input[i    ][j + 1]++;
                // if (i > 0     &&  j < n - 1) input[i - 1][j + 1]++;
            }
        }   
    }
    return count(flashed);
}
bool flash(int input[n][n]) {
    int cnt;
    do {
        
        // if (!exists(flashed)) break;
        cnt = invalidFlashForward(input);
        if (cnt == 100) {
            return true;
        }
        
    } while(cnt > 0);
    return false;
}

void unhighlight(int input[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            input[i][j] = max(0, input[i][j]);
        }   
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int numberOfMoves = 323;
    long long answer = 0;
    int input[n][n];
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            input[i][j] = s[j] - '0';
            // cout << input[i][j];
        }   
        // cout << '\n';
    }
    
    for(int ip = 1; ip <= numberOfMoves; ip+=1) {
        incrementAll(input);
        auto allFlashed = flash(input);
        if(allFlashed){
            cout << ip << '\n'; // I don't know why here should be -10...
            break;
        }
        unhighlight(input);
    }
    // cout << answer;
    
}