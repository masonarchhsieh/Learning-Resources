/*
 * =====================================================================================
 *
 *       Filename:  ChangingString.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/11/2019 04:21:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */
/*
 * 
 * Problem Statement
 *      
 *      You are given two Strings A and B that have the same length and contain only lowercase letters ('a'-'z'). The distance between two letters is defined as the absolute value of their difference. The distance between A and B is defined as the sum of the differences between each letter in A and the letter in B at the same position. For example, the distance between "abcd" and "bcda" is 6 (1 + 1 + 1 + 3).
 *
 *      You must change exactly K characters in A into other lowercase letters. Return the minimum possible distance between A and B after you perform that change.
 *
 *       
 *       Definition
 *              
 *              Class:ClassChangingStringMethod:ClassChangingStringMethoddistanceParameters:ClassChangingStringMethoddistanceParametersString, String, int
 *              Returns:ReturnsintMethod signature:signatureint distance(String A, String B, int K)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -ConstraintsA and B will each contain between 1 and 50 characters, inclusive.
 *                   -inclusiveK will be between 1 and the length of A, inclusive.
 *                   -inclusiveA and B will contain the same number of characters.
 *                   -charactersA and B will contain only lowercase letters ('a' - 'z').
 *                    
 *                    Examples
 *                    0)        
 *                    "ab"
 *                    "ba"
 *                    2
 *                    Returns: 0
 *                    The minimum distance (equal to 0) can be achieved when we change 'a' to 'b' and 'b' to 'a'.
 *                    1)        
 *                    "aa"
 *                    "aa"
 *                    2
 *                    Returns: 2
 *                    We must change both letters 'a' to some other letters. Changing them to 'b' results in the smallest distance.
 *                    2)        
 *                    "aaa"
 *                    "baz"
 *                    1
 *                    Returns: 1
 *                    3)        
 *                    "fdfdfdfdfdsfabasd"
 *                    "jhlakfjdklsakdjfk"
 *                    8
 *                    Returns: 24
 *                    4)        
 *                    "aa"
 *                    "bb"
 *                    2
 *                    Returns: 0
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.
 *
 */

#include <iostream>
#include <string>
#include <stdlib.h>   /* abs */
#include <vector>

using namespace std;

class ChangingString
{
private:

public:
    ChangingString () {}
    int distance (string A, string B, int K)
    {
        int res = 0;
        vector<int> diff;
        for (int i=0; i<A.length(); i++)
        {
            diff.push_back (abs (A[i] - B[i])); 
        }
        
        /* Sorting */
        int temp = 0;
        for (int i=0; i<diff.size(); i++)
        {
            for (int j=i+1; j<diff.size(); j++)
            {
                if (diff[j] > diff[i]) 
                {
                    temp = diff[i];
                    diff[i] = diff[j];
                    diff[j] = temp;
                }
            }
        }

        for (int i=0; i<diff.size(); i++)
        {
            if (K > 0)
            {
                if (diff[i] == 0)
                    diff[i] = 1;
                else
                    diff[i] = 0;

                K--;
            }

            res += diff[i];
        }

        return res; 
    }
};

int main ()
{
    printf ("Enter the instructions:\n");
    char A [50];
    char B [50];
    int K;

    scanf ("%s", A);
    scanf ("%s", B);
    scanf ("%d", &K); 

    ChangingString cs;
    int res = cs.distance(A, B, K);
    printf("The result is: %d\n", res);

    return 0;
}
