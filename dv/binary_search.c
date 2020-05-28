#include <stdio.h>

#include "../utils.h"

int binary_search(int* arr, int begin, int end, int elem)
{
    if (begin > end) return -1;

    int mid = (begin + end) / 2;

    if (arr[mid] == elem) {
        return mid;
    } else if (arr[mid] < elem){
        return binary_search(arr, mid + 1, end, elem);
    } else {
        return binary_search(arr, begin, mid - 1, elem);
    }
}

int main() {
    int N = 10;
    int arr[] = {3, 6, 9, 12, 17, 24, 34, 70, 190, 200};

    int K = 24;

    print_arr(arr, N);
    int index = binary_search(arr, 0, N -1, K);
    if (index != -1) {
        printf("Elemento encontrado en el indice %d.\n", index);
    } else {
        printf("Elemento no encontrado.\n");
    }

    return 0;
}