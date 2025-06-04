🧮 libmsort: Generic Merge Sort Library in C

This library provides a **type-agnostic, generic merge sort** implementation in C using function pointers and manual memory handling. It demonstrates low-level data manipulation, pointer arithmetic, and functional design — all without relying on `qsort`.

🔧 Features

- 🔁 Supports sorting arrays of **any data type** (integers, floats, structs, etc.)
- 💡 Requires only a **comparison function** to sort custom data types
- 🛠️ Replaces `memcpy` with a custom `my_memcpy` implementation
- 💻 Pure C — portable and dependency-free
- 
✨ How It Works

- **`merge_sort_generic(arr, n, element_size, cmp)`**  
  Recursively divides the array and merges sorted halves.

- **`merge_generic(dest, src1, src2, len1, len2, cmp, element_size)`**  
  Merges two sorted subarrays into a destination buffer.

- **`my_memcpy(dest, src, n)`**  
  Custom byte-wise memory copy function for portability and learning.

📌 Usage Example

```c
#include <stdio.h>
#include "merge_sort_generic.h"

int cmp_int(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    int arr[] = {5, 3, 8, 1, 9};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    merge_sort_generic(arr, n, sizeof(int), cmp_int);

    for (size_t i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
