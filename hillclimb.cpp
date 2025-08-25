#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int fitness(int x) {
    return x * x;
}

int main() {
    srand(time(0)); 

    int current = rand() % 20; 
    int currentValue = fitness(current);

    cout << "Starting Point: " << current << " Value: " << currentValue << endl;

    for(int i=0; i<100; i++) {  
        int neighbor = current + (rand()%3 - 1); // neighbor = current+1 or current-1 or same
        if(neighbor < 0) neighbor = 0;     //negativity ko hatana ke liya 

        int neighborValue = fitness(neighbor);

        if(neighborValue > currentValue) { // agar neighbor better hai toh uspar move kro
            current = neighbor;
            currentValue = neighborValue;
            cout << "Move to: " << current << " Value: " << currentValue << endl;
        }
    }

    cout << "\nFinal Solution: " << current << " Value: " << currentValue << endl;

    return 0;
}
