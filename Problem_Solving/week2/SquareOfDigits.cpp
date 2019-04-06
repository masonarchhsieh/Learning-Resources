/*
 * =====================================================================================
 *
 *       Filename:  SquareOfDigits.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/11/2019 09:38:28 PM
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
 *      You are given a String[] data representing a rectangular grid where each cell contains a digit. Find the largest square in this grid that contains the same digit in all of its corner cells. The sides of the square must be parallel to the sides of the grid. If there is more than one such largest square, pick any one of them. 
 *
 *      Return the number of cells in the square. Note that a single cell is also considered a square, so there will always be an answer.
 *       
 *       Definition
 *              
 *              Class:ClassSquareOfDigitsMethod:ClassSquareOfDigitsMethodgetMaxParameters:ClassSquareOfDigitsMethodgetMaxParametersString[]
 *              Returns:ReturnsintMethod signature:signatureint getMax(String[] data)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintsdata will contain between 1 and 50 elements, inclusive.
 *                   -inclusiveEach element of data will contain between 1 and 50 digits ('0'-'9'), inclusive.
 *                   -inclusiveAll elements of data will have the same length.
 *                    
 *                    Examples
 *                    0)        
 *                    {"12",
 *                     "34"}
 *                     Returns: 1
 *                     All digits in the grid are different, so the biggest feasible square has only one cell.
 *                     1)       
 *                     {"1255",
 *                      "3455"}
 *                      Returns: 4
 *                      Four '5' digits form a feasible square.
 *                      2)      
 *                      {"42101",
 *                       "22100",
 *                        "22101"}
 *                        Returns: 9
 *                        The largest square here is the 3 x 3 square that contains the digit '1' in each of its corner cells.
 *                        3)        
 *                        {"1234567890"}
 *                        Returns: 1
 *                        4)        
 *                        {"9785409507",
 *                         "2055103694",
 *                          "0861396761",
 *                           "3073207669",
 *                            "1233049493",
 *                             "2300248968",
 *                              "9769239548",
 *                               "7984130001",
 *                                "1670020095",
 *                                 "8894239889",
 *                                  "4053971072"}
 *                                  Returns: 49
 *                                  This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SquareOfDigits
{
    public:
        SquareOfDigits () {}
        int getMax(vector<string> data)
        {
            int res = 0;
            
            for (int i=0; i<data.size(); i++)
            {
                for (int j=0; j<data[i].length(); j++)
                {
                    for (int k=0; ; k++)
                    {
                        if (i + k >= data.size() || i + k >= data[0].length())  break;
                        else
                        {
                            if (data[i][j] == data[i+k][j] && data[i][j] == data[i+k][j+k] &&
                                    data[i][j] == data[i][j+k])
                            {
                                if ((k + 1) * (k + 1) > res)
                                    res = (k + 1) * (k + 1);
                            }
                        }
                    }
                }
            }

            return res;
        }
};
