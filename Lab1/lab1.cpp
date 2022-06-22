#include <iostream>
#include<cstdlib>
#include<cmath>
#include <ctime>
using namespace std;

int main() {
    double x, y, m = 0;
    int totalThrow;
    srand(time(NULL));

    cout<< "Enter the number of dart to throw: ";
    cin>> totalThrow;

    for(int i=0; i<totalThrow; i++) {
        x = (double) rand() / (RAND_MAX) +1;
        y = (double) rand() / (RAND_MAX);
        if(x >= 1 && x <= 2 && y <= 1/x) m++;
    }
    
    double ln2 = m /totalThrow;
    cout<< "The estimate value of ln 2 is: " << ln2 << endl;
    cout<< "The actual value of ln 2 is: " << log(2) << endl;
    return 0;
}
