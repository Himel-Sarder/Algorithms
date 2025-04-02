Here's a line-by-line explanation of the Job Sequencing algorithm code with step-by-step examples:

---

### **1. Header Files and Namespace**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
```
- **`#include <iostream>`**: Enables input/output operations.
- **`#include <vector>`**: Provides the `vector` container for dynamic arrays.
- **`#include <algorithm>`**: Includes sorting functions.
- **`using namespace std`**: Avoids prefixing standard library components with `std::`.

---

### **2. Job Structure**
```cpp
struct Job {
    int id, deadline, profit;
};
```
Defines a job with three properties:
- **`id`**: Unique identifier (e.g., 1, 2, 3).
- **`deadline`**: Time by which the job must complete (e.g., 2 days).
- **`profit`**: Reward for completing the job (e.g., $100).

---

### **3. Comparison Function**
```cpp
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}
```
- Sorts jobs in **descending order of profit** (greedy strategy).
- Example: For two jobs `{id:1, profit:100}` and `{id:2, profit:50}`, job 1 comes first.

---

### **4. Job Sequencing Function**
```cpp
void jobSequencing(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);
```
- **Sorts jobs** by descending profit.
- Example Input (unsorted):
  ```cpp
  [{1,2,100}, {2,1,50}, {3,2,10}, {4,1,20}, {5,3,30}]
  ```
- After sorting:
  ```cpp
  [{1,2,100}, {2,1,50}, {5,3,30}, {4,1,20}, {3,2,10}]
  ```

---

### **5. Find Maximum Deadline**
```cpp
    int dmax = 0;
    for (auto job : jobs)
        dmax = max(dmax, job.deadline);
```
- Determines the latest deadline among all jobs.
- Example: Jobs have deadlines `2, 1, 3, 1, 2` → `dmax = 3`.

---

### **6. Schedule Initialization**
```cpp
    vector<int> schedule(dmax + 1, -1);
    int total_profit = 0;
```
- **`schedule`**: Array of size `dmax + 1` (indexes 0–3 for `dmax=3`).
  - Slots `1` to `dmax` represent time units (days).
  - Initialized to `-1` (empty slots).
- **`total_profit`**: Accumulates the total profit from scheduled jobs.

---

### **7. Schedule Jobs Greedily**
```cpp
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
```
- **Process each job** in descending order of profit.
- **For Job 1** (deadline 2, profit 100):
  - `k = min(3, 2) = 2`
  - Slot 2 is empty → schedule[2] = 1, profit += 100.
- **For Job 2** (deadline 1, profit 50):
  - `k = 1` → slot 1 is empty → schedule[1] = 2, profit += 50.
- **For Job 5** (deadline 3, profit 30):
  - `k = 3` → slot 3 is empty → schedule[3] = 5, profit += 30.
- **Jobs 4 and 3** (profit 20 and 10):
  - No slots left → not scheduled.

---

### **8. Output Results**
```cpp
    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= dmax; i++) {
        if (schedule[i] != -1)
            cout << schedule[i] << " ";
    }
    cout << "\nTotal Profit: " << total_profit << endl;
}
```
- **Prints scheduled jobs** in order of their slots (1 → 2 → 3).
- Example Output:
  ```
  Scheduled Jobs: 2 1 5 
  Total Profit: 180
  ```

---

### **9. Main Function**
```cpp
int main() {
    vector<Job> jobs = {
        {1, 2, 100}, {2, 1, 50}, {3, 2, 10}, {4, 1, 20}, {5, 3, 30}
    };
    jobSequencing(jobs);
    return 0;
}
```
- Defines the job list and calls the sequencing function.
- Final Output:
  ```
  Scheduled Jobs: 2 1 5 
  Total Profit: 180
  ```

---

### **Key Points**
1. **Greedy Strategy**: Always picks the highest-profit job first.
2. **Slot Allocation**: Places each job in the latest available slot before its deadline.
3. **Time Complexity**: 
   - Sorting: \(O(n \log n)\)
   - Scheduling: \(O(n \cdot d)\), where \(d\) is the maximum deadline.
4. **Space Complexity**: \(O(d)\) for the schedule array.
