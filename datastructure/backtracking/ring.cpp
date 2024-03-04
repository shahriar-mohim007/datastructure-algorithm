#include<bits/stdc++.h>
using namespace std;
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

bool isValid(vector<int>& arrangement) {
    for (int i = 0; i < arrangement.size(); ++i) {
        if (!isPrime(arrangement[i] + arrangement[(i + 1) % arrangement.size()])) {
            return false;
        }
    }
    return true;
}

void generateRing(int n, vector<int>& arrangement, int& caseNumber) {
    
        
    if (arrangement.size() == n && isValid(arrangement)) {
        cout << "Case " << caseNumber << ":\n";
        for (int num : arrangement) {
            cout << num << " ";
        }
        cout << "\n";
        caseNumber++;
        return;
    }

    for (int i = 2; i <= n; ++i) {
        if (find(arrangement.begin(), arrangement.end(), i) == arrangement.end()) {
            arrangement.push_back(i);
            if (isValid(arrangement)) {
                generateRing(n, arrangement, caseNumber);
            }
            arrangement.pop_back();
        }
    }
}

int main() {
    int n;
    int caseNumber = 1;

    while (cin >> n) {
        cout<<n<<endl;
        vector<int> arrangement = {1}; 
        generateRing(n, arrangement, caseNumber);
    }

    return 0;
}
