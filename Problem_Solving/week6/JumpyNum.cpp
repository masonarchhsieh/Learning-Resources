/*
 * =====================================================================================
 *
 *       Filename:  JumpyNum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/19/2019 08:47:14 PM
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
 *      A jumpy number is a positive integer, all of whose adjacent digits differ by at least 2. For example,
 *              
 *                      NOT JUMPY: 28459, 28549, 1091919, 97753, 111111
 *                                  JUMPY: 290464, 13131313, 97539753, 5
 *                                  Create a class JumpyNum that contains a method howMany that is given low and high and returns the number of jumpy numbers that are between low and high, inclusive.
 *                                   
 *                                   Definition
 *                                          
 *                                          Class:ClassJumpyNumMethod:ClassJumpyNumMethodhowManyParameters:ClassJumpyNumMethodhowManyParametersint, int
 *                                          Returns:ReturnsintMethod signature:signatureint howMany(int low, int high)
 *                                          (be sure your method is public)
 *                                              
 *                                               
 *                                               Constraints
 *                                               -Constraintslow is between 1 and 2,000,000,000, inclusive.
 *                                               -inclusivehigh is between low and 2,000,000,000, inclusive.
 *                                                
 *                                                Examples
 *                                                0)        
 *                                                1
 *                                                10
 *                                                Returns: 9
 *                                                All the single digit numbers are jumpy, but 10 isn't since 1 and 0 differ by only 1.
 *                                                1)        
 *                                                9
 *                                                23
 *                                                Returns: 9
 *                                                The jumpy ones are 9,13,14,15,16,17,18,19,20
 *                                                2)        
 *                                                2000000000
 *                                                2000000000
 *                                                Returns: 0
 *                                                3)        
 *                                                8000
 *                                                20934
 *                                                Returns: 3766
 *                                                This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class JumpyNum
{
    map<pair<int, int>, int> m;

    public:
        JumpyNum () {}
        int howMany (int low, int high);   
        int calc (int num);
        int solve (int low, int high);        
};

int JumpyNum::howMany (int low, int high)
{
    
}


int JumpyNum::calc (int num)
{

}

int JumpyNum::solve (int low, int high)
{

}








