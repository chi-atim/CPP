#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;

int I(int i, int j, int n);
int DotProduct(const int A[],const int B[],int i, int j, int n);
void MMultiply(const int A[], const int B[], int C[], int n);

int main(){
    cout << " O(n^3+n^2) --> O(n^3)" << endl;
    return 0;
}
int I(int i, int j, int n){
    return n * i + j;
}
int DotProduct(const int A[],const int B[],int i, int j, int n){
    int t=0;
    for(int k=0; k<n; k++ )
        t += A[ I(i,k,n) ] * B[ I(k,j,n) ]; //n*n*n = O(n^3)
    return t;
}
void MMultiply(const int A[], const int B[], int C[], int n){
    for( int i=0; i<n; i++ )
    for( int j=0; j<n; j++ )
    C[ I(i,j,n) ] = DotProduct(A, B, i, j, n ); //n*n = O(n^2)
}
