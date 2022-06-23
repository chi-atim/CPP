#include<iostream>
#include<cstdlib>
#include <ctime>


using namespace std;

void selectionSort(int A[], int n);

void quickSort(int A[], int n);
void quickSort(int A[], int low, int high);
int partition(int A[], int low, int high);

void mergeSort(int A[], int W[], int n);
void mergeSort(int A[], int low, int high, int W[]);
void merge(int A[], int a_start, int a_end, int b_start, int b_end, int W[]);

void swap(int A[], int a, int b);
void makeArray (int A[], int n);


const int n = 1000; // size of array - 1000, 2000, 4000, 8000, 16000, 32000
const int m = 1000; // # of the experiment to repeat

int main(){
    srand(time(0));

    int A[n];
    //int W[n];
    double T; // total time
    makeArray(A, n);

    for (int i=0; i<m; i++){
        //selectionSort(A, n);
        quickSort(A, n);
        //mergeSort(A, W, n);
    }

    T=(double)clock();
    cout << T/m << endl;

    return 0;
}
/*Generate arrays of random integers*/
void makeArray(int A[], int n){
    for (int i=0; i<n; i++){
        A[i]=rand()%RAND_MAX+RAND_MAX;
    }
}
/*selection sort - acknowledge the source*/
void selectionSort(int A[], int n){
    for(int i=0; i<n; i++){
        int minIndex=i;
        for(int k=i+1; k<n; k++){
            if(A[k] < A[minIndex])
                minIndex=k;
        }
        swap(A, i, minIndex);
    }
}
/*quick sort - acknowledge the source*/
void quickSort(int A[], int n){
    quickSort(A, 0, n-1);
}
void quickSort(int A[], int low, int high){
    if(low >= high) return;
    if(low + 1 == high){
        if(A[low] > A[high]){
            swap(A, low, high);
        }
        return;
    }

    int mid = partition(A, low, high);
    quickSort(A, low, mid - 1);
    quickSort(A, mid + 1, high);
    return;
}
int partition(int A[], int low, int high){
    int pivot = A[low];
    int first = low;
    low++;
    while(true){
        while(low <= high && A[high] > pivot) high--;
        while(low <= high && A[low] < pivot) low++;
        if(low >= high) break;
        if(low < high) {
            swap(A, low, high);
            low++;
            high--;
        }
    }
    swap(A, first, high);
    return high;
}
/*merge sort - acknowledge the source*/
void mergeSort(int A[], int W[], int n){
    mergeSort(A, 0, n-1, W);
}
void mergeSort(int A[], int low, int high, int W[]){
    if (low == high) return;
    if (low + 1 == high){
        if (A[low] > A[high])
            swap(A, low, high);
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(A, low, mid, W);
    mergeSort(A, mid + 1, high, W);
    merge(A, low, mid, mid + 1, high, W);
    return;
}
void merge(int A[], int a_start, int a_end, int b_start, int b_end, int W[]){
    int i=a_start, j=b_start, k=a_start;
    while(i <= a_end && j <= b_end){
        if(A[i] <= A[j])
            W[k++] = A[i++];
        else
            W[k++] = A[j++];
    }
    while(i <= a_end) W[k++] = A[i++];
    while(j <= b_end) W[k++] = A[j++];
    for(i = a_start; i <= b_end; i++)
        A[i] = W[i];
}
void swap(int A[], int a, int b){
    int temp=A[a];
    A[a]=A[b];
    A[b]=temp;
}


