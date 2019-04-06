/*
 * =====================================================================================
 *
 *       Filename:  DerivativeSequence.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/11/2019 09:05:49 PM
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
 *
 *  Problem Statement for DerivativeSequence
 *
 *
 *  Problem Statement
 *          
 *          Given a sequence of K elements, we can calculate its difference sequence by taking the difference between each pair of adjacent elements. For instance, the difference sequence of {5,6,3,9,-1} is {6-5,3-6,9-3,-1-9} = {1,-3,6,-10}. Formally, the difference sequence of the sequence a1, a2, ... , ak is b1, b2, ... , bk-1, where bi = ai+1 - ai.
 *
 *          The derivative sequence of order N of a sequence A is the result of iteratively applying the above process N times. For example, if A = {5,6,3,9,-1}, the derivative sequence of order 2 is: {5,6,3,9,-1} -> {1,-3,6,-10} -> {-3-1,6-(-3),-10-6} = {-4,9,-16}.
 *
 *          You will be given a sequence a as a int[] and the order n. Return a int[] representing the derivative sequence of order n of a.
 *
 *           
 *           Definition
 *                  
 *                  Class:ClassDerivativeSequenceMethod:ClassDerivativeSequenceMethodderSeqParameters:ClassDerivativeSequenceMethodderSeqParametersint[], int
 *                  Returns:Returnsint[]
 *                  Method signature:signatureint[] derSeq(int[] a, int n)
 *                  (be sure your method is public)
 *                      
 *                       
 *                       Notes
 *                       -NotesThe derivative sequence of order 0 is the original sequence. See example 4 for further clarification.
 *                        
 *                        Constraints
 *                        -Constraintsa will contain between 1 and 20 elements, inclusive.
 *                        -inclusiveEach element of a will be between -100 and 100, inclusive.
 *                        -inclusiven will be between 0 and K-1, inclusive, where K is the number of elements in a.
 *                         
 *                         Examples
 *                         0)       
 *                         {5,6,3,9,-1}
 *                         1
 *                         Returns: {1, -3, 6, -10 }
 *                         The first example given in the problem statement.
 *                         1)       
 *                         {5,6,3,9,-1}
 *                         2
 *                         Returns: {-4, 9, -16 }
 *                         The second example given in the problem statement.
 *                         2)       
 *                         {5,6,3,9,-1}
 *                         4
 *                         Returns: {-38 }
 *                         3)       
 *                         {4,4,4,4,4,4,4,4}
 *                         3
 *                         Returns: {0, 0, 0, 0, 0 }
 *                         After 1 step, they all become 0.
 *                         4)       
 *                         {-100,100}
 *                         0
 *                         Returns: {-100, 100 }
 *                         This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class DerivativeSequence
{
private:

public:
    DerivativeSequence () {}
    vector<int> deSeq (vector<int> a, int n)
    {
        vector<int> res;

        if (n <= 0)
            return a;
        else
        {
            for (int i=0; i<a.size()-1; i++)
                res.push_back(a[i+1] - a[i]);
        }

        return deSeq (res, n-1);
    }
};

int main ()
{
    printf("Enter input vectors:\n");
    vector<int> a;
    int n;
    char s;
    string temp = "";
    bool check = false;

    while (1)
    {
        s = getchar();
        if (!check && (s == '{' || s == ','))
            check = true;
        else if (check)
        {
            if (isspace(s) || s == ',' || s == '}')
            {
                a.push_back(stoi(temp));
                temp = "";
                
                if (s == '}')
                    break;
            }
            else 
            {
                temp += s;
            }
        }
    }

    scanf("%d", &n);

    DerivativeSequence ds;
    vector<int> res = ds.deSeq(a, n);
    printf("The result is: %d\n");
    for (int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    
    return 0;
}
