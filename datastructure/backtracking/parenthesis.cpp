#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(int open, int close, 
string current, vector<string>& result) {
    if (open == 0 && close == 0) {
        result.push_back(current);
        return;
    }

    if (open > 0) {
        generateParenthesis(open - 1, close, current + '(', result);
    }

    if (close > open) {
        generateParenthesis(open, close - 1, current + ')', result);
    }
}

int main() {
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    vector<string> result;
    generateParenthesis(n, n, "", result);

    cout << "All combinations of well-formed parentheses:" << endl;
    for (string& str : result) {
        cout << str << endl;
    }

    return 0;
}
