*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-piscine-artwork/main/assets/covers/cover-c11.png" alt="C 11 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 C 11: Function Pointers</h1>
  <p><i>Mastering arrays of pointers, dispatch tables, and passing functions as arguments.</i></p>
  
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <img src="https://img.shields.io/badge/Norminette-Passing-success" alt="Norminette badge" />
</div>

---

## 💡 Description
**C 11** introduces one of the most powerful and advanced paradigms in the C language: **Function Pointers**. 

Instead of hardcoding which function to call, you will learn how to store the memory address of a function inside a pointer. This allows you to pass functions as arguments to other functions, apply custom logic to entire arrays dynamically, and build "dispatch tables" (arrays of function pointers) to replace massive `if/else` chains. You will use these concepts to map, filter, and sort arrays of data.

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise. It focuses on the fundamental logic of C programming, emphasizing manual memory manipulation and edge-case management.*

### 🔹 Iterators & Mapping

| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: ft_foreach`](ex00)** | **Applying Functions:** Iterating through an integer array and executing a function on each element. <br><br>**Logic:** The prototype accepts a function pointer `void (*f)(int)`. We use a simple loop from `0` to `length - 1`, calling `f(tab[i])` for every index. |
| **[`ex01: ft_map`](ex01)** | **Data Transformation:** Creating a new array based on the return values of a function. <br><br>**Logic:** `malloc` is strictly allowed here. We allocate a new integer array of size `length`. Then, we iterate through the original array, assigning `new[i] = f(tab[i])`, and return the newly allocated array. |

### 🔍 Conditionals & Sorting Logic
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex02: ft_any`](ex02)** | **Boolean Evaluation:** Checking if *any* element in a string array meets a condition. <br><br>**Logic:** We iterate through a null-terminated string array (`char **tab`). We pass each string to `f`. If `f(tab[i])` returns anything other than 0, we immediately return 1. If the loop finishes without any hits, we return 0. |
| **[`ex03: ft_count_if`](ex03)** | **Filtering:** Counting how many elements meet a specific condition. <br><br>**Logic:** Similar to `ft_any`, but instead of returning early, we increment a counter variable every time `f(tab[i]) != 0`. We iterate exactly `length` times and return the final count. |
| **[`ex04: ft_is_sort`](ex04)** | **Order Validation:** Verifying if an array is completely sorted. <br><br>**Logic:** The function pointer compares two adjacent integers (`tab[i]` and `tab[i+1]`). Since a sorted array can be either strictly ascending or strictly descending, we must check for both possibilities. If the sequence breaks neither rule, it returns 1; otherwise, it returns 0. |

### 👑 Advanced Applications


| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex05: do-op`](ex05)** | **Dispatch Tables:** Building a simple calculator program without massive `if` statements. <br><br>**Logic:** The program takes arguments like `./do-op 42 "+" 21`. Instead of hardcoding operations, we declare an array of function pointers mapped to the operators `+ - * / %`. We parse the strings to integers and route the calculation to the correct function dynamically. Edge cases like `division by zero` and `modulo by zero` must be caught and printed safely. |
| **[`ex06: ft_sort_string_tab`](ex06)** | **Pointer Sorting:** Sorting a null-terminated array of strings in ASCII order. <br><br>**Logic:** We implement a Bubble Sort algorithm. However, instead of moving the actual characters in memory, we simply swap the pointers in the `char **` array using a temporary variable. We rely on a custom `ft_strcmp` to evaluate the order. |
| **[`ex07: ft_advanced_sort_string_tab`](ex07)** | **Custom Comparators:** Sorting an array using a dynamically provided comparison function. <br><br>**Logic:** We apply the exact same pointer-swapping logic from `ex06`, but instead of hardcoding `ft_strcmp`, we call the `(*cmp)(char *, char *)` pointer provided in the arguments to evaluate the order of elements. |

---

## 🛠️ Instructions

### 🧪 Compilation & Testing
Unlike Shell scripts, C programs must be compiled before they can be executed. Furthermore, most of these exercises strictly ask for functions, not complete programs (with the exception of **[`ex05: do-op`](ex05)**). 

To make testing incredibly easy while avoiding "undefined reference" linker errors, the **[`tester.c`](tester.c)** file in the root directory uses **C Preprocessor Macros** (`#ifdef`). This allows you to selectively compile and test only the exercises you want.

