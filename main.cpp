#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int n, bool asc = true);

void bubbleSort(int arr[], int n, bool asc = true);

void insertionSort(int arr[], int n, bool asc = true);

void merge(int arr[], int l, int m, int r, bool asc);

void mergeSort(int arr[], int l, int r, bool asc=true);

int partition(int arr[],int l,int r, bool asc);

void quickSort(int arr[],int l,int r, bool asc=true);

void countSort(int arr[],int n,bool asc=true);

int main() {
    int arr[] = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // selectionSort(arr, n, false);
    // bubbleSort(arr, n, false);
    // insertionSort(arr, n, false);
    //mergeSort(arr, 0, n - 1, false);
    //quickSort(arr,0,n-1,false);
    countSort(arr,n,false);
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

void merge(int arr[], int l, int m, int r,bool asc) {
    int n1 = m-l+1, n2=r-m;
    int arr1[n1], arr2[n2];
    for (int i=0;i<n1;++i)
        arr1[i]=arr[l+i];
    for(int i=0;i<n2;++i) 
        arr2[i]=arr[m+1+i];

    int i=0,j=0,k=l;
    if(asc) {
        while(i<n1&&j<n2) {
            if(arr1[i]<=arr2[j]) {
                arr[k]=arr1[i];
                ++i;
            } else {
                arr[k]=arr2[j];
                ++j;
            }
            ++k;
        }
    } else {
        while(i<n1&&j<n2) {
            if(arr1[i]>=arr2[j]) {
                arr[k]=arr1[i];
                ++i;
            } else {
                arr[k]=arr2[j];
                ++j;
            }
            ++k;
        }
    }
    while(i<n1){
        arr[k]=arr1[i];
        ++i;
        ++k;
    }
    while(j<n2){
        arr[k]=arr2[j];
        ++j;
        ++k;
    }
}

void mergeSort(int arr[], int l, int r,bool asc) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m,asc);
    mergeSort(arr, m + 1, r,asc);
    merge(arr, l, m, r,asc);
}

int partition(int arr[], int l,int r, bool asc) {
    if(asc){
        int pivot = arr[r];
        int i = l-1;
        for(int j=l;j<r;++j){
            if(arr[j]<pivot) {
                ++i;

                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }

        int tmp=arr[i+1];
        arr[i+1]=pivot;
        arr[r]=tmp;
        return i+1;
    }else{
        int pivot = arr[r];
        int i = l-1;
        for(int j=l;j<r;++j){
            if(arr[j]>pivot) {
                ++i;

                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }

        int tmp=arr[i+1];
        arr[i+1]=pivot;
        arr[r]=tmp;
        return i+1;
    }
}

void quickSort(int arr[],int l,int r, bool asc) {
    if(r<=l) return;

    int piIdx = partition(arr,l,r,asc);

    quickSort(arr,l,piIdx-1,asc);
    quickSort(arr,piIdx+1,r,asc);
}

void countSort(int arr[], int n,bool asc) {
    int max = *max_element(arr,arr+n);
    int min = *min_element(arr,arr+n);
    int range=max-min+1;
    int count[range];
    int sortedArr[n];
    memset(count,0,sizeof(count));

    for(int i=0;i<n;++i)
        count[arr[i]-min]++;
    for(int i=1;i<range;++i)
        count[i]+=count[i-1];
    if(asc) {
        for(int i=0;i<n;++i){
            sortedArr[count[arr[i]]-1]=arr[i];
            count[arr[i]-min]--;
        }
    } else {
        for(int i=0;i<n;++i){
            sortedArr[n-(count[arr[i]]-1)-1]=arr[i];
            count[arr[i]-min]--;
        }
    }
    for(int i=0;i<n;++i)
        arr[i]=sortedArr[i];
}
