/*
 * =====================================================================================
 *
 *       Filename:  ElevatorLimit.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2019 04:00:55 PM
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
 *      Often the maintenance staff of a large building wants to verify that the elevator in the building is being used appropriately. The manufacturer designates safety limits regarding the maximum number of people that should be on the elevator at the same time. Also, there is a physical limitation as to how many people can actually be in the elevator simultaneously. The building in question has very primitive sensing equipment, and only has data telling how many people entered and exited on a particular stop. That is, the data does not explicitly state how many people were on the elevator at any given point in time.
 *
 *      You are to write a class ElevatorLimit, with a method getRange, which takes as parameters a int[] enter, a int[] exit, and an int physicalLimit, where the ith element in each int[] indicates the number of people that entered and exited, respectively, the elevator on the ith stop. At each stop people exit the elevator first, and then people enter. physicalLimit is how many people are physically capable of being in the elevator simultaneously. You are to determine the maximum and minimum numbers of people that could have been on the elevator before the simulation begins, and return these values in a int[] containing exactly two elements. The first element of the return value is the minimum, and the second element is the maximum number.
 *
 *      If the data entered yields an impossible situation, you are to return an empty int[].
 *
 *       
 *       Definition
 *              
 *              Class:ClassElevatorLimitMethod:ClassElevatorLimitMethodgetRangeParameters:ClassElevatorLimitMethodgetRangeParametersint[], int[], int
 *              Returns:Returnsint[]
 *              Method signature:signatureint[] getRange(int[] enter, int[] exit, int physicalLimit)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintsenter and exit will have between 1 and 50 elements, inclusive.
 *                   -inclusiveenter and exit will have the same number of elements.
 *                   -elementsEach element of enter and exit will be between 0 and 1000, inclusive.
 *                   -inclusivephysicalLimit will be between 1 and 1000, inclusive.
 *                    
 *                    Examples
 *                    0)        
 *                    {1,0}
 *                    {0,1}
 *                    1
 *                    Returns: { 0,  0 }
 *                    With a physicalLimit of one person on the elevator at a time, there had to be 0 to start with.
 *                    1)        
 *                    {1,0}
 *                    {0,1}
 *                    2
 *                    Returns: { 0,  1 }
 *                    With a physicalLimit of 2 people, the elevator could have started with 0 or 1 people on it.
 *                    2)        
 *                    {0,1}
 *                    {1,0}
 *                    1
 *                    Returns: { 1,  1 }
 *                    3)        
 *                    {0,2}
 *                    {1,0}
 *                    1
 *                    Returns: { }
 *                    Since there is only a maximum of 1 person, 2 people cannot get on at the second stop. Therefore, there is no possible solution.
 *                    4)        
 *                    {6, 85, 106, 1, 199, 76, 162, 141} 
 *                    {38, 68, 62, 83, 170, 12, 61, 114} 
 *                    668
 *                    Returns: { 223,  500 }
 *                    5)        
 *                    {179, 135, 104, 90, 97, 186, 187, 47, 152, 100, 119, 28, 193, 11, 103, 100,
 *                     179, 11, 80, 163, 50, 131, 103, 50, 142, 51, 112, 62, 69, 72, 88, 3, 162,
 *                      93, 190, 85, 79, 86, 146, 71, 65, 131, 179, 119, 66, 111} 
 *                      {134, 81, 178, 168, 86, 128, 1, 165, 62, 46, 188, 70, 104, 111, 3, 47, 144,
 *                       69, 163, 21, 101, 126, 169, 84, 146, 165, 198, 1, 65, 181, 135, 99, 100,
 *                        195, 171, 47, 16, 54, 79, 69, 6, 97, 154, 80, 151, 76} 
 *                        954
 *                        Returns: { 453,  659 }
 *                        6)        
 *                        {2}
 *                        {3}
 *                        2
 *                        Returns: { }
 *                        This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved. */

#include <iostream>
#include <vector>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class ElevatorLimit
{
public:
    ElevatorLimit () {}
    vector<int> getRange (vector<int> enter, vector<int> exit, int physicalLimit)
    {
        vector<int> res;
        int min, max, numMin, numMax;
        bool chance = true;

        min = 0;
        max = 0;
        numMax = 0;
        numMin = 0;
        
        vector<int> step;
        for (int i=0; i<enter.size(); i++)
        {
            if (enter[i] > physicalLimit || exit[i] > physicalLimit) { chance = false; break; }
       
            if ((numMin = numMin - exit[i]) < 0)
            {
                min += abs(numMin);
                numMin = 0 + enter[i];
            }
            else { numMin += enter[i]; }

            if ((numMax = numMax + enter[i] - exit[i])  > max)
                max = numMax;
        } 

        if (chance)
        { 
            res.push_back(min);
            res.push_back(physicalLimit - max);
        }

        return res;
    }

};

int main ()
{
    
    printf("Enter the enter:\n");
    vector<int> enter;
    vector<int> exit;

    int limit;
    
    char s;
    string temp = "";
    bool check = false;
    int type = 0;

    while (type < 2)
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
                if (type == 0)
                    enter.push_back(stoi(temp));
                else
                    exit.push_back(stoi(temp));

                temp = "";

                if (s == '}')
                {
                    check = false;
                    type++;
                }
            }
            else
                temp += s;
        }
    }
    scanf("%d", &limit);


    ElevatorLimit el;
    vector<int> res = el.getRange(enter, exit, limit);
    printf("The result is:\n");
    for (int i=0; i<res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
