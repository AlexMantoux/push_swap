*This project has been created as part of the 42 curriculum by amantoux, rtrutall*

# Push_swap

## Description

Push_swap is a project designed to introduce students to **algorithmic complexity**, **sorting algorithms**, and **stack manipulation**. It marks the first **group project** in the 42 curriculum.

The goal of this project is to sort a stack of integers using a limited set of predefined operations, in the fewest moves possible. To achieve this, students must design and implement differents efficient algorithms that works with two stacks — stack A and stack B — using only operations such as `push`, `swap`, `rotate`, and `reverse rotate`.

## Instructions

- `make` to compile the project
- `./push_swap` `flags` `stack` to execute. (flags aren't necessary)

- Flags could be :

    `--simple` force to use simple algorithm (selection-sort)

    `--medium` force to use medium algorithm (chunk-based-sort)

    `--complex` force to use medium algorithm (radix-sort)

    `--adaptive` Forces the use of our adaptive algorithm based on disorder. Disorder compute how shuffle/disorder the stack is.

    `--bench` active benchmark mode with some useful informations (disorder, stategy name, number of operations, count of each operations)

## Algorithm choices

In the `push_swap` project, efficiency is measured not just by theoretical complexity, but by the **total number of operations** (`ra`, `pb`, `sa`, etc.) required to sort the stack. My implementation uses a multi-tiered approach, selecting the most efficient algorithm based on the stack size.

### Simple Strategy: Selection Sort & Hard-coded Cases
* **Complexity:** $O(n^2)$
* **Justification:** For very small datasets, the overhead of complex partitioning exceeds the cost of simple selection. 
    * **3 Elements:** A specific "state-machine" approach sorts any permutation in a maximum of 2 or 3 moves.
    * **4-5 Elements:** The algorithm identifies the smallest elements, pushes them to Stack B, sorts the remaining 3, and then pushes back to A.

### Medium Strategy: Chunk-based Sorting
* **Complexity:** $O(n \sqrt{n})$
* **Justification:** This is the core logic for the 100-number test. It balances low instruction counts with a predictable logic.
    * **Phase 1 (A to B):** The stack is divided into "chunks" based on a range proportional to $\sqrt{n}$. By pushing elements into B based on their index relative to the current chunk, we create a pre-sorted "hourglass" shape. Using a conditional rotation (`rb`), smaller indices are sent to the bottom of B and larger ones stay at the top.
    * **Phase 2 (B to A):** We identify the maximum element in B and move it to the top using the **shortest path** (comparing its position to the midpoint to choose between `rb` or `rrb`).

### Complex Strategy: Radix Sort
* **Complexity:** $O(n \log{n})$ (where $k$ is the number of bits)
* **Justification:** Radix sort is a non-comparative algorithm. By treating the pre-indexed values as binary strings, we sort the stack bit by bit. 
    * **Advantage:** It offers a highly stable number of moves, ensuring we never exceed the maximum threshold for large sets, even with the most difficult permutations.

### Adaptive Strategy: The "Disorder Index"
To achieve the highest score, the program does not blindly apply an algorithm based solely on size. It performs a **pre-sort analysis** to evaluate the state of the data:

* **Sorted Check:** If the stack is already sorted, the program exits immediately ($O(n)$).
* **Inversion Counting:** The program calculates a "disorder index" based on the number of inversions.
    * **Low Disorder:** If the stack is "nearly sorted," a modified Chunk-based approach with a larger range is used to minimize swaps.
    * **High Disorder:** The program defaults to the **Chunk Sort** (optimized with a dynamic range) or **Radix Sort** to guarantee a score within the project's "5-point" rubric.

## Resources

* **[Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)**: An incredible tool that allows you to see your algorithm in real-time. It helps in understanding how chunks are formed and moved.
* **[Complexity Analysis (Big O)](https://www.bigocheatsheet.com/)**: A quick reference to understand the efficiency of the different algorithms.
* **[Binary and Radix Sort](https://www.geeksforgeeks.org/radix-sort/)**: A good read if you plan to implement Radix for the 500+ elements case.

<h2 align="center">Educational use only</h2>
<p align="center">Please do not copy this code for assessed work in 42 or other courses.</p>
<p align="center">Use this repository for study and reference only.</p>