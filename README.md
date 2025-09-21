# 🔄 Push Swap – 42 Project

Push Swap is a sorting algorithm project where the goal is to **sort a stack of integers** using a very limited set of stack operations. The challenge is not only to sort correctly but also to **find the most efficient sequence of moves**.

## 📝 Project Overview

* Two stacks: **A** (initial stack with random integers) and **B** (empty).
* Allowed operations: `sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, etc.
* The program `push_swap` outputs a sequence of these instructions that sorts stack A in ascending order.
* The evaluation checks **correctness** (is stack A sorted?) and **performance** (did you use few moves?).

## ⚙️ How to Use

### 1. Compile the program

```bash
make
```

### 2. Run with a list of numbers

```bash
./push_swap 4 67 3 87 23
```

It will output a sequence of operations, e.g.:

```
pb
pb
sa
ra
pa
pa
```

### 3. (Optional) Check with the provided checker program

```bash
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

If the stack ends up sorted, the checker prints:

```
OK
```

## 🎯 Example

```bash
$ ./push_swap 2 1 3
sa
```

## 📚 Skills Practiced

* Data structures (stacks, linked lists)
* Sorting algorithms and complexity
* Algorithmic optimization
* Writing efficient and maintainable C code

---

✨ Push Swap is more than sorting — it’s about designing an algorithm that balances **simplicity, efficiency, and correctness**.
