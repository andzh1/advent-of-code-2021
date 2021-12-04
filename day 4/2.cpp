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
                bingoCol[5*i + k].insert(curbingo[j][k]);
            }
        }
    }
    set<int> ipset;
    for (int i = 0; i < n; i++) ipset.insert(i);
    for (int ip = 0; ip < k; ip++) {
        for (int i = 0; i < 5*n && ipset.size() > 0; i++) {
            if (ipset.find(i/5) == ipset.end()) continue;
            int lastIP;
            if (ipset.size() == 1) {
                for (auto q: ipset) lastIP = q;
            }
            if (bingoCol[i].find(input[ip]) != bingoCol[i].end()) {
                bingoCol[i].erase(input[ip]);
                if (bingoCol[i].empty()) {
                    if (ipset.find(i/5) != ipset.end()) ipset.erase(i/5);
                }
            }
            if (bingoStr[i].find(input[ip]) != bingoStr[i].end()) {
                bingoStr[i].erase(input[ip]);
                if (bingoStr[i].empty()) {
                    if (ipset.find(i/5) != ipset.end()) ipset.erase(i/5);
                }
            }
            if (ipset.size() == 0) {
                int x = lastIP;
                int answer = 0;
                int ipans = x*5;
                for (int j = ipans; j < ipans + 5; j++) {
                    answer += sum(bingoStr[j]);
                }
                answer *= input[ip];
                cout << answer << '\n';
                break;
            }
        }
    }
}