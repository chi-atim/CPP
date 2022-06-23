#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <sstream>
#include <cassert>
#include <vector>

using namespace std;

void printPrompt() {
   cerr << "\n--> ";
}

void printPrompt(string str) {
   printPrompt();
   cerr << str;
}

int main() {
   Node *p, *q;
   // the empty list
   q = nullptr;
   printPrompt("q = ");
   printList(q);
   cerr << "expecting [ ]\n";

   printPrompt("length(q) = ");
   cerr << length(q);
   cerr << "\nexpecting 0\n";

   p = cons(3, cons(2, nullptr));
   printPrompt("p = ");
   printList(p);
   cerr << "expecting [ 3 2 ]\n";

   printPrompt("length(p) = ");
   cerr << length(p);
   cerr << "\nexpecting 2\n";

   p = append(1, p);
   printPrompt("after append: ");
   printList(p);
   cerr << "expecting [ 3 2 1 ]\n";

   // append onto an empty list
   Node *t = append(1160, nullptr);
   printPrompt("after appending to an empty list: ");
   printList(t);
   cerr << "expecting [ 1160 ]\n";
   t = deleteList(t);

   p = reverse(p);
   printPrompt("after reverse: ");
   printList(p);
   cerr << "expecting [ 1 2 3 ]\n";

   // the reverse of the empty list is the empty list
   q = reverse(q);
   printPrompt("after reversing the empty list ");
   printList(q);
   cerr << "expecting [ ]\n";

   printPrompt();
   if (searchInOrder(3, p))
      cerr << "found 3 as expected\n";
   else
      cerr << "**************ERROR: did not find 3\n";

   printPrompt();
   if (searchInOrder(4, p))
      cerr << "**************ERROR: found 4\n";
   else
      cerr << "did not find 4 as expected\n";

   // search for 4 in the empty list q
   printPrompt();
   if (searchInOrder(4, q))
      cerr << "**************ERROR: found 4\n";
   else
      cerr << "did not find 4 in the empty list as expected\n";

   // q is still assigned to the nullptr
   printPrompt();
   if (hasDuplicates(q))
      cerr << "**************ERROR: there are no duplicates in the empty list\n";
   else
      cerr << "no duplicates in the empty list as expected\n";

   q = cons(8, cons(7, cons(3, cons(1, cons(3, nullptr)))));
   printPrompt("q = ");
   printList(q);
   cerr << "expecting q = [ 8 7 3 1 3 ]\n";

   printPrompt();
   if (hasDuplicates(q))
      cerr << "q has duplicates as expected\n";
   else
      cerr << "**************ERROR: there ARE duplicates in p\n";

   // reprinting p ... nothing should have changed
   printPrompt("p = ");
   printList(p);
   cerr << "expecting p = [ 1 2 3 ]\n";

   printPrompt();
   if (hasDuplicates(p))
      cerr << "**************ERROR: there ARE duplicates in p\n";
   else
      cerr << "p does not have duplicates as expected\n";

   printPrompt();
   if (isLonger(q, p))
      cerr << "q is longer than p as expected\n";
   else
      cerr << "**************ERROR: q does have more elements than p\n";

   printPrompt();
   if (!isLonger(p, p))
      cerr << "p is NOT longer than itself as expected\n";
   else
      cerr << "**************ERROR: p does have more elements than itself\n";

   printPrompt();
   if (isLonger(p, q))
      cerr << "**************ERROR: p does not have more elements than q\n";
   else
      cerr << "p is NOT longer than q as expected\n";

   // make q the empty list
   q = deleteList(q);
   printPrompt("after deleteList q = ");
   printList(q);
   cerr << "expecting q = [ ]\n";

   printPrompt();
   if (isLonger(p, q))
      cerr << "p is longer than the empty list q as expected\n";
   else
      cerr << "**************ERROR: p is falsely not longer than the empty list q\n";

   // reprinting p ... nothing should have changed
   printPrompt("p = ");
   p = append(4, p);
   printList(p);
   cerr << "expecting p = [ 1 2 3 4 ]\n";

   int i = 3;
   printPrompt("the list starting with the ith Node, for i=3 is ");
   Node* iPtr = ithNode(p, i);
   printList(iPtr);
   cerr << "expecting [ 4 ]\n";

   i = 9;
   printPrompt("the list starting with the ith Node, for i=9 is ");
   iPtr = ithNode(q, i);
   printList(iPtr);
   cerr << "expecting [ ]\n";

   printPrompt();
   cerr << "Enter integers and exit with a non digit: 2 0 1 5 w\n";
   printPrompt();
   Node* r = readList();
   printPrompt("after readList: r = ");
   printList(r);
   cerr << "expecting r = [ 2 0 1 5 ]\n";

   printPrompt();
   cerr << "Enter a non digit to create an empty list \n";
   printPrompt();
   q = readList();
   printPrompt("after readList: q = ");
   printList(q);
   cerr << "expecting q = [ ]\n";

   q = deleteList(q);
   printPrompt("after deleteList: ");
   printList(q);
   cout << "expecting [ ]\n";

   int A[4] = {1, 3, 5, 7};
   q = array2List(A, 4);
   printPrompt("after array2List: q = ");
   printList(q);
   cerr << "expecting q = [ 1 3 5 7 ]\n";
   q = deleteList(q);

   q = cons(4, cons(6, cons(6, cons(10, nullptr))));
   p = deleteList(p);
   p = cons(7, nullptr);
   printPrompt("after merging p and q: ");
   printList(mergeTwoOrderedLists(p, q));
   cerr << "expecting [ 4 6 6 7 10 ]\n";

   r = deleteList(r);
   r = cons(1, cons(2, cons(3, cons(4, nullptr))));
   printPrompt("after merging with an empty list: ");
   printList(mergeTwoOrderedLists(r, nullptr));
   cerr << "expecting [ 1 2 3 4 ]\n";
   printPrompt("after merging with an empty list: ");
   printList(mergeTwoOrderedLists(nullptr, r));
   cerr << "expecting [ 1 2 3 4 ]\n";

   t = cons(3, cons(4, cons(4, cons(10, cons(12, cons(15, nullptr))))));
   printPrompt("after merging t and r: ");
   printList(mergeTwoOrderedLists(t, r));
   cerr << "expecting [ 1 2 3 3 4 4 4 10 12 15 ]\n";

   return 0;
}
