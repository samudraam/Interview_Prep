# Interview Prep

A collection of C++ solutions and notes for common coding interview problems, organized by topic.


### Google Docs notes
**Document:** [Cracking the Interview](https://docs.google.com/document/d/1M8su2bPD2Yx9kSV9dwq1l3wsuRuLdHrt2B9Q9QIFJgI/edit?usp=sharing)

### Textbook
[Mastering Algorithms for Problem Solving in C++](https://www.educative.io/courses/mastering-algorithms-for-problem-solving-in-cpp)

## Topics Covered

### 1. Two Pointers — Two Sum II (Sorted Array)
**File:** [2Sum/2sum.cpp](2Sum/2sum.cpp)
**Problem:** [LeetCode 167 — Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

Given a 1-indexed array sorted in non-decreasing order, find two numbers that add up to a target and return their (1-indexed) positions.

**Approach:**
- Use two pointers, `left` starting at index 0 and `right` at the last index.
- If `numbers[left] + numbers[right] == target`, return `[left + 1, right + 1]` (1-indexed).
- If the sum is too small, move `left` up; if too large, move `right` down.

> Note: currently returns 0-indexed positions (`left`, `right`) instead of the required 1-indexed `[left + 1, right + 1]` — needs a small fix.

### 2. Prefix Sum + Hash Map — Subarray Sum Equals K
**File:** [arrays/subarraySum/SubSum.cpp](arrays/subarraySum/SubSum.cpp)
**Problem:** [LeetCode 560 — Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)

Given an array of integers and an integer `k`, count the number of contiguous subarrays whose sum equals `k`.

**Approach:**
- Maintain a running `prefix` sum while scanning the array.
- Use an `unordered_map<int,int>` to track how many times each prefix sum has occurred (`map[0] = 1` accounts for a subarray starting at index 0).
- At each step, check whether `prefix - k` has been seen before — if so, that many subarrays ending at the current index sum to `k`.
- Includes debug `cout` statements that trace `prefix`, `need`, and map state for each element — useful for walking through the algorithm by hand.

See also: [reading/Subarrays_cheatsheet.jpg](reading/Subarrays_cheatsheet.jpg) — a visual cheat sheet on subarray techniques.

### 3. Doubly Linked Lists
**File:** [linked_lists/LinkedList.cpp](linked_lists/LinkedList.cpp)

Notes/scaffolding for building a doubly linked list (`node` struct with `data`, `next`, `prev`).

> Status: **work in progress / not yet compiling** — `createNode` and `main` have incomplete pointer logic (nodes are declared but never allocated with `new`, and `addNodesToList` is called with uninitialized pointers). Next steps: allocate nodes with `new node{...}`, implement insertion at head/tail, and fix `createNode` to actually return or link the node it creates.

## How to Run

Each problem is a self-contained `.cpp` file with its own `main()`. Compile and run any file with `g++`:

```bash
g++ <file>.cpp -o <output_name> && ./<output_name>
```

**Examples:**

```bash
# Two Sum II
g++ 2Sum/2sum.cpp -o 2sum && ./2sum

# Subarray Sum Equals K
g++ arrays/subarraySum/SubSum.cpp -o subsum && ./subsum

# Linked List (currently has compile errors — see note above)
g++ linked_lists/LinkedList.cpp -o linkedlist && ./linkedlist
```

**Command breakdown:**
| Part | Meaning |
|---|---|
| `g++ <file>.cpp` | Invokes the C++ compiler on the source file. |
| `-o <output_name>` | Names the generated executable instead of the default `a.out`. |
| `&&` | Chains commands — only runs the next command if compilation succeeds. |
| `./<output_name>` | Executes the compiled binary. |

### Alternative: VS Code Build Task
This repo includes a [.vscode/tasks.json](.vscode/tasks.json) task ("C/C++: clang build active file") that builds whichever `.cpp` file is currently open in the editor using `clang`. Run it via **Terminal → Run Build Task** (`Cmd+Shift+B` on macOS), or use the built-in VS Code C++ debugger.

## Repository Structure

```
Interview_Prep/
├── 2Sum/
│   └── 2sum.cpp              # Two Sum II (two-pointer solution)
├── arrays/
│   └── subarraySum/
│       └── SubSum.cpp        # Subarray Sum Equals K (prefix sum + hash map)
├── linked_lists/
│   └── LinkedList.cpp        # Doubly linked list (WIP)
├── reading/
│   └── Subarrays_cheatsheet.jpg
└── .vscode/
    └── tasks.json            # clang build task for the active file
```

## Requirements
- A C++ compiler: `g++` or `clang` (either works — see build options above).
- No external dependencies; all solutions use the C++ Standard Library (`<iostream>`, `<vector>`, `<unordered_map>`).
