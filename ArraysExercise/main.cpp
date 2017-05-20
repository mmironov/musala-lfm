//
//  main.cpp
//  ArraysExercise
//
//  Created by Miroslav Mironov on 5/19/17.
//  Copyright © 2017 Miroslav Mironov. All rights reserved.
//

#include "arrays.h"
#include "matrices.h"

int main(int argc, const char * argv[]) {
//    
//    useTemperatureCalculator();
//    printPositiveNumbers();
//    findLongestDuplicate();
//    findPropertiesForArray();
//    
//    cout << isPrime(131) << endl;
//
//    printPrimesBelow(1000000);
//    
//    const int SIZE = 5;
//    char word[SIZE] = {'H', 'E', 'L', 'L', 'O'};
//    
//    countLetters(word, SIZE);
//    
//    double d1 = 4.99999;
//    double d2 = 4.99998;
//    
//    if (eq(d1, d2, 0.01))
//    {
//        cout << "equal" << endl;
//    }
//    
//    const int N = 7;
//    int numbers[N] = {1, 2, 3, 4, 5, 6, 7};
//    
//    printDuplicatesWithCounting(numbers, N);
//    cout << endl;
//    
//    double d = 20;
//    cout << "sqrt(" << d << ") = " << sqrt(d, 0.0001) << endl;

    const int SSIZE = 2;
    int matrix[SSIZE][3] = {{1, 2, 3}, {4, 5, 6}};
    
    printMatrixByColumns(matrix, SSIZE);
    cout << sumAll(matrix, SSIZE) << endl;
    
    printSumInEveryRow(matrix, SSIZE);
    
    cout << "Index of max row: " << indexOfRowWithBiggestSum(matrix, SSIZE) << endl;
    
    return 0;
}
