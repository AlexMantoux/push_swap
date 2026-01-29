*This project has been created as part of the 42 curriculum by amantoux, rtrutall*

## Description

Push_swap is a project designed to introduce students to **algorithmic complexity**, **sorting algorithms**, and **stack manipulation**. It marks the first **group project** in the 42 curriculum.

The goal of this project is to sort a stack of integers using a limited set of predefined operations, in the fewest moves possible. To achieve this, students must design and implement differents efficient algorithms that works with two stacks — stack A and stack B — using only operations such as `push`, `swap`, `rotate`, and `reverse rotate`.

## Instructions

- `make` to compile the project
- `./push_swap` `flags` `stack` to execute. (flags aren't necessary)
- `norminette && make re && shuf -i 1-500 -n 100 > test.txt; valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $(cat test.txt) | ../../../Downloads/checker_linux $(cat test.txt) && make fclean && rm test.txt`

- Flags could be :

    `--simple` force to use simple algorithm (selection-sort)

    `--medium` force to use medium algorithm (chunk-based-sort)

    `--complex` force to use medium algorithm (radix-sort)

    `--adaptive` Forces the use of our adaptive algorithm based on disorder. Disorder compute how shuffle/disorder the stack is.

    `--bench` active benchmark mode with some useful informations (disorder, stategy name, number of operations, count of each operations)


## Contributions

**Amantoux**

- Stack operations
- Simple algorithm
- Medium algorithm
- Disorder
- benchmark mode
- Readme

**Rtrutall**
- Parsing of arguments
- Error gestion
- Flags gestion
- Complex algorithm
- benchmark mode
- useful functions for algorithms

## Resources

### References and Documentation
- [link](https://www.google.com/) — Loremmmmm

### IA

## Algorithm choices

- **SIMPLE**

- **MEDIUM**

- **COMPLEX**

### Use of AI
loremmwermewremwrwerewr IA

## Checker

``` bash 
echo "\n+++++++++++++ NORMINETTE +++++++++++++\n" && norminette && echo "\n+++++++++++++ COMPILE +++++++++++++\n" && make re && shuf -i 1-500 -n 100 > test.txt; echo "\n+++++++++++++ VALGRIND / EXEC +++++++++++++\n" && valgrind ./push_swap $(cat test.txt) && echo "\n+++++++++++++ CHECKER +++++++++++++\n" && echo "TEST -> \c"; ./push_swap $(cat test.txt) | ../../../Downloads/checker_linux $(cat test.txt) && echo "\n+++++++++++++ CLEAN UP +++++++++++++\n" && make fclean && rm test.txt
```
command that check norminette errors, compile project, generate list of different numbers in a file `test.txt` that will be used as an argument by `./push_swap` and `./checker_linux`. Valgrind, execute the project and clean up all.