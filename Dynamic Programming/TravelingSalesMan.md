Let’s go through your **brute-force TSP implementation** line by line, using a 4-city example:

---

## ✅ **Code Explanation (Line-by-Line)**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
```
- **Includes necessary headers**:
  - `iostream`: For input/output
  - `vector`: For dynamic arrays
  - `algorithm`: For `next_permutation`
  - `climits`: For `INT_MAX` constant

---

```cpp
int main() {
```
- Start of the main program.

---

```cpp
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
```
- **Adjacency matrix**: `dist[i][j]` gives distance from city `i` to city `j`
- `dist[0][1] = 10` means it costs 10 to go from city 0 to 1.

📊 **Visualized graph**:

```
    (0)
   / | \
10 15 20
 /  |   \
(1)-(2)--(3)
 \   \   /
 25  35 30
```

---

```cpp
    int n = dist.size();
```
- `n = 4`: Number of cities

---

```cpp
    vector<int> cities;
    for(int i = 1; i < n; i++) cities.push_back(i);
```
- Create a list of cities to **permute**: `[1, 2, 3]`
- We fix **city 0 as the starting point**, and try all permutations of other cities.

---

```cpp
    int min_cost = INT_MAX;
    vector<int> optimal_path;
```
- `min_cost`: Store the smallest cost among all paths
- `optimal_path`: Remember the best path that gave `min_cost`

---

### 🧠 **Core Loop: Try All Permutations**

```cpp
    do {
```
- **Start of permutation loop** — will try every permutation of `[1, 2, 3]`:
    - `[1, 2, 3]`
    - `[1, 3, 2]`
    - `[2, 1, 3]`
    - `[2, 3, 1]`
    - `[3, 1, 2]`
    - `[3, 2, 1]`

---

```cpp
        int current_cost = 0;
        int current_city = 0;
```
- We start from city `0`, with zero cost

---

```cpp
        for(int city : cities) {
            current_cost += dist[current_city][city];
            current_city = city;
        }
```
- For each city in the current permutation:
  - Add cost from `current_city` to `city`
  - Move `current_city` to that `city`

🔁 Example for `[1, 2, 3]`:
- 0 → 1: `+10`
- 1 → 2: `+35`
- 2 → 3: `+30`

```cpp
        current_cost += dist[current_city][0]; // return to start
```
- Add cost to **return to city 0**

✳️ Continuing example:
- 3 → 0: `+20`
- Total: `10 + 35 + 30 + 20 = 95`

---

```cpp
        if (current_cost < min_cost) {
            min_cost = current_cost;
            optimal_path = cities;
        }
```
- If this route is better (shorter), update `min_cost` and remember the permutation

---

```cpp
    } while(next_permutation(cities.begin(), cities.end()));
```
- Generate the **next permutation** of cities `[1, 2, 3]`
- Stops when all permutations are checked

---

### 🖨️ Output

```cpp
    cout << "Minimum TSP cost: " << min_cost << endl;
    cout << "Optimal Path: 0";
    for(int city : optimal_path) {
        cout << " -> " << city;
    }
    cout << " -> 0" << endl;
```
- Print the **best cost** and the **full route**
- Always starts and ends at city `0`

---

### ✅ Example Output:

```
Minimum TSP cost: 80
Optimal Path: 0 -> 1 -> 3 -> 2 -> 0
```

This means:  
- 0 → 1 → 3 → 2 → 0 is the shortest tour  
- Total cost = 10 + 25 + 30 + 15 = **80**

---


Let's walk through **detailed iterations** of the permutation loop in your TSP brute-force code for the 4 cities.

---

### 🗺️ **Graph Recap:**

Distance matrix `dist[i][j]`:

```
       0    1    2    3
     -------------------
0 |   0   10   15   20
1 |  10    0   35   25
2 |  15   35    0   30
3 |  20   25   30    0
```

---

### 📍Cities to permute: `[1, 2, 3]`

We'll always start and end at **city 0**, and try all permutations of the rest.

---

## ✅ **Iteration 1: [1, 2, 3]**

**Path:** `0 → 1 → 2 → 3 → 0`

- `0 → 1`: 10
- `1 → 2`: 35
- `2 → 3`: 30
- `3 → 0`: 20

**Total cost:** `10 + 35 + 30 + 20 = 95`

✅ Update `min_cost = 95`, `optimal_path = [1, 2, 3]`

---

## ✅ **Iteration 2: [1, 3, 2]**

**Path:** `0 → 1 → 3 → 2 → 0`

- `0 → 1`: 10
- `1 → 3`: 25
- `3 → 2`: 30
- `2 → 0`: 15

**Total cost:** `10 + 25 + 30 + 15 = 80`

✅ New best → `min_cost = 80`, `optimal_path = [1, 3, 2]`

---

## ✅ **Iteration 3: [2, 1, 3]**

**Path:** `0 → 2 → 1 → 3 → 0`

- `0 → 2`: 15  
- `2 → 1`: 35  
- `1 → 3`: 25  
- `3 → 0`: 20

**Total cost:** `15 + 35 + 25 + 20 = 95`

✖️ No update (not better than 80)

---

## ✅ **Iteration 4: [2, 3, 1]**

**Path:** `0 → 2 → 3 → 1 → 0`

- `0 → 2`: 15  
- `2 → 3`: 30  
- `3 → 1`: 25  
- `1 → 0`: 10

**Total cost:** `15 + 30 + 25 + 10 = 80`

✅ Ties with current best (but still 80), so optional update

---

## ✅ **Iteration 5: [3, 1, 2]**

**Path:** `0 → 3 → 1 → 2 → 0`

- `0 → 3`: 20  
- `3 → 1`: 25  
- `1 → 2`: 35  
- `2 → 0`: 15

**Total cost:** `20 + 25 + 35 + 15 = 95`

✖️ No update

---

## ✅ **Iteration 6: [3, 2, 1]**

**Path:** `0 → 3 → 2 → 1 → 0`

- `0 → 3`: 20  
- `3 → 2`: 30  
- `2 → 1`: 35  
- `1 → 0`: 10

**Total cost:** `20 + 30 + 35 + 10 = 95`

✖️ No update

---

### ✅ Final Output After All Iterations:

```
Minimum TSP cost: 80
Optimal Path: 0 -> 1 -> 3 -> 2 -> 0
```

---

### 🔁 Summary Table:

| Permutation | Path                  | Cost |
|-------------|------------------------|------|
| [1, 2, 3]   | 0 → 1 → 2 → 3 → 0      | 95   |
| [1, 3, 2]   | 0 → 1 → 3 → 2 → 0 ✅    | 80   |
| [2, 1, 3]   | 0 → 2 → 1 → 3 → 0      | 95   |
| [2, 3, 1]   | 0 → 2 → 3 → 1 → 0 ✅    | 80   |
| [3, 1, 2]   | 0 → 3 → 1 → 2 → 0      | 95   |
| [3, 2, 1]   | 0 → 3 → 2 → 1 → 0      | 95   |

