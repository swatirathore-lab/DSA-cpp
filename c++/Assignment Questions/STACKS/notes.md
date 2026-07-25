## Stack — Next Greater Element (Monotonic Stack)

### Why a separate stack instead of popping from arr?
- `arr` = input data, still needed for reading via arr[i]
- `s` (stack) = helper holding "candidates" that could be next-greater for future elements
- Two different jobs — can't destroy arr while still scanning it

### Core idea
- Traverse RIGHT to LEFT
- Last element always has no next greater → ans[last] = -1
- For each arr[i]: pop stack while top <= arr[i] (those elements are "dead" — arr[i] blocks them from ever being anyone's next-greater)
- After popping, if stack empty → ans[i] = -1, else ans[i] = stack top
- Push arr[i] onto stack (it's now a candidate for elements further left)

### Why right to left?
- We need "next greater to the right" — so by processing right to left, 
  everything already in the stack represents valid future candidates
  for the current element

### Time complexity
- O(n), NOT O(n²)
- Each element is pushed once and popped at most once → max 2n operations total

### Dry run: arr = {6,8,0,1,3}
i=4: ans[4]=-1, push 3        → s=[3]
i=3: top=3, not<=1 → ans[3]=3, push 1   → s=[3,1]
i=2: top=1, not<=0 → ans[2]=1, push 0   → s=[3,1,0]
i=1: pop 0,1,3 (all <=8) → empty → ans[1]=-1, push 8  → s=[8]
i=0: top=8, not<=6 → ans[0]=8, push 6   → s=[8,6]

Result: ans = [8, -1, 1, 3, -1]

### Bug to remember: pass by value vs reference
- void nextgreater(vector<int> arr, vector<int> ans) → BOTH copied
- Changes to `ans` inside function do NOT reflect in main's `ans`
- Works only because print happens INSIDE the function (using local copy)
- If ans is checked in main() after the call → shows unchanged {0,0,0,0,0} — silent bug

### Rule: reference vs value
- Need to MODIFY caller's variable → pass by reference (T&)
- Only READING large data (vector/string) → pass by const reference (const T&)
- Only READING small primitive (int/char/bool) → pass by value is fine
- Gut check: "Does caller need to see the change after function returns?" → yes = reference