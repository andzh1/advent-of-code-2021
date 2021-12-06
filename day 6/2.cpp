#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    long long n = 300;
    long long maxCycleLen = 7;
    long long realCycleLen = maxCycleLen + 2;
    long long numberOfFish[realCycleLen];
    for (long long i = 0; i < realCycleLen; i++) numberOfFish[i] = 0;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        numberOfFish[x]++;
    }
    long long numberOfDays = 256;
    for (long long i = 0; i < numberOfDays; i++) {
        long long reproduce = numberOfFish[0];
        numberOfFish[0] = 0;
        for (long long j = 1; j < realCycleLen; j++) {
            numberOfFish[j - 1] = numberOfFish[j];
        }
        numberOfFish[realCycleLen - 1] = reproduce;
        numberOfFish[realCycleLen - 3] += reproduce;
    }
    long long ans = 0;
    for (long long j = 0; j < realCycleLen; j++) {
        ans += numberOfFish[j];
    }
    cout << ans;
}