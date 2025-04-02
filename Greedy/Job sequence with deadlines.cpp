#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int dmax = 0;
    for (auto job : jobs)
        dmax = max(dmax, job.deadline);

    vector<int> schedule(dmax + 1, -1);
    int total_profit = 0;

    for (int i = 0; i < jobs.size(); i++) {
        int k = min(dmax, jobs[i].deadline);
        
        while (k >= 1) {
            if (schedule[k] == -1) {
                schedule[k] = jobs[i].id;
                total_profit += jobs[i].profit;
                break;
            }
            k--;
        }
    }

    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= dmax; i++) {
        if (schedule[i] != -1)
            cout << schedule[i] << " ";
    }
    cout << "\nTotal Profit: " << total_profit << endl;
}

int main() {
    vector<Job> jobs = {
        {1, 2, 100}, {2, 1, 50}, {3, 2, 10}, {4, 1, 20}, {5, 3, 30}
    };
    
    jobSequencing(jobs);
    return 0;
}
