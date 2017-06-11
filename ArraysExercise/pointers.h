//
//  pointers.h
//  ArraysExercise
//
//  Created by Miroslav Mironov on 6/1/17.
//  Copyright © 2017 Miroslav Mironov. All rights reserved.
//

#ifndef pointers_h
#define pointers_h

int length(char* str)
{
    int len = 0;
    while (*str != '\0')
    {
        ++len;
        ++str;
    }
    return len;
}

void testPointers()
{
    int number = 20;
    
    int* p = &number;
    
    int** secondPointer = &p;
    
    cout << "pointer: " << p << endl;
    cout << "value: " << *p << endl;
    
    cout << "secondPointer: " << secondPointer << endl;
    cout << "*secondPointer: " << *secondPointer << endl;
    cout << "**secondPointer: " << **secondPointer << endl;
    cout << "&secondPointer: " << &secondPointer << endl;
    
    int arr[5] = {1,2,3,4,5};
    cout << *(arr + 1) << endl;
    cout << arr[1] << endl;
    
    char str[] = "hello";
    const char* str2 = "hello";
    cout << length("hello") << endl;
}

#endif /* pointers_h */
