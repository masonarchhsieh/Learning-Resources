/*
 * =====================================================================================
 *
 *       Filename:  NumberSplit.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/16/2019 03:21:00 PM
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
 *      We start with an integer and create a sequence of successors using the following procedure: First split the decimal representation of the given number into several (at least two) parts, and multiply the parts to get a possible successor. With the selected successor, we repeat this procedure to get a third number, and so on, until we reach a single-digit number.
 *
 *      For example, let's say we start with the number 234. The possible successors are:
 *
 *      23 * 4 = 92,
 *      2 * 34 = 68 and
 *      2 * 3 * 4 = 24.
 *      If we select 68 as the successor, we then generate 6 * 8 = 48 (the only possibility), from this we generate 4 * 8 = 32 and finally 3 * 2 = 6. With this selection, we have generated a sequence of 5 integers (234, 68, 48, 32, 6).
 *      Given the starting number, start, return the length of the longest sequence that can be generated with this procedure. In the example, the given sequence would be the longest one since the other selections in the first step would give the sequences: (234, 92, 18, 8) and (234, 24, 8), which are both shorter than (234, 68, 48, 32, 6).
 *
 *       
 *       Definition
 *              
 *              Class:ClassNumberSplitMethod:ClassNumberSplitMethodlongestSequenceParameters:ClassNumberSplitMethodlongestSequenceParametersintReturns:ClassNumberSplitMethodlongestSequenceParametersintReturnsintMethod signature:signatureint longestSequence(int start)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Notes
 *                   -NotesThere can not exist an infinite sequence.
 *                   -sequenceAlthough we use no leading zeros in the decimal representation of the number we start with, the parts we get by splitting the number may have leading zeros (e.g. from 3021 we can get 3 * 021 = 63).
 *                    
 *                    Constraints
 *                    -Constraintsstart is between 1 and 100000, inclusive.
 *                     
 *                     Examples
 *                     0)       
 *                     6
 *                     Returns: 1
 *                     A single-digit number is already the last number.
 *                     1)       
 *                     97
 *                     Returns: 4
 *                     For two-digit numbers, there is always only one possible sequence. Here: 97 -> 63 -> 18 -> 8 (4 numbers).
 *                     2)       
 *                     234
 *                     Returns: 5
 *                     The example from the problem statement.
 *                     3)       
 *                     876
 *                     Returns: 7
 *                     Here, it is optimal to make a three way split in the first step - i.e. use 8*7*6=336 as the first successor. Although a two way split would lead to a larger number (87*6=522 or 8*76=608), both these choices would lead in the end to a shorter sequence. The optimal sequence is: 876, 8*7*6=336, 33*6=198, 19*8=152, 1*52=52, 5*2=10, 1*0=0.
 *                     4)       
 *                     99999
 *                     Returns: 29
 *                     This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;

class NumberSplit
{
    public:
        NumberSplit () {}
        int longestSequence (int start)
        {
            int res = 0;

            vector<int> digits;
            int div = 10;
            while (1)
            {
                digits.push_back(start % 10);
                start /= 10;
                if (start == 0)
                    break;
            }

            reverse(digits.begin(), digits.end());

            return res;
        }

        int count (vector<int> digit)
        {

            if (digit.size() == 1)
                return 1;

            vector<int> res;
            int max;
            for (int numSym=1; numSym<digit.size()-1; numSym++)
            {
                int itr = 0;
                vector<int> mul;
                mul.reserve(numSym);

                while (1)
                {
                    for (int i=0; i<digit.size(); i++)
                    {
                        mul[itr] = mul[itr] * 10 + digit[i];

                        if (itr == i)
                            itr++;
                    }
                }
            
            }


        }

};

int main ()
{
    cout << "Enter input: " << endl;
    int start;
    scanf ("%d", &start);

    NumberSplit ns;
    int res = ns.longestSequence(start);
    cout << "Returns: " << res << endl;

    return 0;
}
