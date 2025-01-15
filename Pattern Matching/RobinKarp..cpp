#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int prime = 101; // Prime number used for hash calculation

// Function to calculate the initial hash value
int calculateHash(string str, int length)
{
    int hash = 0;
    for (int i = 0; i < length; i++)
    {
        hash += str[i] * pow(prime, i); // Calculate hash using prime^i
    }
    return hash;
}

// Rabin-Karp Search using the rolling hash formula
void rabinKarpSearch(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    int patternHash = calculateHash(pattern, m); // Hash of the pattern
    int textHash = calculateHash(text, m);       // Hash of the first window of text

    for (int i = 0; i <= n - m; i++)
    {
        // Check if hash values match
        if (patternHash == textHash)
        {
            // Verify characters one by one
            if (text.substr(i, m) == pattern)
            {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Compute the rolling hash for the next window
        if (i < n - m)
        {
            int oldCharValue = text[i];
            int newCharValue = text[i + m];

            textHash -= oldCharValue;                     // Step 1: Subtract value of old character
            textHash /= prime;                            // Step 2: Divide by prime
            textHash += newCharValue * pow(prime, m - 1); // Step 3: Add value of new character
        }
    }
}

int main()
{
    string text = "ababcabcabababd";
    string pattern = "ababd";

    rabinKarpSearch(text, pattern);

    return 0;
}
