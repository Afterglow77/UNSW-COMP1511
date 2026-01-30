# COMP1511 Week 1 Reflection: C Programming Basics

## 1. Data Types & Memory
* **Memory Allocation**: Variables occupy a fixed number of bits in RAM regardless of the value stored.
    * `int`: 32 bits (4 bytes), range from approx. -2.1B to 2.1B.
    * `char`: 8 bits (1 byte), used for small integers or ASCII characters.
    * `double`: 64 bits (8 bytes), used for precise floating-point numbers.
* **Binary Concept**: Computers store everything as bits (0s and 1s). Learned about custom binary mapping (e.g., A=00000).

## 2. Compilation & Tools
* **Tools**: Used `dcc` (UNSW wrapper) and `clang`. `dcc` provides more helpful explanations for beginners.
* **Fatal Mistake**: Never use the source filename as the output name (e.g., `clang var.c -o var.c`), as it overwrites the code with binary data.
* **Files**: Compilation produces the executable and a `.dSYM` folder for debugging.

## 3. Common Pitfalls & Lessons
* **Initialization**: Always initialize variables (e.g., `int age = 0;`). Uninitialized variables contain "garbage values" from memory leftovers.
* **`scanf` Rule**: Always use the `&` (address-of) operator for `scanf` (e.g., `scanf("%d", &age);`) to avoid memory crashes (Segmentation Faults).
* **Workflow**: Remember to **Save (Cmd+S)** the file in VS Code before compiling, otherwise the compiler runs the old version.
* **Formatting**: Use `\n` in `printf` to ensure clean terminal output and avoid the trailing `%` sign.