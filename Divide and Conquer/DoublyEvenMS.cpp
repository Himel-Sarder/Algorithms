#include <iostream>
using namespace std;

int main() {
    int n;

    // Input
    cout << "Enter size of magic square (must be divisible by 4): ";
    cin >> n;

    // Check for valid doubly even size
    if (n % 4 != 0) {
        cout << "Error: Size must be divisible by 4!\n";
        return 1;
    }

    cout << "\nMagic Square of size " << n << "x" << n << ":\n\n";

    // Generate the magic square
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            // Calculate cell value
            int value;
            if (i % 4 == j % 4 || (i % 4 + j % 4 == 3)) {
                value = n * n - (i * n + j);
            } else {
                value = i * n + j + 1;
            }

            // Print the value with tab spacing
            cout << value << "\t";
        }
        cout << "\n";
    }

    // Optional: Print magic constant
    int magic_sum = n * (n * n + 1) / 2;
    cout << "\nMagic Constant (Sum of each row/col/diag): " << magic_sum << "\n";

    return 0;
}
