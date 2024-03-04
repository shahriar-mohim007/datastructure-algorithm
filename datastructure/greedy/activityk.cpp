#include<bits/stdc++.h>
using namespace std;
struct Activity {
    int start;
    int finish;
    int persons;
};

bool compareActivities(const Activity& a, const Activity& b) {
    return (a.finish < b.finish);
}

void printMaxActivities(vector<Activity>& activities, int k) {
   vector<Activity> sortedActivities = activities;
    sort(sortedActivities.begin(), sortedActivities.end(), compareActivities);
    vector<Activity> selectedActivities;

    for (auto& activity : sortedActivities) {
        if (activity.persons <= k) {
         
            if (selectedActivities.empty() || activity.start >= selectedActivities.back().finish) {
                selectedActivities.push_back(activity);
            }
        }
    }

    cout << "Selected activities:\n";
    for (const auto& activity : selectedActivities) {
      cout << "(" << activity.start << ", " << activity.finish << ", Persons: " << activity.persons << ") ";
    }
}

int main() {
    
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    
    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
       cout << "Enter start, finish, and persons for activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].finish >> activities[i].persons;
    }

    int k;
    cout << "Enter the maximum number of persons allowed (K): ";
    cin >> k;
    printMaxActivities(activities, k);
    return 0;
}
