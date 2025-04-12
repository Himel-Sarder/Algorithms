#include<bits/stdc++.h>

using namespace std;

void Bubble(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i -1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }        
        }
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int array[] = {9,3,2,1,8,10,7,6};
    int x = sizeof(array) / sizeof(int); // int x = sizeof(array) / sizeof(array[0]);
    Bubble(array, x);
}
