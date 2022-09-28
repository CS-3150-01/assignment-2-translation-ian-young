#include <stdio.h>
#include <stdlib.h>

int factorial(int);
int numOfBST(int);

int main() {
    printf("Total number of possible Binary Search Trees with given key: %d", numOfBST(5));
    return 0;
}

int factorial(int num) {    
        int fact = 1;    
        if(num == 0)    
            return 1;    
        else {    
            while(num > 1) {    
                fact = fact * num;    
                num--;    
            }    
            return fact;    
        }    
    }   

int numOfBST(int key) {
    int catalanNumber = factorial(2 * key)/(factorial(key + 1) * factorial(key)); 
    return catalanNumber;
}