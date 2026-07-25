question 1:-
int x;
int *ptr;
x = 7;
ptr = &x;
cout << *ptr;
solution 1:-
7 will be the output
question 2:-
void multipleBy2(int &a, int &b, int &c) {
    a *= 2;
    b *= 2;
    c *= 2;
}

int main() {
    int x = 1, y = 2, z = 3;
    multipleBy2(x, y, z);
    cout << x << y << z << "\n";
    return 0;
}
solution 2:-
246
question 3:-
int a = 32;
int *ptr = &a;

char ch = 'A';
char &cho = ch;

cho += a;
*ptr += ch;
cout << a << ", " << ch << endl;
solution 3:-
**Output: `129, a`**

Step by step:

1. `a = 32`, `ptr = &a`
2. `ch = 'A'` (ASCII value 65), `cho` is a reference to `ch` — so `cho` and `ch` are literally the same variable, just two names.
3. `cho += a;` → `ch = ch + a = 65 + 32 = 97` → ASCII 97 is `'a'`, so `ch` becomes `'a'`.
4. `*ptr += ch;` → this means `a += ch` (since `ptr` points to `a`) → `a = 32 + 97 = 129` (ch's value 97 is used numerically here).
5. `cout << a << ", " << ch << endl;` → prints `a` as integer `129`, and `ch` as character `'a'`.

**Final output:**
```
129, a
```

Key concept: reference (`&cho`) is just an alias, no separate memory — changing `cho` changes `ch` directly. And when a `char` is used in arithmetic, C++ auto-converts it to its ASCII integer value.
question 4:-
what is dangling pointer
solution 4:-
Dangling pointer wo pointer hota hai jo kisi aisi memory location ko point kar raha ho jo ab valid/exist nahi karti — yani wo memory free ho chuki hai ya destroy ho chuki hai, lekin pointer abhi bhi uska purana address hold kar raha hai.
