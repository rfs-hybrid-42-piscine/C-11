# 🟢 Exercise 00: ft_foreach

## 📝 Objective
Create the function `ft_foreach`, which applies a given function to all elements of an integer array.

## 💡 The Logic
This exercise introduces the basic syntax and execution of function pointers.
1. **The Prototype:** The function accepts `void (*f)(int)` as a parameter, meaning it takes a pointer to any function that returns `void` and accepts a single `int`.
2. **The Execution:** We iterate through the array using a standard `while` loop, passing each element `tab[i]` directly into the function pointer `f(tab[i])`.
3. **Safety:** We add a guard clause `if (!tab || !f)` to prevent segmentation faults in case a `NULL` array or a `NULL` function pointer is passed.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_foreach.c`](ft_foreach.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-11` directory. You must pass the `-D EX00` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX00 ../tester.c ft_foreach.c -o test_ex00
   ./test_ex00
   ```
