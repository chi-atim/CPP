#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

//a helper function to check if two people share the same birthday
bool isShared(int birthday[], int n){
    for(int i=0; i<n; i++) {
        for(int k=i+1; k<n; k++) {
            if (birthday[i] == birthday[k])
                return true;
        }
    }
    return false;
}
int birthdayParadox(const int n, int trials){
    srand(time(NULL));

    int birthday[n];
    int C = 0; //Count of number of trials which two people in the room do have the same birthday

    for (int j=0;j<trials; j++){
        for(int i=0; i<n; i++) {
            birthday[i] = (rand() % 365) + 1; //Assign a random birthday
        }
        if(isShared(birthday, n)) C++;
    }
    return C;
}
int main(){

    int N = 20;//the number of people in the room
    int T = 3000;//the number of trials

    for (int i=N; i<N+10; i++){
        double P = birthdayParadox(i, T)/double(T);
        cout << "The probability of two people share the same birthday in the room of "  << i << " people is "<< P << endl;
    }
    return 0;
}
