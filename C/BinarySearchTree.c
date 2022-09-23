#include <stdio.h>
#include <math.h>

int numOfBST(int);

int main() {
    
    return 0;
}

numOfBST(int key) {
    int catalanNumber = factorial(2 * key)/(factorial(key + 1) * factorial(key)); 
    return catalanNumber;
}