#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;

void bubbleSortRec(int A[], int n);
void swap(int A[], int a, int b);
void display(int A[], int n);


int main(){
    srand(time(0));
    const int n = 60;
    int A[n];
    for (int i=0; i<n; i++){
            A[i] = rand()%100;
    }

    cout << "Before the recursive bubble sort: " << endl;
    display(A, n);
    bubbleSortRec(A, n);
    cout << "After the recursive bubble sort: "<< endl;
    display(A, n);

    return 0;
}

void bubbleSortRec(int A[], int n){
    if (n==1) return;
    for(int i=0; i<n-1; i++){
        if(A[i]>A[i+1])
            swap(A, i, i+1);
    }
    bubbleSortRec(A, n-1);
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

/*Output
Before the recursive bubble sort:
93 23 65 37 57 37
22 46 67 9  50 67
46 14 51 11 24 72
4  18 7  78 6  16
29 7  28 96 93 43
99 17 36 68 9  22
40 68 35 93 26 86
32 51 50 88 79 86
15 87 56 78 92 85
32 84 14 38 55 20

After the recursive bubble sort:
4  6  7  7  9  9
11 14 14 15 16 17
18 20 22 22 23 24
26 28 29 32 32 35
36 37 37 38 40 43
46 46 50 50 51 51
55 56 57 65 67 67
68 68 72 78 78 79
84 85 86 86 87 88
92 93 93 93 96 99
*/