1. **Clone the repository:**
   You can clone this module directly, or pull the entire 42 Piscine parent repository which includes this module as a submodule.

   **Option A: Clone this module directly**
   ```bash
   git clone git@github.com:rfs-hybrid-42-piscine/C-11.git C-11
   cd C-11
   ```

   **Option B: Clone the parent repository (with submodules)**
   ```bash
   git clone --recurse-submodules git@github.com:rfs-hybrid/42-Piscine.git 42-Piscine
   cd 42-Piscine/C-11
   ```
   *(Note: The `--recurse-submodules` flag ensures all nested module repositories are populated immediately.)*

2. **Test a Single Exercise:**
   Pass the corresponding `-D EX**` flag to activate that specific test block inside **[`tester.c`](tester.c)**.
   ```bash
   # Example for ex00:
   cc -Wall -Wextra -Werror -D EX00 tester.c ex00/ft_foreach.c -o test_ex00
   ./test_ex00
   ```

3. **Test Multiple Exercises Together:**
   You can chain multiple `-D` flags to test several functions at once, provided you include all their `.c` files in the command.
   ```bash
   # Example for ex00 and ex01:
   cc -Wall -Wextra -Werror -D EX00 -D EX01 tester.c ex00/ft_foreach.c ex01/ft_map.c -o test_multiple
   ./test_multiple
   ```

4. **Test ALL Exercises at Once (except do-op):**
   By passing the `-D TEST_ALL` master flag, you can activate the entire testing suite in one go!
   ```bash
   cc -Wall -Wextra -Werror -D TEST_ALL tester.c ex00/ft_foreach.c ex01/ft_map.c ex02/ft_any.c ex03/ft_count_if.c ex04/ft_is_sort.c ex06/ft_sort_string_tab.c ex07/ft_advanced_sort_string_tab.c -o test_all
   ./test_all
   ```

5. **Testing ex05 (do-op):**
   Because `do-op` is a standalone program that does **not** use a Makefile, it must be compiled directly from its source files and tested separately.
   ```bash
   cd ex05
   cc -Wall -Wextra -Werror do_op.c do_op_calc.c -o do-op
   ./do-op 42 "+" 21
   ./do-op 25 "/" 0
   ```

> **⚠️ WARNING for 42 Students:** Do not push **[`tester.c`](tester.c)** or any executable files to your final Moulinette repository! They are strictly for local testing purposes. Submitting unauthorized files will result in a 0.

### 🚨 The Norm
Moulinette relies on a program called `norminette` to check if your files comply with the Norm. Every single `.c` and `.h` file must pass.

**The 42 Header:**
Before writing any code, every file must start with the standard 42 header. `norminette` will automatically fail any file missing this specific signature.
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:46:25 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/01 19:52:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

Run the following command before pushing:
```bash
norminette -R CheckForbiddenSourceHeader <file.c>
```

---

## 📚 Resources & References

* [Function Pointers in C](https://www.geeksforgeeks.org/function-pointer-in-c/) - GeeksforGeeks explanation of declaring and using function pointers.
* [C Dispatch Tables](https://en.wikipedia.org/wiki/Dispatch_table) - Wikipedia overview of routing logic arrays.
* [42 Norm V4](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf) - The strict coding standard for 42 C projects.

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All C functions were built manually to strictly comply with the 42 Norm and deeply understand manual memory manipulation, enforcing the concept that learning is about developing the ability to find an answer, not just getting one directly.
* **Documentation:** AI tools were utilized to structure this `README.md` and format the logic breakdowns to create a clean, accessible educational resource for fellow 42 students.
