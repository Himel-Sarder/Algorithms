Let's break down the **Longest Increasing Subsequence (LIS)** code step by step, showing **full iterations** and explaining each line's purpose.

---

### **Given Code**:
```cpp
vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
vector<int> lis;

for (int num : nums) {
    auto it = lower_bound(lis.begin(), lis.end(), num);
    if (it == lis.end())
        lis.push_back(num);
    else
        *it = num;
}
```

### **Key Concepts**:
1. **`lower_bound`**: Finds the first element ≥ `num` in `lis` (binary search, O(log n)).
2. **`lis`**: Maintains the **smallest possible tail values** for increasing subsequences of increasing lengths.
3. **Goal**: Build the longest possible increasing subsequence by replacing elements strategically.

---

### **Step-by-Step Execution**:

| **Iteration** | **Current `num`** | **`lis` Before Update** | **`lower_bound` Action**            | **`lis` After Update** | **Explanation** |
|---------------|-------------------|-------------------------|--------------------------------------|------------------------|-----------------|
| 1             | `10`              | `[]`                    | `it = lis.end()`                     | `[10]`                 | First element, directly append. |
| 2             | `9`               | `[10]`                  | `it` points to `10` (≥ `9`)          | `[9]`                  | Replace `10` with `9` (better tail for length 1). |
| 3             | `2`               | `[9]`                   | `it` points to `9` (≥ `2`)           | `[2]`                  | Replace `9` with `2` (better tail for length 1). |
| 4             | `5`               | `[2]`                   | `it = lis.end()`                     | `[2, 5]`               | `5` > `2`, append to extend LIS to length 2. |
| 5             | `3`               | `[2, 5]`                | `it` points to `5` (≥ `3`)           | `[2, 3]`               | Replace `5` with `3` (better tail for length 2). |
| 6             | `7`               | `[2, 3]`                | `it = lis.end()`                     | `[2, 3, 7]`            | `7` > `3`, append to extend LIS to length 3. |
| 7             | `101`             | `[2, 3, 7]`             | `it = lis.end()`                     | `[2, 3, 7, 101]`       | `101` > `7`, append to extend LIS to length 4. |
| 8             | `18`              | `[2, 3, 7, 101]`        | `it` points to `101` (≥ `18`)        | `[2, 3, 7, 18]`        | Replace `101` with `18` (better tail for length 4). |

---

### **Final Output**:
- **`lis`**: `[2, 3, 7, 18]` (Length = 4)
- **Actual LIS**: `[2, 5, 7, 101]` or `[2, 3, 7, 101]` (the code tracks **length**, not the exact sequence).

---

### **Line-by-Line Explanation**:
1. **`for (int num : nums)`**:
   - Iterates over each number in `nums`.

2. **`auto it = lower_bound(lis.begin(), lis.end(), num)`**:
   - Finds the first element in `lis` ≥ `num` (binary search).
   - If all elements are < `num`, returns `lis.end()`.

3. **`if (it == lis.end())`**:
   - If `num` is larger than all elements in `lis`, append it to extend the LIS.

4. **`else *it = num`**:
   - If `num` ≤ an existing element, replace it to maintain the smallest possible tail value for that subsequence length.

---

### **Why It Works**:
- **Maintains Optimal Tails**: By keeping the smallest possible values for each subsequence length, future numbers have a higher chance of extending the LIS.
- **Time Complexity**: O(n log n) (binary search dominates the loop).

---

### **Example Walkthrough** (Visual):
```
nums: [10, 9, 2, 5, 3, 7, 101, 18]

Step 1: 10 → lis = [10]
Step 2: 9  → replace 10 → [9]
Step 3: 2  → replace 9  → [2]
Step 4: 5  → append     → [2, 5]
Step 5: 3  → replace 5  → [2, 3]
Step 6: 7  → append     → [2, 3, 7]
Step 7: 101→ append     → [2, 3, 7, 101]
Step 8: 18 → replace 101→ [2, 3, 7, 18]
```

The **length** of `lis` (4) is correct, though the final sequence may not match an actual LIS in the original array. For exact sequences, use a DP-based approach with O(n²) time.
