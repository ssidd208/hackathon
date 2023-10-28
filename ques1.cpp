#include <iostream>
#include <string>
#include <vector>

using namespace std;

string removeOuterParentheses(string S) {
    string result;
    int opened = 0;

    for (size_t i = 0; i < S.size(); ++i) {
        char c = S[i];
        if (c == '(' && opened++ > 0) {
            result = c + result;
        }
        if (c == ')' && opened-- > 1) {
            result = c + result;
        }
    }

    return result;
}

vector<string> decomposeString(string S) {
    vector<string> decomposedStrings;
    int opened = 0;
    int start = 0;

    for (size_t i = 0; i < S.size(); ++i) {
        if (S[i] == '(') {
            opened++;
        } else {
            opened--;
        }

        if (opened == 0) {
            decomposedStrings.push_back(removeOuterParentheses(S.substr(start, i - start + 1)));
            start = i + 1;
        }
    }

    return decomposedStrings;
}

int main() {
    string input;
    getline(cin, input);

    vector<string> decomposed = decomposeString(input);

    string result;
    for (size_t i = 0; i < decomposed.size(); ++i) {
        result = decomposed[i] + result;
    }

    cout << result << endl;

    return 0;
}
