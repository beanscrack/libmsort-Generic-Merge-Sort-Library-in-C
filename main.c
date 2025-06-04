#include <stdio.h>
#include "merge_sort_generic.h"

int cmp_int(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    int arr[] = {4, 2, 7, 1, 9};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    merge_sort_generic(arr, n, sizeof(int), cmp_int);

    for (size_t i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
