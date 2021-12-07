#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    long long n = 1000;
    long long maxPosition = 2500;
    long long input[n];
    for (long long i = 0; i < n; i++) cin >> input[i];
    long long minimum = INT64_MAX;
    for (long long currentPosition = 0;  currentPosition < maxPosition; currentPosition++) {
        long long currentAnswer = 0;
        for (long long i = 0; i < n; i++) {
            long long x = abs(input[i] - currentPosition);
            currentAnswer += x;
        }
        minimum = min(minimum, currentAnswer);
    }
    cout << minimum;
}