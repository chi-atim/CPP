#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int A[], int n);
void bubbleSortRec(int A[], int n);
int theoreticalCalc(char input, int n);

void swap(int A[], int a, int b);
void display(int A[], int n);
void makeArray(int A[], int n, char input);

int compIterative=0;
int compRecursive=0;

int main(){
    srand(time(0));
    const int n = 60;
    int A[n];

    char ch;
    cout << "Enter 'b' for best case, 'w' for worst case, or 'a' for average case: ";
    cin >> ch;
    if (ch!='b'&& ch!='w' && ch!='a'){
        cout << "Please enter 'b' or 'w' or 'a'." << endl;
        return 1;
    }

    cout << "Before the iterative bubble sort: " << endl;
    makeArray(A, n, ch);
    display(A, n);
    bubbleSort(A, n);
    cout << "After the iterative bubble sort: "<< endl;
    display(A, n);

    cout << "Before the recursive bubble sort: " << endl;
    makeArray(A, n, ch);
    display(A, n);
    bubbleSortRec(A, n);
    cout << "After the recursive bubble sort: "<< endl;
    display(A, n);


    cout << "\nThe number of elements in the array: " << n << endl << endl;
    cout << "Theoretical calculation: "<< theoreticalCalc(ch, n)<< endl;
    cout << "Actual number of comparison using iterative bubble sort: "<< compIterative<< endl;
    cout << "Actual number of comparison using recursive bubble sort: "<< compRecursive<< endl <<endl;
    cout << "Best case: Array is sorted in ascending order." << endl;
    cout << "Worst case: Array is sorted in descending order." << endl;
    cout << "Average case: Array is random and unsorted."<< endl;
    return 0;
}

