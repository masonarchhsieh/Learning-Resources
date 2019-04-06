/*
 * =====================================================================================
 *
 *       Filename:  FriendlySequences.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/15/2019 03:53:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */
/*
 * Problem Statement
 *      
 *      We call two numbers friendly if they have the same digits, ignoring order or repetition. For example 122213 and 312 are friendly while 145 and 2544411 are not. A sequence is friendly if it contains at least two numbers, and all possible pairs of numbers within it are friendly. Two contiguous subsequences are different if they have a different start index, end index or both.
 *
 *      If we are given the sequence 112, 12, 21, 354, 534345, 345, 2221 then the friendly contiguous subsequences are: {112, 12}, {112, 12, 21}, {12, 21}, {354, 534345}, {354, 534345, 345} and {534345, 345}. {112, 12, 21, 354} is not a friendly contiguous subsequence because 112 and 354 are not friendly numbers and {112, 12, 21, 2221} is not a friendly contignuous subsequence because the elements of the sequence aren't in consecutive positions in the original sequence.
 *
 *      Given a int[] array, you must return number of different friendly contignuous subsequences of array.
 *
 *       
 *       Definition
 *              
 *              Class:ClassFriendlySequencesMethod:ClassFriendlySequencesMethodcountParameters:ClassFriendlySequencesMethodcountParametersint[]
 *              Returns:ReturnsintMethod signature:signatureint count(int[] array)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintsarray will have between 0 and 50 elements, inclusive.
 *                   -inclusiveEach element of array will be between 0 and 2000000000, inclusive.
 *                    
 *                    Examples
 *                    0)        
 *                    {112, 12, 21, 354, 534345, 345, 2221}
 *                    Returns: 6
 *                    The example in the problem.
 *                    1)        
 *                    {10, 1100, 10101, 111, 1111, 11111, 11, 1, 111}
 *                    Returns: 18
 *                    2)        
 *                    {0, 0, 0, 0}
 *                    Returns: 6
 *                    We have a total of 6 possible different pairs of start and end indices for friendly subsequences.
 *                    3)        
 *                    {123456890, 213456890, 198654320} 
 *                    Returns: 3
 *                    4)        
 *                    {9}
 *                    Returns: 0
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>

using namespace std;

class FriendlySequences
{
    public:
        FriendlySequences () {}
        int count (vector<int> array)
        {
            int res = 0;
            int itr = 0;

            while (itr < array.size() - 1)
            {
                string temp = to_string(array[itr]);
                for (int i=itr+1; i<array.size(); i++)
                {
                    string temp1 = to_string(array[i]);
                    bool check = true;

                    for (int j=0; j<temp.length(); j++)
                    {
                        bool checkItr = false;
                        for (int k=0; k<temp1.length(); k++)
                        {
                            if (temp[j] == temp1[k])
                            {
                                checkItr = true;
                                break;
                            }
                        }

                        if (!checkItr)
                        {
                            check  = false;
                            break;
                        }
                    }

                    if (check)
                        res++;
                    else 
                        break;

                }

                itr++;
            }


            return res;
        }
};

int main ()
{
    cout << "Enter input: " << endl;

    vector<int> array;
    char s;
    string temp = "";
    bool check = false;

    while (1)
    {
        if (check == false)
        {
            if (s == '{')
                check = true;
        }
        else
        {
            if (check && s == ',' || check && s == '}') 
            {
                array.push_back(stoi(temp));
                temp = "";

                if (s == '}')
                    break;
            }
            else
                temp += s;
        }
        
        s = getchar();
    }

 
    FriendlySequences fs;
    int res = fs.count(array);
    cout << "Returns: " << res << endl;

    return 0;
}
