/*
 * =====================================================================================
 *
 *       Filename:  FracCount.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/13/2019 08:15:24 PM
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
 *      It is possible to assign a unique integer value to each irreducible fraction between 0 and 1. (This shows that there are a countable infinity of fractions.) The usual way to number them is shown below
 *
 *      1/2  1/3  2/3  1/4  3/4  1/5  2/5  3/5  4/5  1/6  5/6  1/7  ...
 *       
 *       Notice that 2/4, for example, does not get listed because it reduces to 1/2. Given an irreducible fraction we want to find where it appears in the above counting order, where 1/2 is counted as 1, 1/3 as 2, etc.
 *       Create a class FracCount that contains a method position that is given the numerator and denominator of an irreducible fraction between 0 and 1 and that returns its position in the counting order.
 *
 *        
 *        Definition
 *              
 *              Class:ClassFracCountMethod:ClassFracCountMethodpositionParameters:ClassFracCountMethodpositionParametersint, int
 *              Returns:ReturnsintMethod signature:signatureint position(int numerator, int denominator)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintsnumerator will be between 1 and denominator - 1 inclusive.
 *                   -inclusivedenominator will be between 2 and 1,000 inclusive.
 *                   -inclusiveThe greatest common divisor of numerator and denominator will be 1.
 *                    
 *                    Examples
 *                    0)        
 *                    1
 *                    2
 *                    Returns: 1
 *                    1/2 is at position 1 in the counting order
 *                    1)        
 *                    5
 *                    6
 *                    Returns: 11
 *                    5/6 is at position 11 in the counting order
 *                    2)        
 *                    999
 *                    1000
 *                    Returns: 304191
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.
 */

#include <iostream>

using namespace std;

class FracCount
{
    public:
        FracCount () {}
        int position (int numerator, int denominator)
        {
            int res = 0;
            while (1)
            {
                if (GCD (numerator, denominator) == 1)
                { 
                    res++;
                    if (numerator == 1 && denominator == 2)
                        break;
                }

                numerator--;
                if (numerator == 0)
                {
                    denominator--;
                    numerator = denominator - 1;
                }
            }
            
            return res;
        }

        int GCD(int numerator, int denominator)
        {
            int c = 0;
            while (numerator != 0)
            {
                c = numerator;
                numerator = denominator % numerator;
                denominator = c;
            }

            return denominator;
        }
};

int main ()
{
    cout << "Enter the inputs:" << endl;
    int num, denum;

    scanf("%d", &num);
    scanf("%d", &denum);

    FracCount fc;
    int res = fc.position(num, denum);
    cout << "The result is: " << res << endl;

    return 0;
}
