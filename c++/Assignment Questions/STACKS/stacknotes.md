my teacher just said that she will use vector for stack operations because it do have dynamic sizing-----------make me understand the statement
ans:-
## Why use `vector` for Stack operations?

**Statement:** "Vector is used for stack operations because it has dynamic sizing."

### Explanation

- A **Stack** follows LIFO (Last In, First Out) — elements are pushed and popped from the top.
- To implement a stack, we need an underlying container to store elements. Options: plain **array** or **`std::vector`**.
- A plain array has a **fixed size**, decided at creation time:
  ```cpp
  int arr[100]; // fixed capacity of 100
  ```
  If the stack grows beyond 100 elements → overflow. We'd have to manually create a bigger array and copy all elements over.

- A **`vector`** has **dynamic sizing** — it automatically resizes itself when full:
  - Allocates a new, larger block of memory (usually double the old capacity)
  - Copies existing elements into it
  - Frees the old memory
  - Adds the new element
  
  All of this happens internally when we call `push_back()` — no manual resizing needed.

### Mapping Stack operations to Vector functions

| Stack Operation | Vector Equivalent |
|---|---|
| `push(x)`  | `vec.push_back(x)` |
| `pop()`    | `vec.pop_back()` |
| `top()`    | `vec.back()` |
| `isEmpty()`| `vec.empty()` |

- Both `push_back()` and `pop_back()` work at the **end** of the vector → O(1) amortized time complexity.
- This matches exactly what a stack needs (fast insert/delete at one end).

### Conclusion
`vector` is preferred over a plain array for stack implementation because:
1. No need to predefine a fixed size.
2. Automatically grows as more elements are pushed.
3. Provides efficient O(1) amortized operations at the end (push/pop), which aligns perfectly with stack behavior.