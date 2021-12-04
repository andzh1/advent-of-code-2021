#include <bits/stdc++.h>

using namespace std;

int sum(set<int> input) {
    int ans = 0;
    for(auto s: input) ans += s;
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n = 100;
    int k = 100;
    int input[k];
    for (int i = 0; i < k; i++) {
        cin >> input[i];
    }
    set<int> bingoStr [5*n];
    set<int> bingoCol [5*n];
    int ans[n];
    for (int i = 0; i < n; i++) {
        int curbingo[5][5];
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> curbingo[j][k];
                ans[i] += curbingo[j][k];
                bingoStr[5*i + j].insert(curbingo[j][k]);
                bingoCol[5+i + k].insert(curbingo[j][k]);
            }
        }
    }
    for (int ip = 0; ip < k; ip++) {
        for (int i = 0; i < 5*n; i++) {
            if (bingoCol[i].find(input[ip]) != bingoCol[i].end()) {
                bingoCol[i].erase(input[ip]);
                if (bingoCol[i].empty()) {
                    int ipans = i/5, answer = 0;
                    for (int j = ipans * 5; j < ipans*5 + 5; j++) {
                        answer += sum(bingoCol[j]);
                    }
                    cout << answer*input[ip] << '\n';
                    break;
                }
            }
            if (bingoStr[i].find(input[ip]) != bingoStr[i].end()) {
                bingoStr[i].erase(input[ip]);
                if (bingoStr[i].empty()) {
                    int ipans = i/5, answer = 0;
                    for (int j = ipans * 5; j < ipans*5 + 5; j++) {
                        answer += sum(bingoStr[j]);
                        
                    }
                    cout << answer*input[ip] << '\n';
                    break;
                }
            }
        }
    }
}