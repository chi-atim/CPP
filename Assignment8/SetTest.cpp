/**
** Program Name: Set
** Purpose: Implement an Abstract Data Type “set” and see the running time complexity of an ADT
** Author: Chiemi Mita
** Limitation: No known limitations
*/

#include "Set.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "***** Provided tests *****" << endl;

    Set s, t;
    cout << "empty set: " << s << "\n";
    cout << "\texpecting: { }\n";
    cout << "|s|=" << s.size()<< "\n";
    cout << "\texpecting:|s|= 0\n";
    s.insert(3);
    s.insert(1);
    s.insert(9);
    s.insert(3);
    s.insert(7);
    s.insert(5);
    cout << "s = " << s << "\n";
    cout << "\texpecting: s = { 1 3 5 7 9 }\n";
    if (!s.member(2))
        cout << "2 is not in the set s as expected\n";
    else
        cout << "ERROR: 2 is in the set s\n";
    if (s.member(7))
        cout << "7 is in the set s as expected\n";
    else
        cout << "ERROR: 7 is NOT in the set s\n";
    cout << "|s|=" << s.size()<< "\n";
    cout << "\texpecting:|s|= 5\n";
    s.remove(7);
    s.remove(1);
    s.remove(9);
    s.remove(10);
    cout << "\nafter the removals: s = " << s << "\n";
    cout << "\texpecting: s = { 3 5 }\n";
    s.insert(1);
    s.insert(7);
    s.insert(3);
    cout << "with insertions: s = " << s << "\n";
    cout << "\texpecting: s = { 1 3 5 7 }\n";
    t.insert(3);
    t.insert(5);
    t.insert(4);
    cout << "with insertions: t = "<< t << "\n";
    cout << "\texpecting: t = { 3 4 5 }\n";
    Set a = s + t;
    cout << "s union t = " << a << "\n";
    cout << "\texpecting: a = { 1 3 4 5 7 }\n";
    s.remove(3);
    t.remove(4);
    cout << "remove 3: s = " << s << "\n";
    cout << "\texpecting: s = { 1 5 7 }\n";
    cout << "remove 4: t = " << t << "\n";
    cout << "\texpecting: t = { 3 5 }\n";
    s.insert(3);
    t.insert(4);
    cout << "insert 3: s = " << s << "\n";
    cout << "\texpecting: s = { 1 3 5 7 }\n";
    cout << "insert 4: t = " << t << "\n";
    cout << "\texpecting: t = { 3 4 5 }\n";
    Set b = s * t;
    cout << "s cct t = " << b << "\n";
    cout << "\texpecting: b = { 3 5 }\n";
    cout << "s = " << s << "\n";
    cout << "\texpecting: s = { 1 3 5 7 }\n";
    cout << "t = " << t << "\n";
    cout << "\texpecting: t = { 3 4 5 }\n";

    cout << "\n***** Test copy constructor *****" << endl;
    Set copyS(s);
    cout << "copyS = " << copyS << "\n";
    cout << "\texpecting: copyS = { 1 3 5 7 }\n";
    copyS.insert(8);
    cout << "insert 8: copyS = " << copyS << "\n";
    cout << "\texpecting: copyS = { 1 3 5 7 8 }\n";
    cout << "s = " << s << "\n";
    cout << "\texpecting: s = { 1 3 5 7 }\n";

    cout << "***** Test assignment operator *****" << endl;
    Set copyT;
    copyT.insert(777);
    cout << "copyT = " << copyT << "\n";
    cout << "\texpecting: copyT = { 777 }\n";
    copyT = t;
    cout << "copyT = " << copyT << "\n";
    cout << "\texpecting: copyT = { 3 4 5 }\n";
    copyT.insert(6);
    cout << "insert 6: copyT = " << copyT << "\n";
    cout << "\texpecting: copyT = { 3 4 5 6 }\n";
    cout << "t = " << t << "\n";
    cout << "\texpecting: t = { 3 4 5 }\n";

    cout << "\n***** Tests for Bonus Marks *****" << endl;
    Set setP, setQ;
    setP.insert(2);
    setP.insert(3);
    setQ.insert(2);
    setQ.insert(3);
    setQ.insert(5);
    cout << "setP = " << setP << "\n";
    cout << "setQ = " << setQ << "\n";
    if (setP < setQ)
        cout << "setP is proper subset of setQ as expected\n";
    else
        cout << "ERROR: setP is NOT proper subset of setQ\n";
    setP.insert(5);
    cout << "setP = " << setP << "\n";
    cout << "setQ = " << setQ << "\n";
    if (setP < setQ)
        cout << "ERROR: setP is proper subset of setQ\n";
    else
        cout << "setP is NOT proper subset of setQ as expected\n";
    setP.remove(3);
    setP.remove(5);
    setQ.remove(2);
    setQ.remove(3);
    setQ.remove(5);
    cout << "setP = " << setP << "\n";
    cout << "setQ = " << setQ << "\n";
    if (setP < setQ)
        cout << "ERROR: setP is proper subset of setQ\n";
    else
        cout << "setP is NOT proper subset of setQ as expected\n";
    setP.remove(2);
    setQ.insert(2);
    cout << "setP = " << setP << "\n";
    cout << "setQ = " << setQ << "\n";
    if (setP < setQ)
        cout << "setP is proper subset of setQ as expected\n";
    else
        cout << "ERROR: setP is NOT proper subset of setQ\n";

    cout << "\n***** Additional Tests *****" << endl;
    Set set1, set2;
    set1.insert(0);
    set1.insert(-1);
    set1.insert(-1);
    set1.insert(99);
    set1.insert(-15);
    set1.insert(3);
    cout << "set1 = " << set1 << "\n";
    cout << "\texpecting: set1 = { -15 -1 0 3 99 }\n";
    cout << "size of set1 = " << set1.size()<< "\n";
    cout << "\texpecting: 5\n";
    set1.remove(99);
    cout << "remove 99: set1 = " << set1 << "\n";
    cout << "\texpecting: s = { -15 -1 0 3 }\n";
    cout << "size of set1 = " << set1.size()<< "\n";
    cout << "\texpecting: 4\n";
    cout << "size of set2 = " << set2.size()<< "\n";
    cout << "\texpecting: 0\n";
    set2.remove(4);
    cout << "remove 4: set2 = " << set2 << "\n";
    cout << "\texpecting: set2 = { }\n";

    if (set1.isEmpty())
        cout << "ERROR: set1 is empty\n";
    else
        cout << "set1 is NOT empty as expected\n";
    if (set2.isEmpty())
        cout << "set2 is empty as expected\n";
    else
        cout << "ERROR: set2 is NOT empty\n";

    if (set1.member(-15))
        cout << "-15 is in set1 as expected\n";
    else
        cout << "ERROR: -15 is NOT in set1\n";
    if (set2.member(0))
        cout << "ERROR: 0 is in set2\n";
    else
        cout << "0 is NOT in set2 as expected\n";

    Set setUnion12 = set1 + set2;
    cout << "set1 + set2 = " << setUnion12 << "\n";
    cout << "\texpecting: setUnion12 = { -15 -1 0 3 }\n";
    Set setInter12 = set1 * set2;
    cout << "set1 * set2 = " << setInter12 << "\n";
    cout << "\texpecting: setInter12 = { }\n";

    Set copySet2_a(set2);
    cout << "copySet2_a = " << copySet2_a << "\n";
    cout << "\texpecting: copySet2_a = { }\n";

    Set copySet2_b;
    copySet2_b.insert(7);
    copySet2_b.insert(2);
    cout << "copySet2_b = " << copySet2_b << "\n";
    copySet2_b = set2;
    cout << "After copySet2_b = set2: = " << copySet2_b << "\n";
    cout << "\texpecting: copySet2_b = { }\n";

    return 0;
}
/* Outputs
***** Provided tests *****
empty set: { }
        expecting: { }
|s|=0
        expecting:|s|= 0
s = { 1 3 5 7 9 }
        expecting: s = { 1 3 5 7 9 }
2 is not in the set s as expected
7 is in the set s as expected
|s|=5
        expecting:|s|= 5

after the removals: s = { 3 5 }
        expecting: s = { 3 5 }
with insertions: s = { 1 3 5 7 }
        expecting: s = { 1 3 5 7 }
with insertions: t = { 3 4 5 }
        expecting: t = { 3 4 5 }
s union t = { 1 3 4 5 7 }
        expecting: a = { 1 3 4 5 7 }
remove 3: s = { 1 5 7 }
        expecting: s = { 1 5 7 }
remove 4: t = { 3 5 }
        expecting: t = { 3 5 }
insert 3: s = { 1 3 5 7 }
        expecting: s = { 1 3 5 7 }
insert 4: t = { 3 4 5 }
        expecting: t = { 3 4 5 }
s cct t = { 3 5 }
        expecting: b = { 3 5 }
s = { 1 3 5 7 }
        expecting: s = { 1 3 5 7 }
t = { 3 4 5 }
        expecting: t = { 3 4 5 }

***** Test copy constructor *****
copyS = { 1 3 5 7 }
        expecting: copyS = { 1 3 5 7 }
insert 8: copyS = { 1 3 5 7 8 }
        expecting: copyS = { 1 3 5 7 8 }
s = { 1 3 5 7 }
        expecting: s = { 1 3 5 7 }
***** Test assignment operator *****
copyT = { 777 }
        expecting: copyT = { 777 }
copyT = { 3 4 5 }
        expecting: copyT = { 3 4 5 }
insert 6: copyT = { 3 4 5 6 }
        expecting: copyT = { 3 4 5 6 }
t = { 3 4 5 }
        expecting: t = { 3 4 5 }

***** Tests for Bonus Marks *****
setP = { 2 3 }
setQ = { 2 3 5 }
setP is proper subset of setQ as expected
setP = { 2 3 5 }
setQ = { 2 3 5 }
setP is NOT proper subset of setQ as expected
setP = { 2 }
setQ = { }
setP is NOT proper subset of setQ as expected
setP = { }
setQ = { 2 }
setP is proper subset of setQ as expected

***** Additional Tests *****
set1 = { -15 -1 0 3 99 }
        expecting: set1 = { -15 -1 0 3 99 }
size of set1 = 5
        expecting: 5
remove 99: set1 = { -15 -1 0 3 }
        expecting: s = { -15 -1 0 3 }
size of set1 = 4
        expecting: 4
size of set2 = 0
        expecting: 0
remove 4: set2 = { }
        expecting: set2 = { }
set1 is NOT empty as expected
set2 is empty as expected
-15 is in set1 as expected
0 is NOT in set2 as expected
set1 + set2 = { -15 -1 0 3 }
        expecting: setUnion12 = { -15 -1 0 3 }
set1 * set2 = { }
        expecting: setInter12 = { }
copySet2_a = { }
        expecting: copySet2_a = { }
copySet2_b = { 2 7 }
After copySet2_b = set2: = { }
        expecting: copySet2_b = { }
*/