void makeArray(int A[], int n, char ch){
    if (ch == 'b')
        for (int i=0; i<n; i++)
            A[i] = i;
    else if (ch == 'w')
        for (int i=0, k=n-1; i<n; i++,k--)
            A[i] = k;
    else if (ch == 'a')
        for (int i=0; i<n; i++)
            A[i] = rand()%100;
}
void bubbleSort(int A[], int n){
    for(int i=0; i<n-1; i++){
        bool swapped =false;
        compIterative++;
        for(int k=0; k<n-1; k++){
            if(A[k]>A[k+1]){
                swap(A, k, k+1);
                swapped=true;
                compIterative++;
            }
        }
        if (swapped)compIterative--;
    }
}
void bubbleSortRec(int A[], int n){
    if (n==1) return;
    bool swapped =false;
    compRecursive++;
    for(int i=0; i<n-1; i++){
        if(A[i]>A[i+1]){
            swap(A, i, i+1);
            swapped=true;
            compRecursive++;
        }
    }
    if (swapped) compRecursive--;
    bubbleSortRec(A, n-1);
}
int theoreticalCalc(char ch, int n){
    if (ch == 'b')
        return n-1;
    else if (ch == 'w')
        return (n-1)*n/2;
    else
        return (n-1)*n/4;
}
void swap(int A[], int a, int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}
void display(int A[], int n){
    for (int i=0; i<n; i++){
        if (A[i]/10==0)
            cout << A[i] << "  ";
        else
            cout << A[i] << " ";
        if ((i+1)%6==0)
            cout << endl;
    }
    cout << endl;
}
/*Output - Best case
Enter 'b' for best case, 'w' for worst case, or 'a' for average case: b
Before the iterative bubble sort:
0  1  2  3  4  5
6  7  8  9  10 11
12 13 14 15 16 17
18 19 20 21 22 23
24 25 26 27 28 29
30 31 32 33 34 35
36 37 38 39 40 41
42 43 44 45 46 47
48 49 50 51 52 53
54 55 56 57 58 59

After the iterative bubble sort:
0  1  2  3  4  5
6  7  8  9  10 11
12 13 14 15 16 17
18 19 20 21 22 23
24 25 26 27 28 29
30 31 32 33 34 35
36 37 38 39 40 41
42 43 44 45 46 47
48 49 50 51 52 53
54 55 56 57 58 59

Before the recursive bubble sort:
0  1  2  3  4  5
6  7  8  9  10 11
12 13 14 15 16 17
18 19 20 21 22 23
24 25 26 27 28 29
30 31 32 33 34 35
36 37 38 39 40 41
42 43 44 45 46 47
48 49 50 51 52 53
54 55 56 57 58 59

After the recursive bubble sort:
0  1  2  3  4  5
6  7  8  9  10 11
12 13 14 15 16 17
18 19 20 21 22 23
24 25 26 27 28 29
30 31 32 33 34 35
36 37 38 39 40 41
42 43 44 45 46 47
48 49 50 51 52 53
54 55 56 57 58 59


The number of elements in the array: 60

Theoretical calculation: 59
Actual number of comparison using iterative bubble sort: 59
Actual number of comparison using recursive bubble sort: 59

Best case: Array is sorted in ascending order.
Worst case: Array is sorted in descending order.
Average case: Array is random and unsorted.
*/
/*Output - Worst case
Enter 'b' for best case, 'w' for worst case, or 'a' for average case: w
Before the iterative bubble sort:
59 58 57 56 55 54
53 52 51 50 49 48
47 46 45 44 43 42
41 40 39 38 37 36
35 34 33 32 31 30
29 28 27 26 25 24
23 22 21 20 19 18
17 16 15 14 13 12
11 10 9  8  7  6
5  4  3  2  1  0

After the iterative bubble sort:
0  1  2  3  4  5
6  7  8  9  10 11
12 13 14 15 16 17
18 19 20 21 22 23
24 25 26 27 28 29
30 31 32 33 34 35
36 37 38 39 40 41
42 43 44 45 46 47
48 49 50 51 52 53
54 55 56 57 58 59

Before the recursive bubble sort:
59 58 57 56 55 54
53 52 51 50 49 48
47 46 45 44 43 42
41 40 39 38 37 36
35 34 33 32 31 30
29 28 27 26 25 24
23 22 21 20 19 18
17 16 15 14 13 12
11 10 9  8  7  6
5  4  3  2  1  0

After the recursive bubble sort:
0  1  2  3  4  5
6  7  8  9  10 11
12 13 14 15 16 17
18 19 20 21 22 23
24 25 26 27 28 29
30 31 32 33 34 35
36 37 38 39 40 41
42 43 44 45 46 47
48 49 50 51 52 53
54 55 56 57 58 59


The number of elements in the array: 60

Theoretical calculation: 1770
Actual number of comparison using iterative bubble sort: 1770
Actual number of comparison using recursive bubble sort: 1770

Best case: Array is sorted in ascending order.
Worst case: Array is sorted in descending order.
Average case: Array is random and unsorted.
*/
/*Output - Average case
Enter 'b' for best case, 'w' for worst case, or 'a' for average case: a
Before the iterative bubble sort:
51 56 80 25 19 96
33 76 44 37 53 58
86 70 56 89 52 64
10 75 53 66 14 63
53 81 39 30 6  39
0  66 42 93 87 36
76 6  65 68 86 65
64 9  57 26 72 70
99 98 54 96 80 5
70 56 96 11 60 0

After the iterative bubble sort:
0  0  5  6  6  9
10 11 14 19 25 26
30 33 36 37 39 39
42 44 51 52 53 53
53 54 56 56 56 57
58 60 63 64 64 65
65 66 66 68 70 70
70 72 75 76 76 80
80 81 86 86 87 89
93 96 96 96 98 99

Before the recursive bubble sort:
27 33 22 86 51 84
96 45 62 12 76 26
12 27 18 20 67 52
58 11 83 10 53 2
1  96 94 65 74 99
86 62 61 33 97 18
29 72 6  43 68 14
85 55 97 19 25 91
79 1  49 21 33 42
14 31 73 99 36 29

After the recursive bubble sort:
1  1  2  6  10 11
12 12 14 14 18 18
19 20 21 22 25 26
27 27 29 29 31 33
33 33 36 42 43 45
49 51 52 53 55 58
61 62 62 65 67 68
72 73 74 76 79 83
84 85 86 86 91 94
96 96 97 97 99 99


The number of elements in the array: 60

Theoretical calculation: 885
Actual number of comparison using iterative bubble sort: 828
Actual number of comparison using recursive bubble sort: 886

Best case: Array is sorted in ascending order.
Worst case: Array is sorted in descending order.
Average case: Array is random and unsorted.
*/


