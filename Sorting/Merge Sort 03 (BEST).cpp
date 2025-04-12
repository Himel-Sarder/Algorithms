#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int start, int mid, int end)
{

    int tempArr[end - start + 1];

    int index1 = start;
    int index2 = mid + 1;
    int indexTemp = 0;

    while (index1 <= mid && index2 <= end)
    {
        if (arr[index1] < arr[index2])
            tempArr[indexTemp++] = arr[index1++];
        else
            tempArr[indexTemp++] = arr[index2++];
    }

    while (index1 <= mid)
    {
        tempArr[indexTemp++] = arr[index1++];
    }

    while (index2 <= end)
    {
        tempArr[indexTemp++] = arr[index2++];
    }

    for (int i = start, indexTemp = 0; i <= end; i++, indexTemp++)
    {
        arr[i] = tempArr[indexTemp];
    }
}

void divide(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        divide(arr, start, mid);
        divide(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

int main()
{
    int n;

    cout << "Enter the number of element : ";

    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    divide(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// Himel Sarder
