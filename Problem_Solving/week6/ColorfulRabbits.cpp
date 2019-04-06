/*
 * =====================================================================================
 *
 *       Filename:  ColorfulRabbits.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/19/2019 09:03:42 PM
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
 *      Cat Pochi visited a town of rabbits and asked some of the rabbits the following question: "How many rabbits in this town other than yourself have the same color as you?". The rabbits all replied truthfully, and no rabbit was asked the question more than once. You are given the rabbits' replies in the int[] replies. Return the minimum possible number of rabbits in this town.
 *       
 *       Definition
 *              
 *              Class:ClassColorfulRabbitsMethod:ClassColorfulRabbitsMethodgetMinimumParameters:ClassColorfulRabbitsMethodgetMinimumParametersint[]
 *              Returns:ReturnsintMethod signature:signatureint getMinimum(int[] replies)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintsreplies will contain between 1 and 50 elements, inclusive.
 *                   -inclusiveEach element of replies will be between 0 and 1,000,000, inclusive.
 *                    
 *                    Examples
 *                    0)        
 *                    { 1, 1, 2, 2 }
 *                    Returns: 5
 *                    If there are 2 rabbits with a color and 3 rabbits with another color, Pochi can get this set of replies. 
 *
 *
 *
 *
 *                    1)        
 *                    { 0 }
 *                    Returns: 1
 *                    A poor lonely rabbit.
 *                    2)        
 *                    { 2, 2, 44, 2, 2, 2, 444, 2, 2 }
 *                    Returns: 499
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class ColorfulRabbits
{
    map<int, int> mymaps;
    vector<int> sets;
    vector<int> taken;

    public:
        ColorfulRabbits () {}
        int getMinimum (vector<int> replies)
        {
            int res = 0;
            
            for (int i=0; i<replies.size(); i++)
            {
                bool check = true;
                for (int j=0; j<sets.size(); j++)
                {
                    if (sets[j] == replies[i] && taken[j] <= replies[i])
                    {
                        taken[j]++;
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    sets.push_back(replies[i]);
                    taken.push_back(1);
                }
            }

            for (int i=0; i<sets.size(); i++)
                res += (1 + sets[i]);

            return res;
        }
};

int main ()
{
    cout << "Enter input: " << endl;
    
    vector<int> replies;
    char s;
    string temp = "";
    bool check = false;

    while (s != '}')
    {
        s = getchar();
        if (check == false)
        {
            if (s == '{')
                check = true;
        }
        else
        {
            if (s == ',' || s == '}')
            {
                replies.push_back(stoi(temp)); 

                if (s == '}')
                {
                    check = false;
                    break;
                }    

                temp = "";
            }
            else
                temp += s;
        }
    }

    ColorfulRabbits cr;
    int res = cr.getMinimum(replies);
    cout << "Returns: " << res << endl;

    return 0;
}
