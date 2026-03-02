# 🟢 Exercise 03: ft_count_if

## 📝 Objective
Create a function `ft_count_if`, which returns the number of elements in the array for which the function `f` does not return 0.

## 💡 The Logic
This simulates the classic "filter/count" array method.
1. **The Counter:** We initialize an integer `cnt = 0`.
2. **Iteration:** We iterate through the array up to `length`.
3. **Evaluation:** For each element, we evaluate `f(tab[i])`. If the return value is not `0`, we increment our counter `cnt++`. Once the loop finishes, we return the total count.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_count_if.c`](ft_count_if.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-11` directory. You must pass the `-D EX03` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX03 ../tester.c ft_count_if.c -o test_ex03
   ./test_ex03
   ```
