#include <iostream>
#include <string>
using namespace std;
void countlowercase(char word[],int n) {
    int count=0;
    for(int i=0;i<n;i++) {
        if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u') {
            count++;
        }
    }
    cout<<"Number of lowercase letters: "<<count<<endl;
}
//Question2:Youaregiventwostringss1ands2ofequallength.Astringswapisanoperationwhereyouchoosetwoindicesinastring(notnecessarilydifferent)andswapthecharactersattheseindices.Returntrueifitispossibletomakebothstringsequalbyperformingatmostonestringswaponexactlyoneofthestrings.Otherwise,returnfalse.Example:Input:s1="bank",s2="kanb"Output:trueExplanation:Forexample,swapthefirstcharacterwiththelastcharacterofs2tomake"bank".
bool arrcheckswap(string string1,string string2){
    int i;
    int diff=0;
    char diffchar1, diffchar2;
    if(string1.length()!=string2.length()){
        return false;
    }
    else{
        if(!diff) {
            diffchar1=string1[i];
            diffchar2=string2[i];
        }
        else {
            if( diffchar1!=string2[i] &&  diffchar2!=string2[i]){
                return true;
            }
        }
        diff++;
        
    }
    if(diff>2){
        return false;
    }
    if(diff==1){
        return false;
    }
    return true;
}
/*## Dry Run of Their Solution

```
s1 = "bank"
s2 = "kanb"
diff = 0, diffChar1 = ?, diffChar2 = ?
```

---

**i = 0:**
```
s1[0] = 'b'  s2[0] = 'k'  → different!
!diff = !0 = true → save characters
diffChar1 = 'b'
diffChar2 = 'k'
diff++ → diff = 1
diff > 2? No, continue
```

---

**i = 1:**
```
s1[1] = 'a'  s2[1] = 'a'  → same, skip
diff = 1
diff > 2? No, continue
```

---

**i = 2:**
```
s1[2] = 'n'  s2[2] = 'n'  → same, skip
diff = 1
diff > 2? No, continue
```

---

**i = 3:**
```
s1[3] = 'k'  s2[3] = 'b'  → different!
!diff = !1 = false → go to else
check: s1[3] != diffChar2 || s2[3] != diffChar1
       'k'  != 'k'        || 'b'  != 'b'
        false              ||  false
        → false! so DON'T return false ✅
diff++ → diff = 2
diff > 2? No, continue
```

---

**Loop ends:**
```
diff == 1? No (diff is 2)
return true ✅
```

---

## Summary Table

| i | s1[i] | s2[i] | diff | action |
|---|---|---|---|---|
| 0 | b | k | 0→1 | save diffChar1='b', diffChar2='k' |
| 1 | a | a | 1 | skip |
| 2 | n | n | 1 | skip |
| 3 | k | b | 1→2 | cross check passed ✅ |

**Final answer → `true` ✅***/

