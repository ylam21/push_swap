# push_swap

This project is part of the **42 Prague curriculum**.<br>
The goal of **push_swap** is to sort a stack of integers with the smallest possible number of operations, using only a limited set of stack instructions.<br>
It is one of the key algorithmic projects at 42, teaching sorting algorithms, data structures, and optimization strategies.<br>
I implemented **Radix Sort Algorithm**.<br>

## 📦 Compilation

Build the program with:
```sh
make
```

## 🧹 Makefile Rules

```make``` – Compile the library<br>

```make clean``` – Remove object files (.o)<br>

```make fclean``` – Remove object files and the compiled library (libft.a)<br>

```make re``` – Recompile everything (equivalent to fclean + make)<br>
## 🚀 Usage

The program takes a list of integers as arguments and outputs the sequence of operations needed to sort them:
```sh
./push_swap 4 67 3 87 23
```
or
```sh
./push_swap "4 67 3 87 23"
```

Example output:

pb<br>
ra<br>
pb<br>
sa<br>
pa<br>
pa<br>

The output operations can be piped into the official checker program to validate correctness.

If the input is already sorted, no instructions are printed.
## 📑 Allowed Operations

The following instructions must be used to sort the stack:

**Swap**

sa : swap the first 2 elements at the top of stack a

sb : swap the first 2 elements at the top of stack b

ss : sa and sb at the same time

**Push**

pa : take the first element from b and push it onto a

pb : take the first element from a and push it onto b

**Rotate**

ra : shift all elements of stack a up by 1

rb : shift all elements of stack b up by 1

rr : ra and rb at the same time

**Reverse rotate**

rra : shift all elements of stack a down by 1

rrb : shift all elements of stack b down by 1

rrr : rra and rrb at the same

## ⚙️ Notes

Input validation must handle errors (non-integers, duplicates, overflow, underflow).

Efficiency is graded: fewer instructions = higher score.
