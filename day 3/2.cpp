#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n = 1000;
    int k = 12;
    vector<string> g, eps;
    int pow2 = 1;
    string input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    for (int i = 0; i < n; i++) {
        g.push_back(input[i]);
        eps.push_back(input[i]);
    }
    for (int i = 0; i < k && g.size() > 1; i++) {
        int k0 = 0, k1 = 0;
        for (int j = 0; j < g.size(); j++) {
            (g[j][i] == '0')? k0++ : k1++;
        }
        char biggerbit = (k0 > k1)? '0' : '1';
        vector<string> newg, neweps;
        for (int j = 0; j < g.size(); j++) {
            if (g[j][i] == biggerbit) newg.push_back(g[j]);
        }
        g = newg;
    }
    for (int i = 0; i < 12 && eps.size() > 1; i++) {
        int k0 = 0, k1 = 0;
        for (int j = 0; j < eps.size(); j++) {
            (eps[j][i] == '0')? k0++ : k1++;
        }
        char biggerbit = (k0 > k1)? '0' : '1';
        vector<string> neweps;
        
        for (int j = 0; j < eps.size(); j++) {
            if (eps[j][i] != biggerbit) neweps.push_back(eps[j]);
        }
        eps = neweps;
    }
    long long ans1 = 0, ans2 = 0;
    for (int i = k-1; i > -1; i--) {
        ans1 += (g[0][i] - '0') *pow2;
        ans2 += (eps[0][i] - '0') *pow2;
        pow2 *= 2;
    }
    cout << ans1 * ans2;
}