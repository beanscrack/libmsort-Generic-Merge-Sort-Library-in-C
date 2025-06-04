#ifndef MERGE_SORT_GENERIC_H
#define MERGE_SORT_GENERIC_H

#include <stddef.h>  // for size_t

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file merge_sort_generic.h
 * @brief A generic merge sort library for C using function pointers and void pointers.
 *
 * This library provides a flexible way to sort arrays of any data type using
 * merge sort. The implementation relies on user-provided comparison functions
 * and uses void pointers to handle generic types.
 *
 * Example usage:
 * ```c
 * int cmp_int(const void *a, const void *b) {
 *     return (*(int *)a) - (*(int *)b);
 * }
 * 
 * int arr[] = {4, 2, 1, 9};
 * merge_sort_generic(arr, 4, sizeof(int), cmp_int);
 * ```

 */

/**
 * @brief Performs a generic merge sort on an array.
 *
 * @param arr           Pointer to the array to sort.
 * @param n             Number of elements in the array.
 * @param element_size  Size of each element in bytes.
 * @param cmp           Pointer to a comparison function that returns:
 *                      < 0 if a < b,
 *                      0 if a == b,
 *                      > 0 if a > b.
 */
void merge_sort_generic(void *arr, size_t n, size_t element_size,
                        int (*cmp)(const void *, const void *));

/**
 * @brief Internal function to merge two sorted arrays into one.
 *
 * @param dest          Pointer to the destination array.
 * @param src1          Pointer to the first sorted array.
 * @param src2          Pointer to the second sorted array.
 * @param len1          Number of elements in the first array.
 * @param len2          Number of elements in the second array.
 * @param cmp           Comparison function (same as above).
 * @param element_size  Size of each element in bytes.
 */
void merge_generic(void *dest, const void *src1, const void *src2, size_t len1,
                   size_t len2, int (*cmp)(const void *, const void *),
                   size_t element_size);

/**
 * @brief A custom implementation of memcpy.
 *
 * @param dest  Destination pointer.
 * @param src   Source pointer.
 * @param n     Number of bytes to copy.
 * @return      Pointer to the destination.
 */
void *my_memcpy(void *dest, const void *src, size_t n);

#ifdef __cplusplus
}
#endif

#endif // MERGE_SORT_GENERIC_H
