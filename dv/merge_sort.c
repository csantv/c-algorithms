#include <limits.h>

#include "../utils.h"

void merge(int* arr, int begin, int mid, int end)
{
    int n1 = mid - begin + 1;
    int n2 = end - mid;

    int arr1[n1 + 1];
    int arr2[n2 + 1];

    // copy arrays
    for (int i = begin, j = 0; i <= mid; i++) {
        arr1[j] = arr[i];
        j++;
    }

    for (int i = mid + 1, j = 0; i <= end; i++) {
        arr2[j] = arr[i];
        j++;
    }

    arr1[n1] = INT_MAX;
    arr2[n2] = INT_MAX;

    int i = begin, k = 0, m = 0;
    while (i <= end) {
        if (arr1[k] < arr2[m]) {
            arr[i] = arr1[k];
            k++;
        } else {
            arr[i] = arr2[m];
            m++;
        }
        i++;
    }
}

void merge_sort(int* arr, int begin, int end)
{
    if (begin == end) return;

    int mid = (begin + end) / 2;
    merge_sort(arr, begin, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, begin, mid , end);
}

int main()
{
    int N = 10;
    int arr[] = {4, 9, 1, 45, 12, 3, 14, 0, 89, 7};

    merge_sort(arr, 0 ,N - 1);
    print_arr(arr, N);

    return 0;
}