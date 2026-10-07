#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

/* =====================================================
   NOTES (quick recap)
   - Heap = Complete Binary Tree (CBT) -> sare levels full, last level left se right bharta hai
   - Max Heap: parent >= children | Min Heap: parent <= children
   - Priority Queue (PQ) heaps se bani hoti hai, by default MAX heap
   - Upar wala element (top) = highest priority
   - push() O(logn) | pop() O(logn) | top() O(1)
   ===================================================== */


/* =====================================================
   1) PQ IN STL
   ===================================================== */
void pqInSTL() {
    cout << "--- PQ in STL (max heap) ---" << endl;

    priority_queue<int> pq;   // by default MAX heap

    pq.push(3);               // O(logn)
    pq.push(10);
    pq.push(5);
    pq.push(7);
    pq.push(2);

    while (!pq.empty()) {
        cout << "top : " << pq.top() << endl;   // top() O(1) -> sabse bada
        pq.pop();                               // pop() O(logn)
    }
}

// Ye to maxheap ho gaya, ab minheap banayenge
void minHeapSTL() {
    cout << "--- PQ in STL (min heap) ---" << endl;

    // 3 cheezein: type, container (vector), comparator (greater)
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(3);
    pq.push(10);
    pq.push(5);
    pq.push(7);
    pq.push(2);

    while (!pq.empty()) {
        cout << "top : " << pq.top() << endl;   // ab sabse chota pehle aayega
        pq.pop();
    }
}

// Is wale me hum string input kar rahe (strings lexicographically compare hoti hain)
void pqStrings() {
    cout << "--- PQ with strings ---" << endl;

    priority_queue<string> pq;

    pq.push("hello");
    pq.push("apnacollege");
    pq.push("tick");
    pq.push("drake");

    while (!pq.empty()) {
        cout << "top : " << pq.top() << endl;
        pq.pop();
    }
}


/* =====================================================
   2) HEAP IMPLEMENTATION (class Heap) - MAX HEAP
   Heap ko class (node + pointers) ki jagah ARRAY/VECTOR me banate hain
   kyuki parent-child relation array me index se nikal sakte hain.

   0-based indexing (instructor ki preference):
     node at index i
       left child  = 2*i + 1
       right child = 2*i + 2
       parent      = (i - 1) / 2
   ===================================================== */
class Heap {
    vector<int> vec;

public:
    // ---------- PUSH IN HEAP ----------
    // Step 1: heap me insert (vec.push_back -> O(1))
    // Step 2: heap ko fix karo (O(logn))
    // NOTE: index compare hote hain, values nahi (swap values hoti hain)
    void push(int val) {
        // step 1: insert at end
        vec.push_back(val);

        // step 2: fix heap
        int x = vec.size() - 1;      // child index
        int parI = (x - 1) / 2;      // parent index

        // jab tak parent ke paas chhoti value hai tab tak swap karte raho
        while (parI >= 0 && vec[x] > vec[parI]) {   // MIN HEAP ke liye: '>' ko '<' kar do
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x - 1) / 2;
        }
    }

    // ---------- HEAPIFY ----------
    // i par jo value hai usse apni sahi jagah par pahuchata hai
    // worst case O(logn) -> isliye pop bhi O(logn)
    void heapify(int i) {
        // base case: khali heap (ya invalid index) ke liye return
        if (i >= vec.size()) {
            return;
        }

        int l = 2 * i + 1;           // left child
        int r = 2 * i + 2;           // right child

        // teeno (parent, left, right) me se max nikalo
        int maxI = i;
        if (l < vec.size() && vec[l] > vec[maxI]) {   // MIN HEAP: '>' -> '<' (aur maxI ko minI samjho)
            maxI = l;
        }
        if (r < vec.size() && vec[r] > vec[maxI]) {   // MIN HEAP: '>' -> '<'
            maxI = r;
        }

        swap(vec[i], vec[maxI]);

        // agar swap hua (child ke saath), to neeche wala bigad sakta hai
        // isliye recursion se aage fix karo
        if (maxI != i) {
            heapify(maxI);
        }
    }

    // ---------- POP IN HEAP ----------
    // Step 1: swap(root, last)
    // Step 2: last index delete -> vec.pop_back() O(1)
    // Step 3: heap fix -> heapify(0) O(logn)
    void pop() {
        if (vec.size() == 0) return;     // safety: empty heap me pop nahi

        // step 1
        swap(vec[0], vec[vec.size() - 1]);

        // step 2
        vec.pop_back();

        // step 3
        heapify(0);
    }

    // top() -> highest priority element, O(1)
    int top() {
        return vec[0];
    }

    // empty() -> agar vector ka size zero to heap empty
    bool empty() {
        return vec.size() == 0;
    }
};

void heapDemo() {
    cout << "--- Custom Heap (max heap) ---" << endl;

    Heap heap;
    heap.push(10);
    heap.push(50);
    heap.push(100);
    heap.push(5);

    cout << "top = " << heap.top() << endl;    // 100

    while (!heap.empty()) {
        cout << "top = " << heap.top() << endl;
        heap.pop();
    }
}


/* =====================================================
   3) PQ FOR OBJECTS
   Student class ke object ko PQ me daal sakte hain
   Error aayega kyuki compiler ko nahi pata kis cheez ke basis par
   heap banana hai -> iske liye OPERATOR OVERLOADING (operator <)
   ===================================================== */
class Student {
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    // Marks ke basis par kiya abhi (MAX heap by marks)
    // Name ke basis par bhi kar sakte: return this->name < obj.name;
    // MIN heap ke liye sign reverse: return this->marks > obj.marks;
    bool operator<(const Student &obj) const {
        return this->marks < obj.marks;
    }
};

void pqForObjects() {
    cout << "--- PQ for Objects ---" << endl;

    priority_queue<Student> pq;

    pq.push(Student("aman", 85));
    pq.push(Student("bhumika", 95));
    pq.push(Student("chetan", 93));

    while (!pq.empty()) {
        cout << "top : " << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop();
    }
}


/* =====================================================
   4) PQ FOR PAIRS
   Pair ke liye default comparison "first" par hota hai.
   Agar "second" par karna ho to apna struct (comparator) bana lo.
   ===================================================== */

// Default behaviour: pair<string,int> -> "first" (string) ke basis par max heap
void pqPairsDefault() {
    cout << "--- PQ for Pairs (default: first) ---" << endl;

    priority_queue<pair<string, int>> pq;

    pq.push(make_pair("aman", 500));
    pq.push(make_pair("bhumika", 1000));
    pq.push(make_pair("chetan", 2000));

    while (!pq.empty()) {
        cout << "top = " << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }
}

// Struct for the pair comparison (second ke basis par)
// (struct ka memory allocation stack me, heap memory allocation heap me hota hai)
struct ComparePair {
    bool operator()(pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second;     // MAX heap by second | MIN heap: '<' -> '>'
    }
};

void pqPairsCustom() {
    cout << "--- PQ for Pairs (custom: second) ---" << endl;

    // neeche priority queue banate time: type, phir vector pass karo, phir struct pass karo
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;

    pq.push(make_pair("aman", 500));
    pq.push(make_pair("bhumika", 1000));
    pq.push(make_pair("chetan", 2000));

    while (!pq.empty()) {
        cout << "top = " << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }
}


/* =====================================================
   MAIN - jo section chalana ho wo uncomment/comment kar lo
   ===================================================== */
int main() {
    pqInSTL();
    minHeapSTL();
    pqStrings();

    heapDemo();

    pqForObjects();

    pqPairsDefault();
    pqPairsCustom();

    return 0;
}