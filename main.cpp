#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int n, bool asc = true);

void bubbleSort(int arr[], int n, bool asc = true);

void insertionSort(int arr[], int n, bool asc = true);

void mergeSort(int arr[], int l, int r);

void merge(int arr[], int l, int m, int r);

int main() {
    int arr[] = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // selectionSort(arr, n, false);
    // bubbleSort(arr, n, false);
    // insertionSort(arr, n, false);
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void selectionSort(int arr[], int n, bool asc) {
    int idx;
    if (asc) {
        for (int i = 0; i < n - 1; ++i) {
            idx = i;
            for (int j = i + 1; j < n; ++j) {
                idx = arr[idx] < arr[j] ? idx : j;
            }

            int tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    } else {
        for (int i = 0; i < n - 1; ++i) {
            idx = i;
            for (int j = i + 1; j < n; ++j) {
                idx = arr[idx] > arr[j] ? idx : j;
            }

            int tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }
}

void bubbleSort(int arr[], int n, bool asc) {
    if (asc) {
        for (int i = 0; i < n - 1; ++i) {
            bool swap = false;
            for (int j = 0; j < n - 1 - i; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap = true;
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
            if (!swap) break;
        }
    } else {
        for (int i = 0; i < n - 1; ++i) {
            bool swap = false;
            for (int j = 0; j < n - 1 - i; ++j) {
                if (arr[j] < arr[j + 1]) {
                    swap = true;
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
            if (!swap) break;
        }
    }
}

void insertionSort(int arr[], int n, bool asc) {
    if (asc) {
        for (int i = 1; i < n; ++i) {
            int tmp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > tmp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = tmp;
        }
    } else {
        for (int i = 1; i < n; ++i) {
            int tmp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] < tmp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = tmp;
        }
    }
}

void merge(int arr[], int l, int m, int r) {

}

void mergeSort(int arr[], int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}