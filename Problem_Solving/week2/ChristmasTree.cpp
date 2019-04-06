/*
 * =====================================================================================
 *
 *       Filename:  ChristmasTree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/13/2019 03:49:28 PM
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
 *      You are decorating your Christmas tree. The tree has N levels, numbered 1 through N from top to bottom. You have a number of red, green and blue baubles, and you've decided to hang them in the following manner: On each level k, you will hang a row of exactly k baubles. Within each row, you will select the colors of the baubles such that there is an equal number of baubles of each color used in that level. For example, consider the following two trees:
 *
 *            R                 R
 *                B   G             B   G 
 *                  R   R   R         R   B   R
 *                  The tree on the left is correctly decorated. Each row contains an equal number of baubles for each color used. The tree on the right, however, is not correctly decorated because the third level contains an unequal number of red and blue baubles.
 *                  You are given an int N, the number of levels in the tree, and ints red, green and blue, representing the number of available baubles in each color. Return the number of distinct correct ways to decorate the tree. Two decorated trees are different if there is at least one position at which the two trees have a different colored bauble. If it is impossible to decorate the tree with the given baubles, return 0.
 *
 *                   
 *                   Definition
 *                          
 *                          Class:ClassChristmasTreeMethod:ClassChristmasTreeMethoddecorationWaysParameters:ClassChristmasTreeMethoddecorationWaysParametersint, int, int, int
 *                          Returns:ReturnslongMethod signature:signaturelong decorationWays(int N, int red, int green, int blue)
 *                          (be sure your method is public)
 *                              
 *                               
 *                               Constraints
 *                               -ConstraintsN will be between 1 and 10, inclusive.
 *                               -inclusivered will be between 0 and 50, inclusive.
 *                               -inclusivegreen will be between 0 and 50, inclusive.
 *                               -inclusiveblue will be between 0 and 50, inclusive.
 *                                
 *                                Examples
 *                                0)        
 *                                2
 *                                1
 *                                1
 *                                1
 *                                Returns: 6
 *                                You can use any of the three colors for the top bauble, which always leaves you with two choices for the second level. Hence, there is a total of six different ways to decorate the tree:
 *                                  R        R  
 *                                  B   G    G   B
 *
 *                                    B        B  
 *                                    R   G    G   R
 *
 *                                      G        G
 *                                      B   R    R   B
 *                                      1)      
 *                                      2
 *                                      2
 *                                      1
 *                                      0
 *                                      Returns: 3
 *                                      If you put the green bauble on the top level, you must put both reds on the second level. On the other hand, if you put the red bauble on the top level, you have two different ways to decorate the second level (red-green or green-red). That makes a total of three ways.
 *                                      2)      
 *                                      3
 *                                      2
 *                                      2
 *                                      1
 *                                      Returns: 0
 *                                      You have only five baubles, while six are needed to cover three levels.
 *                                      3)      
 *                                      3
 *                                      2
 *                                      2
 *                                      2
 *                                      Returns: 36
 *                                      The third level must either have three baubles of the same color or three baubles with different colors. Since you don't have three baubles of the same color, you must use three different colors for that level.
 *                                      4)      
 *                                      8
 *                                      1
 *                                      15
 *                                      20
 *                                      Returns: 197121
 *                                      This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved. 
 *  */

#include <iostream>
#include <vector>

 using namespace std;

 class ChristmasTree
{
public:
    ChristmasTree () { }
    long decorationWays (int N, int red, int green, int blue)
    {
        int sum = 0;
        for (int i=N; i>0; i--)
            sum += i;
        if (red + green + blue < sum || red < 0 || blue < 0 || green < 0)
            return 0;

        long res = 0;
        if (N == 1)
        {
            if (red > 0)
                res++;
            if (green > 0)
                res++;
            if (blue > 0)
                res++;

            return res;
        }
        else
        {
            if (N % 2 != 0 && N % 3 == 0)
            {
                return decorationWays(N-1, red-N, green, blue) + decorationWays(N-1, red, green-N, blue) + decorationWays(N-1, red, green, blue-N)
                    + decorationWays(N-1, red-N/3, green-N/3, blue-N/3);
            }
            else if (N % 2 == 0 && N % 3!= 0)
            {
                return decorationWays(N-1, red-N, green, blue) + decorationWays(N-1, red, green-N, blue) + decorationWays(N-1, red, green, blue-N)
                    + decorationWays(N-1, red-N/2, green-N/2, blue) + decorationWays(N-1, red-N/2, green, blue-N/2) + decorationWays(N-1, red, green-N/2, blue-N/2);
            }
            else if (N % 2 == 0 && N % 3 == 0)
            {
                 return decorationWays(N-1, red-N, green, blue) + decorationWays(N-1, red, green-N, blue) + decorationWays(N-1, red, green, blue-N)
                    + decorationWays(N-1, red-N/3, green-N/3, blue-N/3) + decorationWays(N-1, red-N/2, green-N/2, blue) + decorationWays(N-1, red-N/2, green, blue-N/2) 
                    + decorationWays(N-1, red, green-N/2, blue-N/2);
            }

            return decorationWays(N-1, red-N, green, blue) + decorationWays(N-1, red, green-N, blue); decorationWays(N-1, red, green, blue-N);
        }
    }
};

int main ()
{
    cout << "Enter the input: " << endl;
    int N, red, green, blue;
    scanf("%d", &N);
    scanf("%d", &red);
    scanf("%d", &green);
    scanf("%d", &blue);

    ChristmasTree ct;
    long res = ct.decorationWays(N, red, green, blue);

    cout << "The result is: " << res << endl;
    return 0;
}
