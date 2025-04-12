## 🧠 What is a **DP array**?

In **Dynamic Programming (DP)**, a **DP array** is a table (usually a 1D or 2D array) that stores **solutions to subproblems** so we don’t have to **recalculate** them again and again.

It’s like keeping a memory of smaller problems to **build up** to the final solution.

---

## 📦 In the 0/1 Knapsack Problem

### 🔍 Problem:
You're given items with weights and values. You have a bag (knapsack) with limited weight capacity. **Choose items to maximize value** without exceeding capacity.

---

### 💡 DP Array Purpose

Let’s say `dp[j]` means:
> “What is the **maximum value** I can achieve with **capacity `j`**?”

So, for each item, we update the DP array by deciding:

- ✅ **Include** the item: `dp[j] = dp[j - weight] + value`
- ❌ **Exclude** the item: `dp[j] = dp[j]` (no change)

We take the **maximum** of those two.

---

## 🔁 How It Works (Step-by-step)

### Suppose:
- You have a knapsack of capacity 5
- And 4 items:  
  `values = [4, 3, 6, 5]`  
  `weights = [3, 2, 5, 4]`

You initialize:

```cpp
int dp[51] = {}; // dp[0] to dp[5] are all 0
```

Now for **each item**, and for each capacity `j` (in reverse), we **try to add that item** if it fits.

---

## 🧪 Visualization

After processing some items, your `dp` might look like:

```
dp[0]  dp[1]  dp[2]  dp[3]  dp[4]  dp[5]
  0      0     3      4      5      7
```

This means:

- At capacity 0 → value 0 (can't carry anything)
- At capacity 2 → best you can do is value 3
- At capacity 5 → max value is **7**

You **build this up step by step**, so when you reach the final item, you’ve already stored all optimal choices for smaller capacities.

---

## 🔚 Summary

✅ A **DP array** is like a **cache** that remembers the best solutions to small subproblems  
📦 In knapsack, it stores **max value for each weight capacity**  
⚡ It helps avoid recomputation and makes the solution efficient (from exponential to polynomial time)

---


**DP (Dynamic Programming)** is a technique for solving problems by **breaking them down into smaller subproblems**, solving each subproblem **only once**, and **storing** the results so we can **reuse** them later.

The **DP array** is simply the structure where we **store these results**.

- In 0/1 Knapsack, the DP array holds the **maximum value** that can be obtained with a given capacity of the knapsack.

---

## **Example Problem**

You are given:
- `values = {4, 3, 6, 5}` → Value of each item
- `weights = {3, 2, 5, 4}` → Weight of each item
- `capacity = 5` → Knapsack's weight limit

Goal: **Pick items such that total weight ≤ 5 and total value is maximized**

---

## **DP Array Design**

We’ll use a **1D array**, `dp[j]`, where:
- `j` = current capacity (from 0 to 5)
- `dp[j]` = max value that can be achieved using **any subset of items** and **capacity j**

Initial state:
```cpp
dp = {0, 0, 0, 0, 0, 0}  // dp[0] to dp[5] (6 elements)
```

---

## **Processing Each Item**

### Let’s take the first item:
- Value = 4
- Weight = 3

We iterate from capacity `5` to `3`:
```cpp
for (j = 5 to 3) {
    dp[j] = max(dp[j], dp[j - 3] + 4)
}
```

Breakdown:

- `dp[5] = max(0, dp[2] + 4) = max(0, 0 + 4) = 4`
- `dp[4] = max(0, dp[1] + 4) = max(0, 0 + 4) = 4`
- `dp[3] = max(0, dp[0] + 4) = max(0, 0 + 4) = 4`

So `dp` becomes:
```
{0, 0, 0, 4, 4, 4}
```

---

### Now process second item:
- Value = 3
- Weight = 2

Iterate from `5` to `2`:
- `dp[5] = max(4, dp[3] + 3) = max(4, 4 + 3) = 7`
- `dp[4] = max(4, dp[2] + 3) = max(4, 0 + 3) = 4`
- `dp[3] = max(4, dp[1] + 3) = max(4, 0 + 3) = 4`
- `dp[2] = max(0, dp[0] + 3) = max(0, 0 + 3) = 3`

Now:
```
{0, 0, 3, 4, 4, 7}
```

You can see how we're **building up the best values** using previous results.

---

## **Why Loop Backwards?**

We **loop backwards (from capacity → weight)** to make sure we **don’t use the same item more than once** in the same iteration. This is important in **0/1 knapsack**, where you either take the item or not — no repetitions.

---

## **Final Answer**

After processing all items, `dp[capacity]` (i.e., `dp[5]`) gives the **maximum achievable value** with the given knapsack capacity.

---

## **Full Example Visualization**

Let’s show how `dp` changes after each item:

1. After item 0 (value = 4, weight = 3):
   ```
   {0, 0, 0, 4, 4, 4}
   ```

2. After item 1 (value = 3, weight = 2):
   ```
   {0, 0, 3, 4, 4, 7}
   ```

3. After item 2 (value = 6, weight = 5):
   - Try to fit into capacity 5:
     `dp[5] = max(7, dp[0] + 6) = max(7, 6) = 7` (no change)

   ```
   {0, 0, 3, 4, 4, 7}
   ```

4. After item 3 (value = 5, weight = 4):
   - `dp[5] = max(7, dp[1] + 5) = max(7, 5) = 7`
   - `dp[4] = max(4, dp[0] + 5) = max(4, 5) = 5`

   ```
   {0, 0, 3, 4, 5, 7}
   ```

So, **max value = 7** at capacity 5.

---

## **TL;DR: What is a DP Array?**

- It's a memory that holds answers to small subproblems
- Helps avoid recalculating the same thing again
- In knapsack, it tells max value for every capacity up to the limit
- It's built step-by-step using decisions: **take or skip** each item

---
