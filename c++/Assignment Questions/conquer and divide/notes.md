## `push_back` in vectors

`push_back` appends an element to the **end** of a vector, and automatically increases its size by 1.

```cpp
vector<int> temp;
temp.push_back(5);   // temp = [5]
temp.push_back(3);   // temp = [5, 3]
temp.push_back(8);   // temp = [5, 3, 8]
```

No need to track index or size manually — the vector handles it.

---

**Why `k` became useless here:**

If you had used a plain array instead of a vector, you'd write:
```cpp
int temp[100];
temp[k++] = arr[i++];  // k needed to track where to insert
```

But with `push_back`, the vector always knows where the next element goes (at the end), so `k` has no role.

---

**One thing to keep in mind:** `push_back` can be slightly slower in rare cases because the vector may need to **reallocate memory** as it grows. In competitive programming this usually doesn't matter, but if you know the size in advance, you can do:

```cpp
vector<int> temp;
temp.reserve(ei - si + 1);  // pre-allocates memory, avoids reallocations
```

This is a small optimization worth knowing for merge sort specifically since you always know the size of the subarray being merged.




and why temp[i-si]
Good question. Think about it this way:

`temp` always starts at index `0`, but the subarray you're sorting lives somewhere in the middle of `arr`.

**Example:** say `si=3, ei=6`

```
arr  : [_, _, _, 5, 2, 8, 1, _, _]
                 ^           ^
                si=3        ei=6

temp : [2, 5, 1, 8]   ← always starts at index 0
```

When copying back, you loop `i` from `si` to `ei` (i.e. 3 to 6), so you need to map that back to temp's 0-based index:

```
i=3  →  temp[3-3] = temp[0]
i=4  →  temp[4-3] = temp[1]
i=5  →  temp[5-3] = temp[2]
i=6  →  temp[6-3] = temp[3]
```

If you just wrote `temp[i]`, you'd be accessing `temp[3], temp[4]...` which is wrong — temp only has indices 0 to 3.

So `i - si` is just **shifting the index back to 0** to match how temp is stored.


is arr the larger array i mean are'nt we just sorting the elements of array and keeping them in sorted way in temp then just keeping back in array then how array is somehow bigger shit
Yes you're right, `arr` IS the same array throughout — merge sort doesn't create a new array.

The confusion is just about **which portion** of `arr` you're working on at any given moment.

```
arr = [7, 3, 5, 2, 8, 1, 4, 6]
       0  1  2  3  4  5  6  7
```

When mergesort recurses down, it keeps passing the **same `arr`** but with different `si` and `ei` values — so each call only "sees" a slice of it.

For example when `si=2, ei=5`:
```
arr = [7, 3, | 5, 2, 8, 1, | 4, 6]
                ^           ^
              si=2         ei=5
```
Only this portion is being merged. The rest of `arr` exists but this call doesn't touch it.

So when you copy `temp` back into `arr[si]` to `arr[ei]`, you're writing the sorted version back into **that exact slice** of the original array — not the whole thing.

That's why `i - si` matters — `arr` is big, `temp` only covers the slice, so you need that offset to align them correctly.

**Summary:**
- `arr` = full original array, never changes
- `temp` = scratch space for just the current slice being merged
- after merge, sorted slice goes back into the right position in `arr`




question 2
Very close! Just two small mistakes:

**1. `i<=n` should be `i<n`**
- same issue as before, `<=n` goes out of bounds

**2. `count>=n/2` should be `count>n/2`**
- majority means **more than** n/2, not equal to
- e.g. n=4, n/2=2, majority element must appear more than 2 times (3+), not 2

**3. return type is `void` but you're returning `element`**
- change to `int`

Fixed:
```cpp
int majorityelement(int arr[], int n) {
    int element;
    int count;
    for(int i=0; i<n; i++){
        element = arr[i];
        count = 0;
        for(int j=0; j<n; j++){
            if(arr[j]==element){
                count++;
            }
        }
        if(count > n/2){
            return element;
        }
    }
    return -1; // no majority element found
}
```

Also `candidate` variable was declared but never used — removed it.




question3
Okay Q1 and Q2 are done. Only Q3 remains — inversion count.

Before jumping to code, do you understand what an inversion is? Look at the example:

```
arr = {2, 4, 1, 3, 5}
```
Inversions are pairs where a bigger number appears **before** a smaller one:
- (2,1) → 2 is before 1, and 2>1 ✓
- (4,1) → 4 is before 1, and 4>1 ✓
- (4,3) → 4 is before 3, and 4>3 ✓

Do you want to try brute force first (two nested loops) or jump straight to the merge sort based approach since the hint says sorting?




Here are notes for both methods:

---

## Question 3: Inversion Count

**Definition:** A pair (i,j) is an inversion if `i<j` and `arr[i]>arr[j]`. Inversion count tells how far an array is from being sorted.

---

### Method 1: Brute Force — O(n²)

**Approach:** Check every pair (i,j) where j>i. If arr[i]>arr[j], count it.

```cpp
int inversioncount(int arr[], int n){
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}
```

---

### Method 2: Merge Sort — O(n log n)

**Key Insight:** During the merge step, both halves are already sorted. If `arr[i]>arr[j]`, then **all elements from i to mid** are also greater than `arr[j]` — so count `mid-i+1` inversions at once instead of one by one.

```cpp
int merge(int arr[], int si, int mid, int ei){
    vector<int> temp;
    int i=si, j=mid+1, count=0;

    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        } else {
            count += (mid-i+1);  // all remaining left elements > arr[j]
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=ei)  temp.push_back(arr[j++]);
    for(int i=si; i<=ei; i++) arr[i]=temp[i-si];
    return count;
}

int mergesort(int arr[], int si, int ei){
    if(si>=ei) return 0;
    int mid=(si+ei)/2;
    int count=0;
    count += mergesort(arr,si,mid);
    count += mergesort(arr,mid+1,ei);
    count += merge(arr,si,mid,ei);
    return count;
}
```

**Why merge sort works here:** inversions can only happen between left and right halves during merge — within each half they're already counted recursively.

---

**Test cases:**
```
{2,4,1,3,5} → 3  (pairs: (2,1),(4,1),(4,3))
{2,3,4,5,6} → 0  (already sorted)
{5,5,5}     → 0  (equal elements don't count)
```