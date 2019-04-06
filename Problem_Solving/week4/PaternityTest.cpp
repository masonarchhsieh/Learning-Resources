/*
 * =====================================================================================
 *
 *       Filename:  PaternityTest.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/15/2019 04:48:13 PM
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
 *      DNA testing is one of the most popular methods of establishing paternity. In such a test, you compare samples of DNA from the man, the child, and the child's mother. For the purposes of this problem, assume that each sample is represented as a String of uppercase letters ('A'-'Z'). If half of the characters in the child's sample match the characters in the corresponding positions in the man's sample, and the remaining characters in the child's sample match the characters in the corresponding positions in the mother's sample, then the man is most likely the father. On the other hand, if it is impossible to partition the child's sample such that half of the characters match the man's and the other half match the mother's, then the man is definitely ruled out as the father.
 *
 *      For example, suppose the child's sample is "ABCD" and the mother's sample is "AXCY" (all quotes for clarity only). The 'A' and 'C' in the child's sample must have come from the mother, so the 'B' and 'D' must have come from the father. If the man's sample is "SBTD", then he is most likely the father, but if the man's sample is "QRCD", then he is definitely not the father. Note in the latter case that the man was definitely ruled out even though half of his sample (the 'C' and 'D') did in fact match the child's.
 *
 *      Your method will take samples from the child and the mother, as well as samples from several men, and return the indices of the men who cannot be ruled out as the father, in increasing order.
 *
 *       
 *       Definition
 *              
 *              Class:ClassPaternityTestMethod:ClassPaternityTestMethodpossibleFathersParameters:ClassPaternityTestMethodpossibleFathersParametersString, String, String[]
 *              Returns:Returnsint[]
 *              Method signature:signatureint[] possibleFathers(String child, String mother, String[] men)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Notes
 *                   -NotesYou may assume that the identity of the mother is not in question.
 *                    
 *                    Constraints
 *                    -Constraintsmen contains between 1 and 5 elements, inclusive.
 *                    -inclusivechild, mother, and all elements of men contain the same number of characters, which is even and between 2 and 20, inclusive.
 *                    -inclusivechild, mother, and all elements of men contain only uppercase letters ('A'-'Z').
 *                    -lettersAt least half of the characters in mother match the characters in the corresponding positions in child.
 *                     
 *                     Examples
 *                     0)       
 *                     "ABCD"
 *                     "AXCY"
 *                     { "SBTD", "QRCD" }
 *                     Returns: { 0 }
 *                     The example above.
 *                     1)       
 *                     "ABCD"
 *                     "ABCX"
 *                     { "ABCY", "ASTD", "QBCD" } 
 *                     Returns: { 1,  2 }
 *                     "ABCY" could not be the father. "ASTD" could be the father, with the 'A' and 'D' coming from the father and the 'B' and 'C' coming from the mother. "QBCD" could also be the father, with either the 'B' and 'D' or the 'C' and 'D' coming from the father.
 *                     2)       
 *                     "ABABAB"
 *                     "ABABAB"
 *                     { "ABABAB", "ABABCC", "ABCCDD", "CCDDEE" }
 *                     Returns: { 0,  1 }
 *                     3)       
 *                     "YZGLSYQT"
 *                     "YUQRWYQT"
 *                     {"YZQLDPWT", "BZELSWQM", "OZGPSFKT", "GZTKFYQT", "WQJLSMQT"}
 *                     Returns: { }
 *                     4)       
 *                     "WXETPYCHUWSQEMKKYNVP"
 *                     "AXQTUQVAUOSQEEKCYNVP"
 *                     { "WNELPYCHXWXPCMNKDDXD",
 *                       "WFEEPYCHFWDNPMKKALIW",
 *                         "WSEFPYCHEWEFGMPKIQCK",
 *                           "WAEXPYCHAWEQXMSKYARN",
 *                             "WKEXPYCHYWLLFMGKKFBB" }
 *                             Returns: { 1,  3 }
 *                             This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.
 * */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class PaternityTest
{
    public:
        PaternityTest () {}
        vector<int> possibleFathers (string child, string mother, vector<string> men)
        {
            vector<int> res;
            
            int itr = 0;
            while (itr < men.size())
            {
                int common = 0;
                int temp = 0;
                int temp1 = 0;
                bool check = true;
                for (int i=0; i<child.length(); i++)
                {
                    if (mother[i] == men[itr][i] && mother[i] == child[i])
                    {
                        temp++;
                        temp1++;
                        common++;
                    }
                    else if (mother[i] == child[i])
                        temp++;
                    else if (men[itr][i] == child[i])
                        temp1++;
                    else
                    {
                        check = false;
                        break;
                    }
                }

                cout << "mother " << temp << "  , common: " << common << endl;

                if (check)
                {
                    if (temp >= child.length()/2 && temp1 >= child.length()/2)
                        res.push_back(itr);
                }

                itr++;
            }

            return res;   
        }
};

int main ()
{
    cout << "Enter input" << endl;
    string child, mother;
    vector<string> men;

    char s;
    string temp = "";
    bool check = false;

    int type = 0;
    while (s != '}')
    {
        s = getchar();
        if (check == false)
        {
            if (s == '\"')
                check = true;
        }
        else
        {
            if (check && s == '\"') 
            {
                if (type == 0)
                {
                    child = temp;
                    type++;
                }
                else if (type == 1)
                {
                    mother = temp;
                    type++;
                }
                else
                    men.push_back(temp);

                temp = "";
                check = false;
            }
            else
                temp += s;
        }
    }

    PaternityTest pt;
    vector<int> res = pt.possibleFathers(child, mother, men);

    cout << "Returns: {";
    for (int i=0; i<res.size(); i++)
        cout << res[i] << " ";
    cout << " }" << endl;


    return 0;
}
