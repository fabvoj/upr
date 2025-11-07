#include <stdio.h>

int main(){
    int number = 250;
    int cash[] = {5000, 2000, 1000, 500, 200, 100};
    for( int numberOfCash = 0; numberOfCash < 6; numberOfCash++ ){
        printf("Bankovka %4d: %dx\n", cash[numberOfCash], number / cash[numberOfCash]);
        number = number % cash[numberOfCash];
    }
    return 0;
}