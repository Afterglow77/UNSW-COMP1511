# COMP1511 Week 03 Lab - Core Breakthroughs in Loops and Structures

## Week 03 Reflections
This week's focus shifted from **linear sequential logic** to **complex structures and multi-dimensional loop control**. I learned about member access in C structures (`struct`), pattern rendering via nested loops, and leveraging modular arithmetic (`%`) to handle wrap-around boundaries. Additionally, I explored utilizing the input buffer's queue characteristics for dynamic data handling (avoiding unnecessary arrays) and grid printing via double loops.

---

## 📂 Exercise Summary

| Exercise File | Core Concepts | Key Logic & Pitfalls Recorded |
| :--- | :--- | :--- |
| `count_up_down.c` | Basic Loop Control | Handled bidirectional boundary conditions for both incrementing and decrementing loops. |
| `debug_factorial.c` | Code Debugging | Traced loop counters to identify and fix logical bugs in factorial computations. |
| `print_grid.c` | 2D Coordinate System | Established the concepts of `row` and `col` tracking, utilizing nested loops to print planar graphics. |
| `vector_sum.c` | Structures (`struct`) | **Cannot directly assign values to independent components `x, y, z`**. They are inner variables encapsulated within the `sum_vector` struct and must be accessed via the dot operator `.` (e.g., `sum_vector.x`). |
| `custom_cake.c` | Buffering + Nested Loops | **Core Approach: On-the-fly rendering**. Bypassed the need for arrays. Placed `scanf` inside the outer loop to leverage the input buffer queue, fetching a new character for each layer and printing it horizontally `number` times using the inner loop. |
| `letters_between.c` | Circular Algorithm | **Personal Approach & Reflection**: I initially converted letters into ASCII numerical indexes to simplify the core comparison logic. Although the nested conditionals became quite complex (and there might be room for optimization), it successfully got the job done. I then introduced a dynamic baseline `base` (automatically detecting uppercase `'A'` or lowercase `'a'`) to map characters into a clean `0-25` integer ring via subtraction (`letter - base`), making circular distance calculation and direction comparison significantly easier. |

---

## 🧠 Common Pitfalls & Key Takeaways

### 1. Struct Usage & Member Access (`vector_sum.c`)
In C, declaring a struct variable like `struct vector sum_vector;` is akin to creating a large capsule container named `sum_vector`. Its members `x`, `y`, and `z` act as dedicated inner compartments. When assigning values, you must explicitly specify the structural variable instance being accessed:

```c
sum_vector.x = first_vector.x + second_vector.x;