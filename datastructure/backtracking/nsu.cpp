#include<bits/stdc++.h>
using namespace std;

void generateCombinations(string& s, int r, int index, string current) 
{
    if (r == 0) {
        cout << current << endl;
        return;
    }

    for (int i = index; i < s.length();i++) {
        generateCombinations(s, r - 1, i + 1, current + s[i]);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        int r;
        cin >> s >> r;

        sort(s.begin(), s.end());  

        generateCombinations(s, r, 0, "");
    }

    return 0;
}
