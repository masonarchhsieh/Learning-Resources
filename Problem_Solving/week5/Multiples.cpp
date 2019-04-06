/*
 * =====================================================================================
 *
 *       Filename:  Multiples.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/16/2019 03:14:04 PM
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
 *      You are to create a class Multiples with a method number, which takes three ints: min, max, and factor.
 *
 *      Given a range of integers from min to max (inclusive), determine how many numbers within that range are evenly divisible by factor.
 *
 *       
 *       Definition
 *              
 *              Class:ClassMultiplesMethod:ClassMultiplesMethodnumberParameters:ClassMultiplesMethodnumberParametersint, int, int
 *              Returns:ReturnsintMethod signature:signatureint number(int min, int max, int factor)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Notes
 *                   -NotesIf x is evenly divisble by y, there exists some integer k such that k * y = x.
 *                    
 *                    Constraints
 *                    -Constraintsmin will be between -1000000 and 1000000, inclusive.
 *                    -inclusivemax will be between -1000000 and 1000000, inclusive.
 *                    -inclusivemax will be greater than or equal to min.
 *                    -minfactor will be between 1 and 1000, inclusive.
 *                     
 *                     Examples
 *                     0)       
 *                     0
 *                     14
 *                     5
 *                     Returns: 3
 *                     The numbers 0, 5, and 10 are evenly divisible by 5, so this returns 3.
 *                     1)       
 *                     7
 *                     24
 *                     3
 *                     Returns: 6
 *                     The numbers 9, 12, 15, 18, 21, 24 are evenly divisible by 3, so this returns 6.
 *                     2)       
 *                     -123456
 *                     654321
 *                     997
 *                     Returns: 780
 *                     3)       
 *                     -75312
 *                     407891
 *                     14
 *                     Returns: 34515
 *                     This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.
 *
 *                         
 */

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

class Multiples
{
    public:
        Multiples () {}
        int number (int min, int max, int factor)
        {
            int res = 0;

            for (int i=min; i<=max; i++)
            {
                if (i % factor == 0)
                    res++;
            }

            return res;
        }
};


int main ()
{
    cout << "Enter input:" << endl;
    int min, max, factor;
    scanf ("%d", &min);
    scanf ("%d", &max);
    scanf ("%d", &factor);

    Multiples m;
    int res = m.number(min, max, factor);

    cout << "Returns: " << res << endl;
}
