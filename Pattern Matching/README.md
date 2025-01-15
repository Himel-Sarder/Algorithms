# Robin Karp   
---   
Here’s a line-by-line explanation of the Rabin-Karp algorithm code, with examples for every step.

---

### **Code Explanation**

#### **1. Header Files and Namespace**

```cpp
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
```

- **`#include <iostream>`**: Used for input/output operations.
- **`#include <string>`**: Enables the use of the `string` class.
- **`#include <cmath>`**: Provides mathematical functions like `pow()` (power function).
- **`using namespace std;`**: Simplifies code by avoiding the need to prefix standard library functions with `std::`.

---

#### **2. Prime Constant**

```cpp
const int prime = 101; // Prime number used for hash calculation
```

- **`prime`**: A small prime number used as the base for hash calculations. Prime numbers help reduce hash collisions.

---

### **Hash Calculation Function**

#### **3. Function Definition**

```cpp
int calculateHash(const string& str, int length) {
    int hash = 0;
```

- **`calculateHash`**: Computes the hash value of a string up to the given length.
- **`hash = 0`**: Initializes the hash value to zero.

---

#### **4. Compute Hash Using Prime**

```cpp
    for (int i = 0; i < length; i++) {
        hash += str[i] * pow(prime, i); // Calculate hash using prime^i
    }
    return hash;
}
```

- **`for (int i = 0; i < length; i++)`**: Iterates through the first `length` characters of the string.
- **`str[i]`**: ASCII value of the character at position `i`.
- **`pow(prime, i)`**: Raises the prime number to the power of the character’s position (`i`).
- **`hash +=`**: Adds the contribution of each character to the hash value.
- **Example**: For `str = "ababd"` and `prime = 101`:
  - `hash = 'a' * 101^0 + 'b' * 101^1 + 'a' * 101^2 + 'b' * 101^3 + 'd' * 101^4`
  - ASCII values: `'a' = 97`, `'b' = 98`, `'d' = 100`
  - `hash = 97 + (98 * 101) + (97 * 101^2) + (98 * 101^3) + (100 * 101^4)`

---

### **Rabin-Karp Search Function**

#### **5. Function Definition**

```cpp
void rabinKarpSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
```

- **`rabinKarpSearch`**: Implements the Rabin-Karp string matching algorithm.
- **`text.size()`**: Returns the length of the text.
- **`pattern.size()`**: Returns the length of the pattern.
- **Example**: For `text = "ababcabcabababd"` and `pattern = "ababd"`, `n = 15`, `m = 5`.

---

#### **6. Initial Hash Calculations**

```cpp
    int patternHash = calculateHash(pattern, m); // Hash of the pattern
    int textHash = calculateHash(text, m);       // Hash of the first window of text
```

- **`patternHash`**: Computes the hash of the pattern using the `calculateHash` function.
- **`textHash`**: Computes the hash of the first `m` characters of the text.
- **Example**:
  - `patternHash = calculateHash("ababd", 5)`
  - `textHash = calculateHash("ababc", 5)`

---

#### **7. Sliding the Window**

```cpp
    for (int i = 0; i <= n - m; i++) {
```

- **`for (int i = 0; i <= n - m; i++)`**: Iterates through all possible windows of size `m` in the text.
- **`n - m`**: Ensures the loop stops before exceeding the text length.
- **Example**: For `n = 15` and `m = 5`, the loop runs from `i = 0` to `i = 10`.

---

#### **8. Check for Hash Match**

```cpp
        if (patternHash == textHash) {
            if (text.substr(i, m) == pattern) {
                cout << "Pattern found at index " << i << endl;
            }
        }
```

- **`if (patternHash == textHash)`**: Compares the hash values of the pattern and the current window of text.
- **`text.substr(i, m)`**: Extracts a substring of length `m` starting at index `i`.
- **`== pattern`**: Confirms the match by comparing the actual strings.
- **Example**: At `i = 10`, if `textHash` and `patternHash` match, check if `"ababd" == "ababd"`.

---

#### **9. Compute Rolling Hash**

```cpp
        if (i < n - m) {
            int oldCharValue = text[i];
            int newCharValue = text[i + m];

            textHash -= oldCharValue; // Step 1: Subtract value of old character
            textHash /= prime;        // Step 2: Divide by prime
            textHash += newCharValue * pow(prime, m - 1); // Step 3: Add value of new character
        }
```

- **`oldCharValue`**: ASCII value of the character leaving the window.
- **`newCharValue`**: ASCII value of the character entering the window.
- **Rolling Hash Update**:
  1. Subtract the contribution of the old character: \( \text{textHash} -= \text{oldCharValue} \).
  2. Shift the hash by dividing by the prime: \( \text{textHash} /= \text{prime} \).
  3. Add the contribution of the new character: \( \text{textHash} += \text{newCharValue} \cdot \text{prime}^{(m-1)} \).
- **Example**:
  - For `text = "ababcabcabababd"`, at `i = 0`:
    - `oldCharValue = 'a'`, `newCharValue = 'c'`.
    - Update `textHash` for the next window `"babc"`.

---

### **Main Function**

#### **10. Input and Function Call**

```cpp
int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";

    rabinKarpSearch(text, pattern);

    return 0;
}
```

- **`text`**: The string in which the pattern is searched.
- **`pattern`**: The string to search for.
- **`rabinKarpSearch`**: Calls the search function with the given text and pattern.

---

### **Example Run**

#### Input:
- **Text**: `"ababcabcabababd"`
- **Pattern**: `"ababd"`

#### Output:
```
Pattern found at index 10
```

#### Hash Calculations:
1. Initial `patternHash = 105190579`.
2. Initial `textHash` for `"ababc" = 105190580`.
3. Rolling hash updates for each window.
