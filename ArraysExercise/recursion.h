//
//  recursion.h
//  ArraysExercise
//
//  Created by Miroslav Mironov on 5/21/17.
//  Copyright © 2017 Miroslav Mironov. All rights reserved.
//

#ifndef recursion_h
#define recursion_h

//Computes factorial of n
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    
    return n * fact(n-1);
}

//Computes factorial of n
int iter_fact(int n)
{
    int fact = 1;
    
    for(int i=2; i <= n; ++i)
    {
        fact *= i;
    }
    
    return fact;
}

//Computes factorial of n
int iter_fact_helper(int i, int res)
{
    if (i == 1)
    {
        return res;
    }
    
    return iter_fact_helper(i - 1, res * i);
}

//Computes factorial of n
int fact_with_helper(int n)
{
    int result = iter_fact_helper(n, 1);
    return result;
}

//Checks whether big starts with small
bool isPrefixRecursive(char small[], char big[])
{
    if (strlen(small) > 0)
    {
        if (strlen(big) > 0)
        {
            bool firstChars = small[0] == big[0];
            
            return firstChars && isPrefixRecursive(small + 1, big + 1);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

//Test for isPrefix
bool isPrefixTest(char* firsts[], char* seconds[], int expected[], int counT)
{
    int successfulTests = 0;
    for(int i = 0; i < counT; i++)
    {
        char* first = firsts[i];
        char* second = seconds[i];
        bool actual = isPrefixRecursive(first,second);
        bool success = actual == expected[i];
        if(success)
        {
            successfulTests++;
        }
        else
        {
            cout<<" TEST "<< i << " Failed. Expected is " << expected[i] << " but actual was " <<actual<<'.'<<endl;
        }
    }
    bool allSuccessful = successfulTests >= counT;
    if(allSuccessful)
    {
        cout<<"SUCCESS!"<<endl;
    }else
    {
        cout<<"FAILURE!"<<endl;
    }
    cout << "Tests: " << successfulTests << "/" << counT << endl;
    return allSuccessful;
}

//Counts how many times sentence contains word
int countWord(char word[], char sentence[])
{
    if (strlen(sentence) >= strlen(word))
    {
        bool prefix = isPrefix(word, sentence);
        int prefixWeight = prefix ? 1 : 0;
        
        if (strlen(sentence) > 0)
        {
            return prefixWeight + countWord(word, sentence + 1);
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

//Computes the sum of the numbers in arr
int sum(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    
    int otherSum = sum(arr + 1, n-1);
    
    cout << arr[0] << " ";
    //1 2 3 4
    //1
    //4
    //1 1 1 1
    
    return arr[0] + otherSum;
}

void testRecursion()
{
    char* strOne[] = {"hello","abv","dce","aleluq","ale"};
    char* strTwo[] = {"ll","ab","cde","luq",""};
    // cout<<subStr(strOne,strTwo)<<endl;
    int expected[] = {0,1,0,0,1};
    int counT = 5;
    isPrefixTest(strTwo, strOne, expected, counT);
    
    cout << "Count: " << countWord("hello", "hello world, hello, hello!") << endl;
}

#endif /* recursion_h */
