#include <stdio.h>;
#include <stdlib.h>;
#include <stdbool.h>;
#include <assert.h>
#include "merge_sort_generic.h"

// for more documentation see merge_sort_generic.h

void merge_generic(void *dest, const void *src1, const void *src2, size_t len1, size_t len2, int (*cmp)(const void *, const void *), size_t element_size) {
    assert(dest);
    assert(src1);
    assert(src2);
    size_t pos1 = 0;
    size_t pos2 = 0;
    for (size_t i = 0; i < len1 + len2; i++) {
        if (pos1 == len1 || (pos2 < len2 && cmp((char *)src1 + pos1 * element_size, (char *)src2 + pos2 * element_size) >= 0)) {
            my_memcpy((char *)dest + i * element_size, (char *)src2 + pos2 * element_size, element_size);
            pos2++;
        } else {
            my_memcpy((char *)dest + i * element_size, (char *)src1 + pos1 * element_size, element_size);
            pos1++;
        }
    }
}

void *my_memcpy(void *dest, const void *src, size_t n) {
    assert(dest);
    assert(src);
    size_t i = 0;
    char *d_char = (char *)dest;
    char *s_char = (char *)src;
    while (n--) {
        *d_char++ = *s_char++;
    }
    return dest;
}

void merge_sort_generic(void *arr, size_t n, size_t element_size, int (*cmp)(const void *, const void *)) {
    assert(arr);
    if (n <= 1) {
        return;
    }
    size_t llen = n / 2;
    size_t rlen = n - llen;
    void *left = malloc(llen * element_size);
    void *right = malloc(rlen * element_size);
    for (size_t i = 0; i < llen; i++) {
        my_memcpy((char *)left + i * element_size, (char *)arr + i * element_size, element_size);
    }
    for (size_t i = 0; i < rlen; i++) {
        my_memcpy((char *)right + i * element_size, (char *)arr + (llen + i) * element_size, element_size);
    }
    merge_sort_generic(left, llen, element_size, cmp);
    merge_sort_generic(right, rlen, element_size, cmp);
    merge_generic(arr, left, right, llen, rlen, cmp, element_size);
    free(left);
    free(right);
}


