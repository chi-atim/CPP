#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;

void recursiveInsertion(int list[], int n);
void display(int list[], int n);

int main(){
    srand(time(0));
    const int SIZE = 30;
    int list[SIZE];
    for (int i=0; i<SIZE; i++){
            list[i] = rand()%100;
    }

    cout << "Before sort: " << endl;
    display(list, SIZE);

    recursiveInsertion(list, SIZE);

    cout << "After sort: "<< endl;
    display(list, SIZE);

    return 0;
}
void display(int list[], int n){
    for (int i=0; i<n; i++){
        if (list[i]/10==0)
            cout << list[i] << "  ";
        else
            cout << list[i] << " ";
        if ((i+1)%6==0)
            cout << endl;
    }
    cout << endl;
}

void recursiveInsertion(int list[], int n){
    if (n==1) return;
    int k;
    int temp = list[n-1];
    recursiveInsertion(list, n-1);
    for (k=n-1; k>=0 && list[k]>temp; k--){
        list[k+1] = list[k];
    }
    list[k+1] = temp;
}
