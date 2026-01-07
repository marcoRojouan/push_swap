*This project has been created as part of the 42 curriculum by mrojouan.*

# push_swap

## Description

**push_swap** is a 42 project whose goal is to sort a list of integers using two stacks (A and B) and a restricted set of operations. The program must output a sequence of operations that will sort the input stack in ascending order. The challenge is to design and implement an algorithm that minimizes the number of operations while respecting the project's constraints (allowed operations, input validation, and error handling).

This implementation uses the **radix** strategie to handle different input sizes efficiently.

## Features

- Full implementation of allowed operations:
  - `sa`, `sb`, `ss`
  - `pa`, `pb`
  - `ra`, `rb`, `rr`
  - `rra`, `rrb`, `rrr`
- Sorting strategies:
  - **Radix sort**: assigns an index to each value and sorts the stack using binary representation, pushing and rotating elements between stacks `a` and `b` based on bit comparison to minimize the number of operations.
- Robust input validation:
  - Detects non-numeric arguments, duplicates, and 32-bit integer overflow.
  - On invalid input prints `Error` and exits with a non-zero status.
- Designed with clarity and performance in mind (simple data structures, focused helper functions).

## Instructions

### Requirements

- A POSIX-compatible system (Linux / macOS).
- `gcc` (or a compatible C compiler).
- `make`.

### Compilation

A Makefile is provided. To build the project:

```bash
make
```

This will produce the executable:
push_swap

Common Makefile targets:

make — build the program.

make clean — remove object files.

make fclean — remove object files and the executable.

make re — fclean then make.

## Execution

Run push_swap with a series of integers as arguments:

```bash
./push_swap 3 2 5 1 4
```

The program prints a list of operations (one per line) which, when applied to the initial stack A, will result in a sorted stack.

Example output:
```bash
pb
sa
pa
ra
```
If the input is already sorted, the program prints nothing and exits with status 0.

On invalid input (duplicate values, non-integers, overflow, empty arguments), the program prints:

```bash
Error
```
and exits with a non-zero status.

## Algorithm & Technical choices

#### Data structures:
i used int arrays to simplify the sorting logic  and the making of allowed operations

```c
typedef struct s_stack
{
	int		*values;
	int		size;
}				t_stack;
```

#### Radix: 

Values are first indexed (from 0 to n - 1) according to their sorted order.
The algorithm then sorts stack A by processing each bit of the index, from least significant to most significant.

For each bit:

Elements with a 0 at the current bit are pushed to stack B

Elements with a 1 are rotated within stack A

Once all elements are processed, stack B is pushed back into A

This guarantees a sorted stack after processing all bits, with a predictable and efficient operation count.

### Usage examples

#### Small example:

```bash
./push_swap 2 1 3
```
Output:

```bash
sa
```

#### Bigger example:

```bash
./push_swap 8 3 7 1 6 2 5 4
```
Output:

```bash
ra
pb
pb
pb
ra
ra
pb
ra
...
```

## Resources

For Radix Documentation :
	- "https://www.geeksforgeeks.org/dsa/radix-sort/"
	- "https://en.wikipedia.org/wiki/Radix_sort"
For Parsing Documentation :
	- I used the experience i have in Web Development to parse users informations.

## Testing & Validation

To test leaks and multiple test at once and errors i used :
	- Nda-cunh's push-swap-tester "https://gitlab.com/nda-cunh/push_swap-testeur-max"
To visualize the number of operation step by step i used :
	- Nda-cunh's visualizer-push-swap "https://gitlab.com/nda-cunh/visualizer-push-swap"