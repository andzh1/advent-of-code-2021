#include <bits/stdc++.h>

using namespace std;

set<char> cross(set<char> first, set<char> second) {
    set<char> answer;
    for (auto f: first) {
        if (second.find(f) != second.end()) answer.insert(f);
    }
    return answer;
}

set<char> merge(set<char> first, set<char> second) {
    set<char> answer;
    for (auto f: first) {
        answer.insert(f);
    }
    for (auto f: second) {
        answer.insert(f);
    }
    return answer;
}

int differ (set<char> first, set<char> second) {
    return first.size() - cross(first, second).size();
}

bool equal (set<char> first, set<char> second) {
    return first == merge(first, second) && first.size() == second.size();
}

int main() {
    freopen("input.txt", "r", stdin);
    long long n = 200;
    long long answer = 0;
    for (long long i = 0; i < n; i++) {
        string s;
        string input[10], value[4];
        for (int j = 0; j < 10; j++) {
            cin >> input[j];
        }
        cin >> s;
        for (int j = 0; j < 4; ++j) {
            cin >> value[j];
        }
        int ansDigits[4];
        std::set<char> digits[10];
        for (int j = 0; j < 10; ++j) {
            int x = -1;
            if (input[j].size() == 2) x = 1;
            if (input[j].size() == 3) x = 7;
            if (input[j].size() == 4) x = 4;
            if (input[j].size() == 7) x = 8;
            if (x > 0) for (int k = 0; k < input[j].size(); ++k) digits[x].insert(input[j][k]);
        }
        std::set<char> codedAns[4];
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < value[j].size(); ++k) codedAns[j].insert(value[j][k]);
        }
        set<char> inputSets[10];
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < input[j].size(); ++k) inputSets[j].insert(input[j][k]);
        }

        for (int j = 0; j < 10; ++j) {
            if (inputSets[j].size() == 5 && merge(inputSets[j], digits[4]).size() == 7) {
                digits[2] = merge(digits[2], inputSets[j]);
                break;
            } 
        }
        for (int j = 0; j < 10; ++j) {
            if (inputSets[j].size() == 5 && merge(inputSets[j], digits[2]).size() == 7) {
                digits[5] = merge(digits[5], inputSets[j]);
                break;
            } 
        }
        for (int j = 0; j < 10; ++j) {
            if (inputSets[j].size() == 5 && !equal(inputSets[j], digits[2]) && !equal(inputSets[j], digits[5])) {
                digits[3] = merge(digits[3], inputSets[j]);
                break;
            } 
        }
        for (int j = 0; j < 10; ++j) {
            if (inputSets[j].size() == 6) {
                int x = 0;
                if (merge(digits[2], inputSets[j]).size() == 7) x++; 
                if (merge(digits[3], inputSets[j]).size() == 7) x++; 
                if (merge(digits[5], inputSets[j]).size() == 7) x++; 
                if (x == 3) digits[0] = merge(digits[0], inputSets[j]);
                if (x == 2) digits[6] = merge(digits[6], inputSets[j]);
                if (x == 1) digits[9] = merge(digits[9], inputSets[j]);
            }
        }
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 10; ++k) {
                if (equal(codedAns[j], digits[k])) {
                    ansDigits[j] = k;
                    break;
                }
            }
        }
        int currentAns = 0;
        currentAns += ansDigits[0] * 1000;
        currentAns += ansDigits[1] * 100;
        currentAns += ansDigits[2] * 10;
        currentAns += ansDigits[3];
        answer += currentAns;
    }
    cout << answer;
    
}