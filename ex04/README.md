# 🟢 Exercise 04: ft_is_sort

## 📝 Objective
Create a function `ft_is_sort`, which returns 1 if the array is sorted and 0 if it is not.

## 💡 The Logic
This requires dynamically evaluating sequence direction.
1. **Comparator Return:** The provided function `f` returns a negative integer if the first argument is less, 0 if equal, or a positive integer if greater.
2. **Finding the Direction:** A sorted array can be *ascending* or *descending*. We establish the initial `sort_dir` based on the first two non-equal elements we encounter.
3. **Validating the Sequence:** We iterate through the rest of the array. If the array was established as ascending (`sort_dir == -1`) but we encounter a pair where `cmp_res > 0`, the sequence is broken, and we `return (0)`. If the loop finishes smoothly, we `return (1)`.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_is_sort.c`](ft_is_sort.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-11` directory. You must pass the `-D EX04` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX04 ../tester.c ft_is_sort.c -o test_ex04
   ./test_ex04
   ```
