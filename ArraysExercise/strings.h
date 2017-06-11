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

//Concatenates (attaches in the end) str1 and str2 into str1
void strcat(char str1[], char str2[])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    for(int i=0; i <= len2; ++i)
    {
        str1[len1 + i] = str2[i];
    }
}

//Compares the two strings
//The function returns:
//-1 if str1 < str2
//0 if str1 is the same as str2
//1 if str1 > str2
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
    
    if (len1 == len2)
    {
        return 0;
    }
    
    return len1 < len2 ? -1 : 1;
}

//Check whether the two strings are the same
bool eq(char first[], char second[])
{
    return strcmp(first, second) == 0;
}

//Checks whether big starts with small
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

//Checks whether big contains small
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

//Checks whether big contains small
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

int replaceLetter(char* str, char oldChar, char newChar)
{
    int count = 0;
    for(int i=0; i < strlen(str); ++i)
    {
        if (str[i] == oldChar)
        {
            str[i] = newChar;
            ++count;
        }
    }
    return count;
}

void replaceFrom(char* str, char* newStr, int oldLength)
{
    for(int i=0; i < strlen(newStr); ++ i) {
        str[i] = newStr[i];
    }
    
    int offset = oldLength - strlen(newStr);
    
    if (offset > 0) {
        for(int i = strlen(newStr); i <= strlen(str) - offset; ++ i)
        {
            str[i] = str[i+offset];
        }
    }
}

int replaceSubstring(char* str, char* oldStr, char* newStr)
{
    int count = 0;
    int replaced = 0;
    
    int index = substr(oldStr, str);
    
    if (index > -1)
    {
        ++count;
        replaceFrom(str + index, newStr, strlen(oldStr));
        
        replaced = replaceSubstring(str + index + strlen(newStr), oldStr, newStr);
    }
    
    return count + replaced;
}

void basicStrings()
{
//    char word[] = "word";
//    
//    cout << word << endl;
//    
//    char word2[] = {'h', 'e', 'l', 'l', 'o', '\0'};
//
//    cout << word2 << endl;
//    
//    char name[10] = "abc";
//    
//    cout << endl;
//    
//    cout << strlen(name) << endl;
//    
//    strcat(name, word);
//    
//    cout << "Concatenated: " << name << endl;
//    cout << strlen(name) << endl;
    
    char string[] = "Hello World";
    int replaced = replaceLetter(string, 'o', 'X');
    cout << "Replaced " << replaced << " characters in " << string << endl;
    
    char str[] = "aaaaaa";
    
    int count = replaceSubstring(str, "aa", "a");
    cout << "Replaced " << count << " strings in (" << str << ")" << endl;
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

//Test suite for the substr function
//firsts - contains the test arguments for the first parameter of substr
//seconds - contains the test arguments for the second parameter of substr
//expected - the expected value for calling substr with the respective args
//from firsts and seconds
//count - the number of the tests
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

bool testStrcat(char* firsts[], char* seconds[], char* expected[], int count)
{
    int successfulTests = 0;
    
    for(int i=0; i < count; ++i)
    {
        char* first = firsts[i];
        char* second = seconds[i];
        
        strcat(first, second);
        
        bool success = eq(first, expected[i]);
        
        if (success)
        {
            ++successfulTests;
        }
        else
        {
            cout << "Test " << i << " failed. Expected is " << expected[i]
            << " but actual was " << first << "." << endl;
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

bool testStrlen(char* strings[], int expected[], int count)
{
    int successfulTests = 0;
    
    for(int i=0; i < count; ++i)
    {
        char* arg = strings[i];
        
        int actual = strlen(arg);
        
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
//
//    char* firsts[] = {"ei", "hello", "string", "string", "", "hello", "I"};
//    char* seconds[] = {"height", "abc", "This is a string", "string", "hello", "", "I am"};
//    int expected[] = {1, -1, 10, 0, 0, -1, 0};
//    int count = 7;
//
//    testSubstring(firsts, seconds, expected, count);
//    
//    char* strings[] = {"", "I", "hello", "World"};
//    int expected[] = {0, 1, 5, 5};
//    int count = 4;
//    
//    testStrlen(strings, expected, count);
    
    char first_0[50] = "ei";
    char first_1[50] = "hello";
    char first_2[50] = "string";
    char* firsts[] = {first_0, first_1, first_2};
    char* seconds[] = {"height", "abc", ""};
    char* expected[] = {"eiheight", "helloabc", "string"};
    int count = 3;
    
    testStrcat(firsts, seconds, expected, count);
    
//    outputPrefix("hello", "hello world");
//    outputPrefix("or", "world");
//    outputPrefix("", "prefix");
//    outputPrefix("", "");
//    
//    char str[] = "This is a string.";
//    cout << str + 5 << endl;
}

#endif /* strings_h */
