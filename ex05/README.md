# 🟢 Exercise 05: do-op

## 📝 Objective
Create a program called `do-op` that takes three arguments (value1, operator, value2) and performs basic arithmetic.

## 💡 The Logic
This is a masterclass in using "Dispatch Tables" to avoid writing massive, ugly `if/else` logic trees.
1. **The Dispatch Table:** We create an array of function pointers `int (*calc[5])(int, int)` and map them to our arithmetic functions (`ft_add`, `ft_sub`, etc.).
2. **Dynamic Routing:** We define a string `type = "+-*/%"`. We iterate through this string; if the user's operator matches `type[i]`, we simply execute `calc[i](n1, n2)`!
3. **Edge Cases:** The program strictly prints `0` for invalid operators. It also intercepts `division by 0` and `modulo by 0`, printing their respective stop warnings instead of crashing.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:* **[`do_op.c`](do_op.c)** | **[`do_op_calc.c`](do_op_calc.c)**

2. **Testing:**
   Because this is a standalone executable, it does *not* use the `tester.c`. Compile it directly and pass arguments to it:
   ```bash
   cc -Wall -Wextra -Werror do_op.c do_op_calc.c -o do-op
   
   ./do-op 42 "+" 21
   ./do-op 25 "/" 0
   ./do-op 42 "p" 21
   ```
