/*
 * =====================================================================================
 *
 *       Filename:  NiceOrUgly.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  01/18/2019 04:21:02 PM
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
 *      A string is called ugly if it has 3 vowels in a row, or 5 consonants in a row, or both. A string is called nice if it is not ugly. You are given a string s, consisting of uppercase letters ('A'-'Z') and question marks ('?'). Return "UGLY" if the string is definitely ugly (that means you cannot substitute letters for question marks so that the string becomes nice), "NICE" if the string is definitely nice, and "42" if it can be either ugly or nice (quotes for clarity only).
 *
 *       Definition
 *
 *              Class:ClassNiceOrUglyMethod:ClassNiceOrUglyMethoddescribeParameters:ClassNiceOrUglyMethoddescribeParametersStringReturns:ClassNiceOrUglyMethoddescribeParametersStringReturnsStringMethod signature:signatureString describe(String s)
 *              (be sure your method is public)
 *
 *
 *                   Notes
 *                   -NotesThe letters 'A', 'E', 'I', 'O', 'U' are vowels, and all others are consonants.
 *
 *                    Constraints
 *                    -Constraintss will contain between 1 and 50 characters, inclusive.
 *                    -inclusiveEach character in s will be either '?', or an uppercase letter ('A'-'Z').
 *
 *                     Examples
 *                     0)
 *                     "HELLOWORLD"
 *                     Returns: "NICE"
 *                     1)
 *                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
 *                     Returns: "UGLY"
 *                     Apparently the English alphabet has 5 consonants in a row.
 *                     2)
 *                     "HELLOW?RLD"
 *                     Returns: "42"
 *                     "HELLOWORLD" is nice, "HELLOWZRLD" is ugly.
 *                     3)
 *                     "H??LOWOR??"
 *                     Returns: "NICE"
 *                     You just can't make it ugly.
 *                     4)
 *                     "EE?FFFF"
 *                     Returns: "UGLY"
 *                     Whatever you put there, it becomes ugly.
 *                     This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.
 * */

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class NiceOrUgly
{
    string NICE = "NICE";
    string UGLY = "UGLY";
    string HYBRID = "42";

    int VOWEL = 0;
    int CONSONANT = 1;
    int UNSURE = 2;

    int nice = 0;
    int ugly = 0;

public:
    NiceOrUgly () {}
    string describe (string s);
};

string NiceOrUgly::describe (string s)
{
    string res = NICE;

    int count_vows = 0;
    int count_consonants = 0;
    int unsure = 0;
    int type = 0;   // type:0, 1, 2: vows, consonants, ?

    for (int i=0; i<s.length(); i++)
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            count_vows++;
            type = VOWEL;
            if (count_vows >= 3)
            {
                res = UGLY;
                break;
            }
            count_consonants = 0;
            unsure = 0;
        }
        else if (s[i] == '?')
        {
            unsure++;
            int prev_type = type;
            type = UNSURE;

            int next_type = type;
            int count_next = 0;
            bool check = false;
            int itr = i + 1;
            // find all continuous '?'
            while (itr < s.length())
            {
                if (s[itr] == 'A' || s[itr] == 'E' || s[itr] == 'I' || s[itr] == 'O' || s[itr] == 'U')
                {
                    check = true;
                    next_type = VOWEL;
                    type = next_type;
                    break;
                }
                else if (s[itr] == '?')
                {
                    unsure++;
                }
                else
                {
                    check = true;
                    next_type = CONSONANT;
                    type = next_type;
                    break;
                }
                itr++;
            }

            i = itr;

            if (check)
            {
                for (int j=itr; j<s.length(); j++)
                {
                    if (next_type == VOWEL && (s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U'))
                    {    
                        count_next++;
                        i = j;
                    }
                    else if (next_type == CONSONANT && s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U' && s[j] != '?')
                    {  
                        count_next++;
                        i = j;
                    }
                    else    break;
                } 
            }


            if (prev_type != next_type && ((prev_type == VOWEL && count_vows >= 2) || (prev_type == CONSONANT && count_consonants >= 4))
                    && ((next_type == VOWEL && count_next >= 2) || (next_type == CONSONANT && count_next >= 4)) && unsure == 1)
            {
                res = UGLY;
                break;
            }
            else if ((count_vows + unsure >= 3 || count_consonants + unsure >= 5) || ((next_type == CONSONANT && count_next + unsure >= 5) ||
                                                                                      (next_type == VOWEL && count_next + unsure >= 3)))
            {
                res = HYBRID;
            }
            else if ((prev_type == next_type && prev_type == VOWEL && (count_next + count_vows + unsure >= 3)) ||
                     (prev_type == next_type && prev_type == CONSONANT && (count_next + count_consonants + unsure >= 5)))
            {
                res = HYBRID;
            }

            unsure = 0;
            count_vows = 0;
            count_consonants = 0;
        }
        else
        {
            count_consonants++;
            type = CONSONANT;
            if (count_consonants >= 5)
            {
                res = UGLY;
                break;
            }
            count_vows = 0;
            unsure = 0;
        }
    }

    return res;
};


int main ()
{
    cout << "Enter input string:" << endl;
    char s[50];
    scanf ("%s", s);

    NiceOrUgly nou;
    string res = nou.describe(s);

    cout << "Returns: " << res << endl;

    return 0;
}
