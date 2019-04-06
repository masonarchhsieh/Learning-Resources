/*
 * =====================================================================================
 *
 *       Filename:  FewestFactors.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/13/2019 09:32:01 PM
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
 *
 * Problem Statement
 *      
 *      You will be given some decimal digits in a int[] digits. Build an integer with the minimum possible number of factors, using each of the digits exactly once (be sure to count all factors, not only the prime factors). If more than one number has the same (minimum) number of factors, return the smallest one among them.
 *
 *       
 *       Definition
 *              
 *              Class:ClassFewestFactorsMethod:ClassFewestFactorsMethodnumberParameters:ClassFewestFactorsMethodnumberParametersint[]
 *              Returns:ReturnsintMethod signature:signatureint number(int[] digits)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Notes
 *                   -NotesA factor of an integer n is an integer k, such that n % k = 0 (% being the modulo operator).
 *                   -operatorThe digit 0 can also be used as a leading zero, see example 1.
 *                    
 *                    Constraints
 *                    -Constraintsdigits will have between 1 and 5 elements, inclusive.
 *                    -inclusiveEach element of digits will be between 0 and 9, inclusive.
 *                    -inclusiveAt least one element of digits will be non-zero.
 *                     
 *                     Examples
 *                     0)       
 *                     {1, 2}
 *                     Returns: 21
 *                     Using the digits 1 and 2 we can build the numbers 12 (which has 6 factors: 1, 2, 3, 4, 6 and 12) and 21 (which has 4 factors: 1, 3, 7 and 21). So we return 21, which is the number among them having the smallest number of factors.
 *
 *                     1)       
 *                     {6, 0}
 *                     Returns: 6
 *                     Note that we can use 0 as a leading zero, giving the number 6 that has 4 factors (1, 2, 3 and 6), less than the alternative 60 that has 12 factors.
 *
 *                     2)       
 *                     {4, 7, 4}
 *                     Returns: 447
 *                     Note that digits may contain duplicate digits. We have to use each digit as many times as it appears in the input.
 *
 *                     3)       
 *                     {1, 3, 7, 9}
 *                     Returns: 1973
 *                     4)       
 *                     {7, 5, 4, 3, 6}
 *                     Returns: 36457
 *                     5)       
 *                     {1,2,4}
 *                     Returns: 241
 *                     Both 241 and 421 are prime numbers, and thus have exactly 2 factors (241 has the factors 1 and 241, while 421 has the factors 1 and 421). All other numbers that we can build from these digits (124, 142, 214 and 412) have more than 2 factors. We have to use the tie-breaker here and return the smaller of (241, 421).
 *                     This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

class FewestFactors
{
    public:
        FewestFactors () {}
        int number (vector<int> digits)
        {
            int res, min, minFac, temp, count;

            min = INT_MAX;
            minFac = INT_MAX;

            int size = digits.size();
            sort(digits.begin(), digits.begin() + digits.size());
            do {
                count = 0;
                temp = 0;
                for (int i=0; i<digits.size(); i++)
                    temp = temp * 10 + digits[i];
                
               int square_root = (int) sqrt(temp) + 1; 
                for (int i=0; i<square_root; i++)
                {
                    if (temp % i == 0 && i * i != temp)
                        count += 2;
                    else if (temp %i == 0 && i * i == temp)
                        count += 1;
                }

                if (minFac > temp)
                {
                    minFac = count;
                    min = temp;
                }

            } while (next_permutation(digits.begin(), digits.end()));
                      

            return res;
        }
};

int main ()
{
    cout << "Enter input: " << endl;

    vector<int> digits;
    char s;
    string temp = "";
    bool check = false;

    while (1)
    {
        s = getchar();

        if (!check)
        {
            if (s == '{') 
                check = true;
        }
        else
        {
            if (check && (s == ',' || s == '}'))
            {
                digits.push_back(stoi(temp));
                temp = "";

                if (s == '}')
                {
                    check = false;
                    break;
                }
            }
            else
                temp += s;
        }
    }

    for (int i=0; i<digits.size(); i++)
    {}
    FewestFactors ff;
    int res = ff.number(digits);

    cout << "The result is: " << res << endl;
   
    return 0;
}
