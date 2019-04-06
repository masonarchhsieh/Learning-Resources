/*
 * =====================================================================================
 *
 *       Filename:  UnsealTheSafe.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/15/2019 05:32:45 PM
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
 *  Problem Statement
 *          
 *          A door of a safe is locked by a password. Josh witnessed an employee opening the safe. Here is the information Josh spied.
 *
 *          The password is a sequence containing exactly N digits..
 *          The password is entered using the keypad shown in the picture below.
 *          Every pair of neighboring digits in the password is adjacent on the keypad. Two digits are adjacent on the keypad if they are distinct and have a common edge.
 *
 *
 *          Josh has evil intentions of unsealing the safe, but before he can realize his plan, he wants to know how many different passwords exist. Given the value for N, return the number of possible passwords that satisfy all the constraints given above.
 *
 *           
 *           Definition
 *                  
 *                  Class:ClassUnsealTheSafeMethod:ClassUnsealTheSafeMethodcountPasswordsParameters:ClassUnsealTheSafeMethodcountPasswordsParametersintReturns:ClassUnsealTheSafeMethodcountPasswordsParametersintReturnslongMethod signature:signaturelong countPasswords(int N)
 *                  (be sure your method is public)
 *                      
 *                       
 *                       Constraints
 *                       -ConstraintsN will be between 2 and 30, inclusive.
 *                        
 *                        Examples
 *                        0)        
 *                        2
 *                        Returns: 26
 *                        if the first button is 1, the second button can be either 2 or 4
 *                        if the first button is 2, the second button can be either 1, 3 or 5
 *                        if the first button is 3, the second button can be either 2 or 6
 *                        if the first button is 4, the second button can be either 1, 5 or 7
 *                        if the first button is 5, the second button can be either 2, 4, 6 or 8
 *                        if the first button is 6, the second button can be either 3, 5 or 9
 *                        if the first button is 7, the second button can be either 4, 8 or 0
 *                        if the first button is 8, the second button can be either 5, 7 or 9
 *                        if the first button is 9, the second button can be either 6 or 8
 *                        if the first button is 0, the second button can be 7 only
 *                        1)        
 *                        3
 *                        Returns: 74
 *                        2)        
 *                        25
 *                        Returns: 768478331222
 *                        This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.
 *  */

#include <iostream>
#include <algorithm>

using namespace std;

class UnsealTheSafe
{
    long array[10][2];
    public:
        UnsealTheSafe () {}
        long countPasswords (int N)
        {
            long res = 0;
            /* setup */
            for (int i=0; i<10; i++)
            {
                array[i][0] = 1;
                array[i][1] = 0;
            }


            while (N > 1)
            {
                for (int i=0; i<10; i++)
                {
                    switch (i)
                    {
                        case 1:
                            array[2][1] += array[i][0];
                            array[4][1] += array[i][0];
                            break;
                        case 2:
                            array[1][1] += array[i][0];
                            array[3][1] += array[i][0];
                            array[5][1] += array[i][0];
                            break;
                        case 3:
                            array[2][1] += array[i][0];
                            array[6][1] += array[i][0];
                            break;;
                        case 4:
                            array[1][1] += array[i][0];
                            array[5][1] += array[i][0];
                            array[7][1] += array[i][0];
                            break;
                        case 5:
                            array[2][1] += array[i][0];
                            array[4][1] += array[i][0];
                            array[6][1] += array[i][0];
                            array[8][1] += array[i][0];
                            break;
                        case 6:
                            array[3][1] += array[i][0];
                            array[5][1] += array[i][0];
                            array[9][1] += array[i][0];
                            break;
                        case 7:
                            array[4][1] += array[i][0];
                            array[8][1] += array[i][0];
                            array[0][1] += array[i][0];
                            break;
                        case 8:
                            array[5][1] += array[i][0];
                            array[7][1] += array[i][0];
                            array[9][1] += array[i][0];
                            break;
                        case 9:
                            array[6][1] += array[i][0];
                            array[8][1] += array[i][0];
                            break;
                        case 0:
                            array[7][1] += array[i][0];
                            break; 
                    }
                }

                for (int i=0; i<10; i++)
                {
                    array[i][0] = array[i][1];
                    array[i][1] = 0;
                }

                N--;
            }

            for (int i=0; i<10; i++)
                res += array[i][0];

            return res;
        }

};

int main ()
{
    cout << "Enter input" << endl;
    int N;
    scanf("%d", &N);

    UnsealTheSafe uts;
    long res = uts.countPasswords(N);
    cout << "Returns: " << res << endl;

    return 0;
}
