//
//  strings.h
//  ArraysExercise
//
//  Created by Miroslav Mironov on 5/21/17.
//  Copyright © 2017 Miroslav Mironov. All rights reserved.
//

#ifndef strings_h
#define strings_h

#include <iostream>
using namespace std;

//Returns the length of the string
int strlen(char str[])
{
    int i = 0;
    
    while (str[i] != '\0')
    {
        ++i;
    }
    
    return i;
}

//Concatenates str1 and str2 into str1
void strcat(char str1[], char str2[])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    for(int i=0; i <= len2; ++i)
    {
        str1[len1 + i] = str2[i];
    }
}

int strcmp(char str1[], char str2[])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    int minLen = len1 < len2 ? len1 : len2;
    
    for(int i=0; i < minLen; ++i)
    {
        if (str1[i] < str2[i])
        {
            return -1;
        }
        
        if (str1[i] > str2[i])
        {
            return 1;
        }
    }
    
    return len1 < len2 ? -1 : 1;
}

bool eq(char first[], char second[])
{
    return strcmp(first, second) == 0;
}

bool isPrefix(char small[], char big[])
{
    if (strlen(small) > strlen(big))
    {
        return false;
    }
    
    for(int i=0; i < strlen(small); ++i)
    {
        if (small[i] != big[i])
        {
            return false;
        }
    }
    
    return true;
}

int substr(char small[], char big[])
{
    int lenSmall = strlen(small);
    int lenBig = strlen(big);
    
    for(int i=0; i < lenBig - lenSmall + 1; ++i)
    {
        bool foundMismatch = false;
        for(int j=0; j < lenSmall; ++j)
        {
            if (small[j] != big[j + i])
            {
                foundMismatch = true;
                break;
            }
        }
        
        if (!foundMismatch)
        {
            return i;
        }
    }
    
    //If we are here, we haven't found any substring
    return -1;
}

int substr2(char small[], char big[])
{
    int lenSmall = strlen(small);
    int lenBig = strlen(big);
    
    for(int i=0; i < lenBig - lenSmall + 1; ++i)
    {
        if (isPrefix(small, big + i))
        {
            return i;
        }
    }
    
    //If we are here, we haven't found any substring
    return -1;
}

void basicStrings()
{
    char word[] = "word";
    
    cout << word << endl;
    
    char word2[] = {'h', 'e', 'l', 'l', 'o', '\0'};

    cout << word2 << endl;
    
    char name[10] = "abc";
    
    cout << endl;
    
    cout << strlen(name) << endl;
    
    strcat(name, word);
    
    cout << "Concatenated: " << name << endl;
    cout << strlen(name) << endl;
}

void outputCmp(char str1[], char str2[])
{
    int cmpResult = strcmp(str1, str2);
    
    cout << "cmp(" << str1 << ", " << str2 << ") = " << cmpResult << endl;
}

void outputSubstring(char str1[], char str2[])
{
    int substrResult = substr2(str1, str2);
    
    cout << "substr(" << str1 << ", " << str2 << ") = " << substrResult << endl;
}

void outputPrefix(char str1[], char str2[])
{
    int prefixResult = isPrefix(str1, str2);
    
    cout << "isPrefix(" << str1 << ", " << str2 << ") = " << prefixResult << endl;
}

bool testSubstring(char* firsts[], char* seconds[], int expected[], int count)
{
    int successfulTests = 0;
    
    for(int i=0; i < count; ++i)
    {
        char* first = firsts[i];
        char* second = seconds[i];
        
        int actual = substr(first, second);
        
        bool success = actual == expected[i];
        
        if (success)
        {
            ++successfulTests;
        }
        else
        {
            cout << "Test " << i << " failed. Expected is " << expected[i]
            << " but actual was " << actual << "." << endl;
        }
    }
    
    bool allSuccessful = successfulTests >= count;
    
    if (allSuccessful)
    {
        cout << "SUCESS!" << endl;
    }
    else
    {
        cout << "FAILURE!" << endl;
    }
    
    cout << "Tests: " << successfulTests << "/" << count << endl;
    
    return allSuccessful;
}

void testComparison()
{
//    char hello[] = "hello";
//    char world[] = "world";
//    char height[] = "height";
//    char heightheight[] = "heightheight";
//    char helloo[] = "helloo";
//    char empty[] = "";
//    char space[] = " ";
//    
//    outputCmp(hello, height);
//    outputCmp(height, hello);
//    outputCmp("Miro", "Miroslav");
//    outputCmp(hello, hello);
//    outputCmp(empty, empty);
//    outputCmp(empty, hello);
//    outputCmp(space, empty);
//    outputCmp(empty, space);
//    outputCmp(height, heightheight);
//    outputCmp(world, helloo);
//    
//    outputSubstring("ei", "height");
//    outputSubstring("hello", "abc");
//    outputSubstring("string", "This is a string");
//    outputSubstring("string", "string");
//    outputSubstring("", "hello");
//    outputSubstring("hello", "");

    char* firsts[] = {"ei", "hello", "string", "string", "", "hello", "I"};
    char* seconds[] = {"height", "abc", "This is a string", "string", "hello", "", "I am"};
    int expected[] = {1, -1, 10, 0, 0, -1, 0};
    int count = 7;
    
    testSubstring(firsts, seconds, expected, count);
    
//    outputPrefix("hello", "hello world");
//    outputPrefix("or", "world");
//    outputPrefix("", "prefix");
//    outputPrefix("", "");
//    
//    char str[] = "This is a string.";
//    cout << str + 5 << endl;
}

#endif /* strings_h */
