#include<bits/stdc++.h>
using namespace std;
struct Activity {
    int start;
    int finish;
};

bool compareActivities(const Activity& a, const Activity& b) {
    return (a.finish < b.finish);
}

void printMaxActivities(vector<Activity>& activities) {
   
    vector<Activity> sortedActivities = activities;
    sort(sortedActivities.begin(), sortedActivities.end(), compareActivities);

    
    cout << "Selected activities:\n";
    int i = 0;
    cout << "(" << sortedActivities[i].start << ", " << sortedActivities[i].finish << ") ";

    for (int j = 1; j < sortedActivities.size(); j++) {
        if (sortedActivities[j].start >= sortedActivities[i].finish) {
            cout << "(" << sortedActivities[j].start << ", " << sortedActivities[j].finish << ") ";
            i = j;
        }
    }
}

int main() {
    
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter start time and finish time for activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }

    printMaxActivities(activities);

    return 0;
}
