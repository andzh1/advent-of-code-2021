#include <bits/stdc++.h>

using namespace std;

bool match (char c1, char c2) {
    return abs(c1 - c2) <= 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    long long n = 106;
    vector<long long> ansv;
    for (int i= 0; i < n; ++i) {
        long long answer = 0;
        stack<char> input;
        string s;
        cin >> s;
        int ip = 1;
        input.push(s[0]);
        bool isCorrect = true;
        while(isCorrect && ip < s.length()) {
            if (s[ip] == '{' || s[ip] == '(' ||s[ip] == '[' ||s[ip] == '<') {
                input.push(s[ip]);
                ++ip;
            } else {
                if (match(s[ip], input.top())) {
                    input.pop();
                    ++ip;
                } else {
                    isCorrect = false;
                }
            }
        }
        if (isCorrect) {
            while(!input.empty()) {
                char ch = input.top();
                input.pop();
                answer *= 5;
                if (ch == '{') answer += 3;
                if (ch == '(') answer += 1;
                if (ch == '[') answer += 2;
                if (ch == '<') answer += 4;
               
            }
        }
        if (isCorrect) ansv.push_back(answer);
    }
    sort(ansv.rbegin(), ansv.rend());
    cout << (ansv[ansv.size() / 2]);
}