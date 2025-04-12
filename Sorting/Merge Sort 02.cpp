#include <iostream>
using namespace std;

void merge(int A[], int left, int mid, int right) {
    int i;
    int index_a, index_l, index_r;
    int size_left = mid - left + 1;
    int size_right = right - mid;
    int L[size_left], R[size_right];
    
    for (i = 0; i < size_left; i++) {
        L[i] = A[left + i];
    }
    for (i = 0; i < size_right; i++) {
        R[i] = A[mid + 1 + i];
    }
    
    index_l = 0;
    index_r = 0;
    index_a = left;
    while (index_l < size_left && index_r < size_right) {
        if (L[index_l] <= R[index_r]) {
            A[index_a] = L[index_l];
            index_l++;
        } else {
            A[index_a] = R[index_r];
            index_r++;
        }
        index_a++;
    }

    while (index_l < size_left) {
        A[index_a] = L[index_l];
        index_l++;
        index_a++;
    }

    while (index_r < size_right) {
        A[index_a] = R[index_r];
        index_r++;
        index_a++;
    }
}

void merge_sort(int A[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int i, n = 8;
    int A[] = {1, 5, 6, 3, 5, 8, 7, 2};
    merge_sort(A, 0, n - 1);
    for (i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
