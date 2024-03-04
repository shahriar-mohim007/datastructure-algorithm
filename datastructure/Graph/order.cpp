#include<bits/stdc++.h>
using namespace std;

void generateOrderings(vector<char>& variables, vector<pair<char, char>>& constraints, vector<char>& currentOrdering, vector<bool>& used, vector<string>& result) {
    if (currentOrdering.size() == variables.size()) {
        result.push_back(string(currentOrdering.begin(), currentOrdering.end()));
        return;
    }

    for (char var : variables) {
        if (!used[var - 'a']) {
            bool valid = true;

            for (auto constraint : constraints) {
                if (constraint.second == var && !used[constraint.first - 'a']) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                used[var - 'a'] = true;
                currentOrdering.push_back(var);
                generateOrderings(variables, constraints, currentOrdering, used, result);
                currentOrdering.pop_back();
                used[var - 'a'] = false;
            }
        }
    }
}

int main() {
    while (true) {
        vector<char> variables;
        vector<pair<char, char>> constraints;
        string variableLine, constraintLine;

        if (!getline(cin, variableLine)) break;

        getline(cin, constraintLine);

        for (char c : variableLine) {
            if (isalpha(c)) {
                variables.push_back(c);
            }
        }

        sort(variables.begin(), variables.end());

        for (int i = 0; i < constraintLine.size(); i += 4) {
            constraints.push_back({constraintLine[i], constraintLine[i + 2]});
        }

        vector<char> currentOrdering;
        vector<bool> used(26, false);
        vector<string> result;

        generateOrderings(variables, constraints, currentOrdering, used, result);

        sort(result.begin(), result.end());

        for (const string& ordering : result) {
            cout << ordering << endl;
        }

        cout << endl;
    }

    return 0;
}
