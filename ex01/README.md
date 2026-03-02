# 🟢 Exercise 01: ft_map

## 📝 Objective
Create the function `ft_map`, which applies a given function to all elements of an integer array (in order) and returns a new array containing all the return values.

## 💡 The Logic
This exercise combines function pointers with dynamic memory allocation (`malloc` is explicitly allowed).
1. **Allocation:** We dynamically allocate a new integer array `new` of size `length`. If allocation fails, we return `NULL`.
2. **Transformation:** We iterate through the original array. For each element, we pass it to the function pointer and store its return value in the corresponding index of our new array: `new[i] = f(tab[i])`.
3. **Return:** The newly populated array is returned to the caller (who is responsible for eventually freeing it).

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_map.c`](ft_map.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-11` directory. You must pass the `-D EX01` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX01 ../tester.c ft_map.c -o test_ex01
   ./test_ex01
   ```
