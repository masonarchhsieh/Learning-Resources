/*
 * =====================================================================================
 *
 *       Filename:  SimpleCompressor.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/13/2019 09:03:47 PM
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
 *      A simple way to shorten a string is to encode repeated consecutive substrings as a counter followed by the substring. For example, if X represents a substring, and the string contains a sequence "XX...X", we can shorten the sequence as "[DX]", where D is the number of times X is repeated (D is a single digit, i.e., 1 <= D <= 9). X itself might contain some shortened substrings as well. For example, the string "CABABABABABABC" can be shortened as "C[6AB]C" or "C[2[3AB]]C". You are given a String data. Calculate the original string that was shortened to produce data and return the result. The expanded string will contain only uppercase letters ('A'-'Z').
 *       
 *       Definition
 *              
 *              Class:ClassSimpleCompressorMethod:ClassSimpleCompressorMethoduncompressParameters:ClassSimpleCompressorMethoduncompressParametersStringReturns:ClassSimpleCompressorMethoduncompressParametersStringReturnsStringMethod signature:signatureString uncompress (String data)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -ConstraintsThe return value will contain between 1 and 1000 characters, inclusive.
 *                   -inclusiveThe return value will contain only uppercase letters ('A'-'Z').
 *                   -lettersdata will contain between 1 and 50 characters, inclusive.
 *                   -inclusivedata will contain only uppercase letters ('A'-'Z'), digits ('1'-'9'), and brackets ('[' and ']').
 *                   -anddata will be a properly compressed string.
 *                   -stringIn each occurrence of "[DX]", D will be a single digit, between 1 and 9, inclusive.
 *                   -inclusiveIn each occurrence of "[DX]", X will be a non-empty string.
 *                    
 *                    Examples
 *                    0)        
 *                    "C[6AB]C"
 *                    Returns: "CABABABABABABC"
 *                    1)        
 *                    "C[2[3AB]]C"
 *                    Returns: "CABABABABABABC"
 *                    2)        
 *                    "CO[1N]TEST"
 *                    Returns: "CONTEST"
 *                    3)        
 *                    "[2[2AB]]"
 *                    Returns: "ABABABAB"
 *                    4)        
 *                    "AAAAAAAAAAAAAAAAAAAAA"
 *                    Returns: "AAAAAAAAAAAAAAAAAAAAA"
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <string>

using namespace std;

class SimpleCompressor
{
    public:
        SimpleCompressor () {}
        string uncompress (string data)
        {
            string res = "";
            int itr = 1;
            int prev = 1;
            int check = 0;
            string temp = "";

            for (int i=0; i<data.length(); i++)
            {
                if (data[i] == '[')
                {
                    check++;
                    string tempInt;
                    tempInt = data[i+1];

                    itr *= stoi(tempInt);
                    i++;
                }
                else if (data[i] == ']')
                {   
                    for (int j=0; j<itr; j++)
                        res += temp;

                    temp = "";
                    itr /= prev;
                    check--;
                }
                else
                {
                    if (check == 0)
                        res += data[i];
                    else
                        temp += data[i];
                }  
            }

            return res;
        }
};

int main ()
{
    cout << "Enter string: " << endl;
    char data[50];
    scanf("%s", data);

    SimpleCompressor sc;
    string res = sc.uncompress(data);
    cout << "The result is: " << res << endl;

    return 0;
}
