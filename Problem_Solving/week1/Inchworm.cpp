/*
 * =====================================================================================
 *
 *       Filename:  Inchworm.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/10/2019 03:18:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */
/* 
 
Problem Statement
        
   The inchworm is a creature of regular habits. She inches forward some distance along the branch of a tree, then stops to rest. If she has stopped at a leaf, she makes a meal of it. Then she inches forward the same distance as before, and repeats this routine until she has reached or passed the end of the branch.

   Consider an inchworm traveling the length of a branch whose leaves are spaced at uniform intervals. Depending on the distance between her resting points, the inchworm may or may not be able to eat all of the leaves. There is always a leaf at the beginning of the branch, which is where the inchworm rests before setting out on her journey.

   You are given three int values that specify, in inches: the length of the branch; the distance traveled by the inchworm between rests; and the distance between each consecutive pair of leaves. Given that the inchworm only eats at rest, calculate the number of leaves she will consume.

    
   Definition
        
Class:ClassInchwormMethod:ClassInchwormMethodlunchtimeParameters:ClassInchwormMethodlunchtimeParametersint, int, int
Returns:ReturnsintMethod signature:signatureint lunchtime(int branch, int rest, int leaf)
(be sure your method is public)
    
 
Notes
-NotesThe inchworm starts by gobbling up the leaf at the beginning of the branch.
-branchIf there is a leaf at the end of the branch, the inchworm eats it only if it falls at a resting point.
 
Constraints
-Constraintsbranch is between 1 and 1000000 (one million), inclusive
-inclusiverest is between 1 and 1000, inclusive
-inclusiveleaf is between 1 and 1000, inclusive
 
Examples
0)      
11
2
4
Returns: 3
Leaves grow 0, 4, and 8 inches from the beginning of the branch. The inchworm eats them all.
1)      
12
6
4
Returns: 2
The inchworm misses the leaves growing at distances 4 and 8, but eats those at 0 and 12.
2)      
20
3
7
Returns: 1
The inchworm eats only the leaf at the outset.
3)      
21
7
3
Returns: 2
The inchworm eats the leaves at the beginning and end of the branch.
4)      
15
16
5
Returns: 1
The inchworm eats only the leaf at the outset.
5)      
1000
3
7
Returns: 48
6)      
1000
7
3
Returns: 48

 * */
#include <iostream>

using namespace std;

class Inchworm
{
public:
    Inchworm () {}
    int lunchtime (int branch, int rest, int leaf) 
    {
        int count = 0;
        for (int i=0; i<=branch; i+=rest)
            if (i % leaf == 0)
                count++;
        return count;
    }
};

int main() 
{
    printf ("Enter branch, rest, leaf:\n");
    int branch, rest, leaf;
    scanf ("%d", &branch);
    scanf ("%d", &rest);
    scanf ("%d", &leaf);
 
    Inchworm iw;
    int res = iw.lunchtime(branch, rest, leaf);
    printf ("The result is: %d\n", res);
    
    return 0;
}
