# 🟢 Exercise 07: ft_advanced_sort_string_tab

## 📝 Objective
Create the function `ft_advanced_sort_string_tab`, which sorts an array of strings depending on the return value of a custom comparison function provided as an argument.

## 💡 The Logic
This combines the pointer-swapping sorting logic of `ex06` with the dynamic function pointer paradigm.
1. **The Custom Comparator:** Instead of hardcoding `ft_strcmp` into our bubble sort, the function prototype accepts `int (*cmp)(char *, char *)`. 
2. **Dynamic Sorting:** In our bubble sort condition, we call `cmp(tab[j], tab[j + 1])`. This means the user can pass a function that sorts ascending, descending, by string length, or any other rule, and our sort algorithm will adapt flawlessly!

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_advanced_sort_string_tab.c`](ft_advanced_sort_string_tab.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-11` directory. You must pass the `-D EX07` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX07 ../tester.c ft_advanced_sort_string_tab.c -o test_ex07
   ./test_ex07
   ```
