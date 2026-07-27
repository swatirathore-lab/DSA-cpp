```markdown
## Contains Duplicate

**Problem:** Given an integer array `nums`, return `true` if any value appears at least twice, and `false` if every element is distinct.

**Examples:**
```
Input: nums = [1,2,3,1]        → Output: true
Input: nums = [1,2,3,4]        → Output: false
Input: nums = [1,1,1,3,3,4,3,2,4,2] → Output: true
```

**Constraints:**
- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---

### Approach 1: Brute Force
**Logic:** Har element ko baaki sab elements se compare karo (nested loop). Match mile toh `true`.

```cpp
bool containsDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}
```
- `j = i+1` se start hota hai taaki element khud se compare na ho.
- **Time:** O(n²) | **Space:** O(1)

---

### Approach 2: Sorting
**Logic:** Array sort karo → duplicates adjacent aa jayenge → consecutive elements compare karo.

```cpp
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i+1]) {
            return true;
        }
    }
    return false;
}
```
- Loop `size() - 1` tak jaata hai warna `nums[i+1]` out of bounds ho jayega.
- **Time:** O(n log n) | **Space:** O(1) (in-place sort)

---

### Approach 3: Hashing (unordered_set) — Most Efficient
**Logic:** Ek `unordered_set` banao. Har element insert karne se pehle check karo already present hai ya nahi.

```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    
    for (int i = 0; i < nums.size(); i++) {
        if (seen.count(nums[i]) > 0) {
            return true;
        }
        seen.insert(nums[i]);
    }
    return false;
}
```
- `seen.count(x)` → 0 agar absent, 1 agar present.
- `seen.insert(x)` → element ko set mein daal deta hai.
- **Time:** O(n) | **Space:** O(n)

---

### Comparison

| Approach | Time | Space |
|---|---|---|
| Brute Force | O(n²) | O(1) |
| Sorting | O(n log n) | O(1) |
| Hashing | O(n) | O(n) |

**Interview mein preferred:** Hashing (best time complexity trade-off).
```