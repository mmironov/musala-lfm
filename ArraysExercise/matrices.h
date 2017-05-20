//
//  matrices.h
//  ArraysExercise
//
//  Created by Miroslav Mironov on 5/20/17.
//  Copyright © 2017 Miroslav Mironov. All rights reserved.
//

#ifndef matrices_h
#define matrices_h

#include <iostream>
using namespace std;

void printRow(int row[], int n)
{
    for(int i=0; i < n; ++i)
    {
        cout << row[i] << " ";
    }
}

void printMatrix(int matrix[][3], int n)
{
    for(int row = 0; row < n; ++row)
    {
        printRow(matrix[row], 3);
        cout << endl;
    }
}

void printMatrixByColumns(int matrix[][3], int n)
{
    for(int col = 0; col < 3; ++col)
    {
        for(int row = 0; row < n; ++row)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}

int sumAll(int matrix[][3], int n)
{
    int sum = 0;
    
    for(int col = 0; col < 3; ++col)
    {
        for(int row = 0; row < n; ++row)
        {
            sum += matrix[row][col];
        }
    }
    
    return sum;
}

void printSumInEveryRow(int matrix[][3], int n)
{
    for(int row=0; row < n; ++row)
    {
        int sum = 0;
        for(int col=0; col < 3; ++col)
        {
            sum += matrix[row][col];
        }
        cout << "Row " << row << ": " << sum << endl;
    }
}

int sumRow(int matrix[][3], int n, int row)
{
    int sum = 0;
    for(int col=0; col < 3; ++col)
    {
        sum += matrix[row][col];
    }
    
    return sum;
}

int indexOfRowWithBiggestSum(int matrix[][3], int n)
{
    int indexMax = 0;
    int maxSum = sumRow(matrix, n, 0);
    
    for(int row = 1; row < n; ++row)
    {
        int sum = sumRow(matrix, n, row);
        
        if (sum > maxSum)
        {
            maxSum = sum;
            indexMax = row;
        }
    }
    
    return indexMax;
}

#endif /* matrices_h */
