#include <bits/stdc++.h>

using namespace std;

bool match (char c1, char c2) {
    return abs(c1 - c2) <= 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    long long n = 106;
    long long answer = 0;
    for (int i= 0; i < n; ++i) {
        stack<char> input;
        string s;
        cin >> s;
        int ip = 1;
        input.push(s[0]);
        bool isCorrect = true;
        while(isCorrect) {
            if (s[ip] == '{' || s[ip] == '(' ||s[ip] == '[' ||s[ip] == '<') {
                input.push(s[ip]);
                ++ip;
            } else {
                if (match(s[ip], input.top())) {
                    input.pop();
                    ++ip;
                } else {
                    if (s[ip] == '}') answer += 1197;
                    if (s[ip] == ')') answer += 3;
                    if (s[ip] == ']') answer += 57;
                    if (s[ip] == '>') answer += 25137;
                    isCorrect = false;
                }
            }
        }
    }
    cout << answer;
}