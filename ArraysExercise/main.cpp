//
//  main.cpp
//  ArraysExercise
//
//  Created by Miroslav Mironov on 5/19/17.
//  Copyright © 2017 Miroslav Mironov. All rights reserved.
//

#include <iostream>
using namespace std;

void useTemperatureCalculator();

const double MULT = 9.0;
const double DIV = 5.0;
const double ADD = 32.0;

double convertToFahrenheit(double celsius)
{
    double result = celsius * MULT / DIV + ADD;
    return result;
}

double convertToCelsius(double fahrenheit)
{
    double result = (fahrenheit - ADD) * DIV / MULT;
    return result;
}

void useTemperatureCalculator()
{
    char choice = ' ';
    double converted = 0;
    
    const char choiceF = 'F';
    const char choiceC = 'C';
    
    do
    {
        cout << "Enter " << choiceC << " to convert from Celsius" << endl;
        cout << "Enter " << choiceF << " to convert from Fahreinheit" << endl;
        cout << "Your choice: ";
        
        cin >> choice;
    } while (!(choice == choiceC || choice == choiceF));
    
    double temperature;
    
    cout << "Temperature in " << choice << ":";
    cin >> temperature;
    
    if (choice == choiceC)
    {
        converted = convertToFahrenheit(temperature);
    }
    else if (choice == choiceF)
    {
        converted = convertToCelsius(temperature);
    }
    
    const char convertedChoice = (choice == choiceC) ? choiceF : choiceC;
    
    cout << temperature << " " << choice << " = " << converted << " " << convertedChoice << endl;
}

void printPositiveNumbers()
{
    int n = 0;
    
    do
    {
        cout << "n=";
        cin >> n;
    } while (n < 0);
    
    for(int i=0; i <=n; i += 2)
    {
        cout << i << " ";
    }
    cout << endl;
}

void findLongestDuplicate()
{
    const int SIZE = 10;
    int arr[SIZE] = {1, 4, 4, 4, 7, 1, 5, 5, 5, 1};
    
    int longest = 1;
    int lastIndex = 0;
    
    int currentLength = 1;
    
    for(int i=1; i < SIZE; ++i)
    {
        if (currentLength > longest)
        {
            longest = currentLength;
            lastIndex = i-1;
        }
        
        if (arr[i] == arr[i-1])
        {
            ++currentLength;
        }
        else
        {
            currentLength = 1;
        }
    }
    
    if (currentLength > longest)
    {
        longest = currentLength;
        lastIndex = SIZE - 1;
    }
    
    cout << "Sequence: ";
    
    for(int i=lastIndex; i > lastIndex - longest; --i)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}

void findPropertiesForArray()
{
    const int SIZE = 1;
    int arr[SIZE] = {1};
    
    bool increasing = true;
    bool decreasing = true;
    bool allEqual = true;
    bool zigZagged = true;
    
    bool smallToBig = true;
    
    for(int i=1; i < SIZE; ++i)
    {
        if (arr[i] < arr[i-1])
        {
            increasing = false;
        }
        
        if (arr[i] > arr[i-1])
        {
            decreasing = false;
        }

        if (arr[i] != arr[i-1])
        {
            allEqual = false;
        }

        if ((smallToBig && arr[i] < arr[i-1]) || (!smallToBig && arr[i] > arr[i-1]))
        {
            zigZagged = false;
        }
        
        smallToBig = !smallToBig;
    }
    
    cout << "Increasing: " << increasing << endl;
    cout << "Decreasing: " << decreasing << endl;
    cout << "All Equal: " << allEqual << endl;
    cout << "Is zigzagged: " << zigZagged << endl;
}

int main(int argc, const char * argv[]) {
    
//    useTemperatureCalculator();
//    printPositiveNumbers();
//    findLongestDuplicate();
    findPropertiesForArray();

    return 0;
}
