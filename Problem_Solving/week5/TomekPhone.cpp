/*
 * =====================================================================================
 *
 *       Filename:  TomekPhone.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/16/2019 04:18:34 PM
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
 *      Tomek thinks that smartphones are overrated. He plans to release a new cellphone with an old-school keyboard, which may require you to tap a key multiple times to type a single letter. For example, if the keyboard has two keys, one with the letters "adef" and the other one with the letters "zyx", then typing 'a' requires one keystroke, typing 'f' requires four keystrokes, typing 'y' requires two keystrokes, and so on.
 *
 *
 *
 *      Tomek has already designed the keyboard's layout. That is, he already knows the number of keys on the keyboard, and for each key he knows the maximum number of letters it may hold. He now wants to create a specific keyboard for a language that uses N different letters. He has a large body of text in this language, and he already analyzed it to find the frequencies of all N letters of its alphabet.
 *
 *
 *
 *      You are given a int[] frequencies with N elements. Each element of frequencies is the number of times one of the letters in Tomek's alphabet appears in the text he has. Each element of frequencies will be strictly positive. (I.e., each of the N letters occurs at least once in Tomek's text.)
 *
 *
 *
 *      You are also given a int[] keySize. The number of elements of keySize is the number of keys on Tomek's keyboard. Each element of keySize gives the maximal number of letters on one of the keys.
 *
 *
 *
 *      Find an assignment of letters to keys that minimizes the number of keystrokes needed to type Tomek's entire text. Return that minimum number of keystrokes. If there is not enough room on the keys and some letters of the alphabet won't fit, return -1 instead.
 *
 *       
 *       Definition
 *              
 *              Class:ClassTomekPhoneMethod:ClassTomekPhoneMethodminKeystrokesParameters:ClassTomekPhoneMethodminKeystrokesParametersint[], int[]
 *              Returns:ReturnsintMethod signature:signatureint minKeystrokes(int[] frequencies, int[] keySizes)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintsfrequencies will contain between 1 and 50 elements, inclusive.
 *                   -inclusiveEach element of frequencies will be between 1 and 1,000, inclusive.
 *                   -inclusivekeySizes will contain between 1 and 50 elements, inclusive.
 *                   -inclusiveEach element of keySizes will be between 1 and 50, inclusive.
 *                    
 *                    Examples
 *                    0)        
 *                    {7,3,4,1}
 *                    {2,2}
 *                    Returns: 19
 *                    Tomek's language has four letters. Let us call them A, B, C, and D. Tomek's text contains seven As, three Bs, four Cs, and one D. The keyboard has two keys, each of them may contain at most two letters. One optimal solution is to use the keys "AD" and "CB". We can then type each A and each C using a single keystroke, and we need two keystrokes for each B and each D. Therefore, the total number of keystrokes when typing the entire text will be 7*1 + 3*2 + 4*1 + 1*2 = 19.
 *                    1)        
 *                    {13,7,4,20}
 *                    {2,1}
 *                    Returns: -1
 *                    There is not enough space on the keys to fit all four letters.
 *                    2)        
 *                    {11,23,4,50,1000,7,18}
 *                    {3,1,4}
 *                    Returns: 1164
 *                    3)        
 *                    {100,1000,1,10}
 *                    {50}
 *                    Returns: 1234
 *                    4)        
 *                    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}
 *                    {10,10,10,10,10,10,10,10}
 *                    Returns: 3353
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

class TomekPhone
{
    public:
        TomekPhone () {}
        int minKeystrokes (vector<int> frequencies, vector<int> keySizes)
        {
            int res = 0;

            int keySize = 0;
            for (int i=0; i<keySizes.size(); i++)
                keySize += keySizes[i];
            if (keySize < frequencies.size())
                return -1;
        
            sort(frequencies.begin(), frequencies.end());
            sort(keySizes.begin(), keySizes.end());

            int itr = 1;
            int next = 0;
            for (int i=frequencies.size()-1; i>=0; i--)
            {
                
                bool check = false;
                for (int j=next; j<keySizes.size(); j++)
                {
                    if (keySizes[j] >= itr)
                    {
                        res += (frequencies[i] * itr);
                        next = j + 1;
                        check = true;
                        break;
                    }
                }

                if (check && next >= keySizes.size())
                {   
                    next = 0;
                    itr++;   
                }
            }

            return res;
        }
};

int main ()
{
    cout << "Enter input" << endl;
    vector<int> frequencies;
    vector<int> keySizes;

    char s;
    string temp = "";
    bool check = false;

    int type = 0;
    while (type < 2)
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
                if (type == 0)
                    frequencies.push_back(stoi(temp));
                else if (type == 1)
                    keySizes.push_back(stoi(temp));
                

                if (s == '}')
                {
                    type++;
                    check = false;
                }    

                temp = "";
            }
            else
                temp += s;
        }
    }

    TomekPhone tp;
    int res = tp.minKeystrokes(frequencies, keySizes);

    cout << "Returns: " << res << endl; 

    return 0;
}

