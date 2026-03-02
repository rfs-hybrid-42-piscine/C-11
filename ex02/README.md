# 🟢 Exercise 02: ft_any

## 📝 Objective
Create a function `ft_any`, which returns 1 if, when passed to the function `f`, at least one element of the array returns a value other than 0. Otherwise, it should return 0.

## 💡 The Logic
This simulates the classic "any" or "some" array method found in higher-level languages.
1. **Null-Terminated Array:** Unlike previous exercises, the string array `tab` is delimited by a null pointer. This means we don't need a `length` parameter; we iterate until `tab[i]` is `NULL`.
2. **Early Return:** Inside the loop, we evaluate `f(tab[i])`. If it returns anything other than `0`, we immediately `return (1)` to stop execution and save performance.
3. **Fallback:** If the loop completely finishes without any matches, we `return (0)`.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_any.c`](ft_any.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-11` directory. You must pass the `-D EX02` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX02 ../tester.c ft_any.c -o test_ex02
   ./test_ex02
   ```
