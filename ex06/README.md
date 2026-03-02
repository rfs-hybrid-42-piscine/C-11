# 🟢 Exercise 06: ft_sort_string_tab

## 📝 Objective
Create the function `ft_sort_string_tab`, which sorts the strings in `tab` in ASCII order. 

## 💡 The Logic
This exercise demonstrates performance optimization when sorting massive arrays.
1. **Pointer Swapping:** We use a Bubble Sort algorithm. However, rather than copying entire strings character by character (which is slow and inefficient), the sorting is performed by exchanging the array's pointers.
2. **ASCII Evaluation:** We implement a standard `ft_strcmp` to evaluate the ASCII difference between `tab[j]` and `tab[j + 1]`. 
3. **Execution:** If `ft_strcmp` returns a value `> 0`, it means the strings are out of alphabetical order, triggering our pointer `ft_swap`.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_sort_string_tab.c`](ft_sort_string_tab.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-11` directory. You must pass the `-D EX06` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX06 ../tester.c ft_sort_string_tab.c -o test_ex06
   ./test_ex06
   ```
