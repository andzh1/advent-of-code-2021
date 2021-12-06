#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n = 300;
    int maxCycleLen = 7;
    int realCycleLen = maxCycleLen + 2;
    int numberOfFish[realCycleLen];
    for (int i = 0; i < realCycleLen; i++) numberOfFish[i] = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numberOfFish[x]++;
    }
    int numberOfDays = 80;
    for (int i = 0; i < numberOfDays; i++) {
        int reproduce = numberOfFish[0];
        numberOfFish[0] = 0;
        for (int j = 1; j < realCycleLen; j++) {
            numberOfFish[j - 1] = numberOfFish[j];
        }
        numberOfFish[realCycleLen - 1] = reproduce;
        numberOfFish[realCycleLen - 3] += reproduce;
    }
    long long ans = 0;
    for (int j = 0; j < realCycleLen; j++) {
        ans += numberOfFish[j];
    }
    cout << ans;
}