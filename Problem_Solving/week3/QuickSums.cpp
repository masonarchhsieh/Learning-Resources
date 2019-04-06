/*
 * =====================================================================================
 *
 *       Filename:  QuickSums.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/14/2019 03:37:11 PM
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
 *      Given a string of digits, find the minimum number of additions required for the string to equal some target number. Each addition is the equivalent of inserting a plus sign somewhere into the string of digits. After all plus signs are inserted, evaluate the sum as usual. For example, consider the string "12" (quotes for clarity). With zero additions, we can achieve the number 12. If we insert one plus sign into the string, we get "1+2", which evaluates to 3. So, in that case, given "12", a minimum of 1 addition is required to get the number 3. As another example, consider "303" and a target sum of 6. The best strategy is not "3+0+3", but "3+03". You can do this because leading zeros do not change the result.
 *      Write a class QuickSums that contains the method minSums, which takes a String numbers and an int sum. The method should calculate and return the minimum number of additions required to create an expression from numbers that evaluates to sum. If this is impossible, return -1.
 *       
 *       Definition
 *              
 *              Class:ClassQuickSumsMethod:ClassQuickSumsMethodminSumsParameters:ClassQuickSumsMethodminSumsParametersString, int
 *              Returns:ReturnsintMethod signature:signatureint minSums(String numbers, int sum)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintsnumbers will contain between 1 and 10 characters, inclusive.
 *                   -inclusiveEach character in numbers will be a digit.
 *                   -digitsum will be between 0 and 100, inclusive.
 *                    
 *                    Examples
 *                    0)        
 *                    "99999"
 *                    45
 *                    Returns: 4
 *                    In this case, the only way to achieve 45 is to add 9+9+9+9+9. This requires 4 additions.
 *                    1)        
 *                    "1110"
 *                    3
 *                    Returns: 3
 *                    Be careful with zeros. 1+1+1+0=3 and requires 3 additions.
 *                    2)        
 *                    "0123456789"
 *                    45
 *                    Returns: 8
 *                    3)        
 *                    "99999"
 *                    100
 *                    Returns: -1
 *                    4)        
 *                    "382834"
 *                    100
 *                    Returns: 2
 *                    There are 3 ways to get 100. They are 38+28+34, 3+8+2+83+4 and 3+82+8+3+4. The minimum required is 2.
 *                    5)        
 *                    "9230560001"
 *                    71
 *                    Returns: 4
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

class QuickSums
{
    public:
        QuickSums () {}
        int minSums (string numbers, int sum)
        {
            int res = getMins(numbers, sum, 0);
            if (res >= 100)
                return -1;
            else
                return res;
        }

        int getMins (string numbers, int remSum, int prev)
        {
            if (prev > remSum || (numbers.length() == 1 && remSum > prev + stoi(numbers)))
                return 100000;
            else if ((stoull(numbers) == remSum && prev == 0) ||
                    (stoull(numbers) + prev == remSum))
                return 0;
            
            else
            {
                string num, rem;
                for (int i=0; i<numbers.length(); i++)
                {
                    if (i==0)
                        num = numbers[i];
                    else
                        rem += numbers[i];
                }

                return  min(1 + getMins(rem, remSum - (prev + stoi(num)), 0), getMins(rem, remSum, 10 * (prev + stoi(num))));
            }
        }


};

int main ()
{
    cout << "Enter your input:" << endl;
    char numbers[20];
    int sum;
    scanf ("%s", numbers);
    scanf ("%d", &sum);

    QuickSums qs;
    int res = qs.minSums(numbers, sum);
    cout << "The result is: " << res << endl;
    
    return 0;
}
