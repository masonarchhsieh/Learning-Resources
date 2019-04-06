/*
 * =====================================================================================
 *
 *       Filename:  EggCartons.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/11/2019 04:09:16 PM
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
 *      There are two types of egg cartons. One type contains 6 eggs and the other type contains 8 eggs. John wants to buy exactly n eggs. Return the minimal number of egg cartons he must buy. If it's impossible to buy exactly n eggs, return -1.
 *       
 *       Definition
 *              
 *              Class:ClassEggCartonsMethod:ClassEggCartonsMethodminCartonsParameters:ClassEggCartonsMethodminCartonsParametersintReturns:ClassEggCartonsMethodminCartonsParametersintReturnsintMethod signature:signatureint minCartons(int n)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintsn will be between 1 and 100, inclusive.
 *                    
 *                    Examples
 *                    0)        
 *                    20
 *                    Returns: 3
 *                    He should buy 2 cartons containing 6 eggs and 1 carton containing 8 eggs. In total, he buys 3 egg cartons.
 *                    1)        
 *                    24
 *                    Returns: 3
 *                    There are two ways to buy 24 eggs: buy 4 cartons containing 6 eggs or buy 3 cartons containing 8 eggs. Minimize the number of cartons.
 *                    2)        
 *                    15
 *                    Returns: -1
 *                    He can't buy an odd number of eggs.
 *                    3)        
 *                    4
 *                    Returns: -1
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved. */

#include <iostream>

using namespace std;

class EggCartons
{
private:

public:
    EggCartons () {}
    int minCartons (int n)
    {
        int res = -1;

        for (int i =n/8; i>=0; i--)
        {
            if (n%8 == 0) { res = i; break; }
            else
            {
                if ((n - 8 * i) % 6 == 0) { res = i + (n - 8 * i) / 6; break; }
            }
        }

        return res;
    }
};

int main ()
{
    int n;
    printf("Enter the N:\n");
    scanf("%d", &n);

    EggCartons ec;
    int res = ec.minCartons(n);
    printf("The result is: %d\n", res);

    return 0;
}
