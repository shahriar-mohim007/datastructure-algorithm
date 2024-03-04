#include<bits/stdc++.h>
using namespace std;

struct Job {
    int deadline; 
    int profit;
};

bool compareJobs(const Job& a, const Job& b) {
    return (a.profit > b.profit); 
}

void printJobSequence(vector<Job>& jobs) {
   
    vector<Job> sortedJobs = jobs;
    sort(sortedJobs.begin(), sortedJobs.end(), compareJobs);

    int maxDeadline = 0;
    for (const auto& job : sortedJobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<int> sequence(maxDeadline, -1);

    int totalProfit = 0;
    for (const auto& job : sortedJobs) {
        for (int i = job.deadline - 1; i >= 0; --i) {
            if (sequence[i] == -1) {
                sequence[i] = job.profit;
                totalProfit += job.profit;
                break;
            }
        }
    }

    
    cout << "Job Sequence: ";
    for (const auto& profit : sequence) {
        if (profit != -1)
            cout << profit << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << "\n";
}

int main() {
    
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    
    vector<Job> jobs;
    for (int i = 0; i < n; i++) {
        cout << "Enter deadline and profit for job " << i + 1 << ": ";
        int deadline, profit;
        cin >> deadline >> profit;
        jobs.push_back({deadline, profit});
    }

    printJobSequence(jobs);

    return 0;
}
