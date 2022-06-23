#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;


void bubbleSort(int A[], int n);
void swap(int A[], int a, int b);
void display(int A[], int n);


int main(){
    srand(time(0));
    const int n = 60;
    int A[n];
    for (int i=0; i<n; i++){
            A[i] = rand()%100;
    }
    cout << "Before the iterative bubble sort: " << endl;
    display(A, n);
    bubbleSort(A, n);
    cout << "After the iterative bubble sort: "<< endl;
    display(A, n);

    return 0;
}

void bubbleSort(int A[], int n){
    for(int i=0; i<n-1; i++)
        for(int k=0; k<n-1; k++)
            if(A[k]>A[k+1])
                swap(A, k, k+1);
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
Before the iterative bubble sort:
5  83 3  36 43 12
52 29 4  93 25 71
56 38 63 8  25 48
82 20 50 42 91 77
81 29 50 6  15 23
48 61 6  31 85 50
34 20 73 11 41 36
23 21 80 15 83 18
75 4  84 9  51 55
73 87 81 4  62 36

After the iterative bubble sort:
3  4  4  4  5  6
6  8  9  11 12 15
15 18 20 20 21 23
23 25 25 29 29 31
34 36 36 36 38 41
42 43 48 48 50 50
50 51 52 55 56 61
62 63 71 73 73 75
77 80 81 81 82 83
83 84 85 87 91 93
*/
