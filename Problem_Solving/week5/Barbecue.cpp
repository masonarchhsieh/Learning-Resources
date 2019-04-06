/*
 * =====================================================================================
 *
 *       Filename:  Barbecue.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/17/2019 03:18:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */
/*
 * Problem Statement
 *      The Smiths are having a barbecue on a sunny Saturday morning. There was exactly one piece of meat for each family member. But before eating, they decided to play a game of football. As the barbecue was left unattended, the family dog ate one of the pieces of meat. In order to solve this problem, the big brother proposed that one of them should go and play with the dog while the others take their share of meat. Everybody was hungry, so they decided to vote for the person to be excluded. 
 *
 *
 *
 *      There are n members in the Smith family, which are denoted with indices between 0 and n-1. Each of them can vote for any number of persons (from 0 to n-1). In the end, the one who receives the most votes is going to lose the meat. In case of a tie, the one who voted the most loses his meat. If the tie still persists, the person with the smallest index is going to lose. 
 *
 *
 *
 *      You are given an int n denoting the number of Smiths attending the barbecue. You are also given a int[] voter and a int[] excluded with the following signification: the member with the index voter[i] has voted for the exclusion of the member with the index excluded[i]. Return the index of the person that is going to be excluded, according to the criteria defined above.
 *       
 *       Definition
 *              
 *              Class:ClassBarbecueMethod:ClassBarbecueMethodeliminateParameters:ClassBarbecueMethodeliminateParametersint, int[], int[]
 *              Returns:ReturnsintMethod signature:signatureint eliminate(int n, int[] voter, int[] excluded)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintsn is between 2 and 20, inclusive.
 *                   -inclusivevoter and excluded have between 0 and 50 elements, inclusive.
 *                   -inclusivevoter and excluded have the same number of elements.
 *                   -elementsEach element of voter and excluded is between 0 and n-1, inclusive.
 *                   -inclusiveA person cannot vote for the same person more than once.
 *                   -onceA person cannot vote for himself.
 *                    
 *                    Examples
 *                    0)        
 *                    3
 *                    {0,1,2,2}
 *                    {2,2,0,1}
 *                    Returns: 2
 *                    In this case, we have three members. The member with index 2 was voted for by the member with index 0 and the member with index 1 and thus, he is going to be excluded.
 *                    1)        
 *                    3
 *                    {0,2,2}
 *                    {2,0,1}
 *                    Returns: 2
 *                    This time, all the three members are tied with one vote against them. But since the member with index 2 has voted two times, the answer is 2.
 *                    2)        
 *                    2
 *                    {0,1}
 *                    {1,0}
 *                    Returns: 0
 *                    There are only two members and each of them has one exclusion vote. They are also tied by the number of votes given, so the tie is broken by the order of their indices. Thus, the correct answer is 0.
 *                    3)        
 *                    20
 *                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3,4,5,
 *                    6,7,8,9,10,11,12,13,14,15,16,17,18,19,19,19,19}
 *                    {0,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
 *                    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,1,2,3}
 *                    Returns: 2
 *                    4)        
 *                    5
 *                    {4,3,1,0}
 *                    {2,2,3,3}
 *                    Returns: 3
 *                    5)        
 *                    10
 *                    {4,5,6,7,8,9,0,1,2}
 *                    {5,6,7,8,9,0,1,2,3}
 *                    Returns: 0
 *                    6)        
 *                    7
 *                    {1,2,3,4,5,6,0,2,3,4,5,6,0,1,3,4,5,6,0,1,2,
 *                     4,5,6,0,1,2,3,5,6,0,1,2,3,4,6,0,1,2,3,4,5}
 *                     {0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,
 *                      3,3,3,4,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6}
 *                      Returns: 0
 *                      7)      
*                      5
*                      {}
*                      {}
*                      Returns: 0
*                      This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.
*
*                            
 */

#include <iostream>
#include <vector>
#include <algorithm>

 using namespace std;

 class Barbecue
{
    public:
        Barbecue () {}
        int elminate (int n, vector<int> voter, vector<int> excluded);
};

int Barbecue::elminate (int n, vector<int> voter, vector<int> excluded)
{
    int res = 0;

    for (int i=0; i<voter.size(); i++)
    {
        for (int j=0; j<voter.size(); j++)
        {
            if (voter[i] > voter[j])
            {
                int temp = voter[i];
                int temp1 = excluded[i];

                voter[i] = voter[j];
                excluded[i] = excluded[j];

                voter[j] = temp;
                excluded[j] = temp1;
            }
        }
    }

    vector<int> count(n, 0);
    vector<int> numVotes(n, 0);
    for (int i=0; i<voter.size(); i++)
    {
        numVotes[voter[i]]++;
        count[excluded[i]]++;
    }

    int max = 0;
    for (int i=0 ;i<count.size(); i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            res = i;
        }
        else if (count[i] == max && numVotes[i] > numVotes[res])
            res = i;
        
    }

    return res;
};


int main ()
{
    cout << "Enter input:" << endl;
    int N;
    scanf ("%d", &N);

    char s;
    string temp = "";
    bool check = false;

    vector<int> voter;
    vector<int> excluded;
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
                    voter.push_back(stoi(temp));
                else if (type == 1)
                    excluded.push_back(stoi(temp));
                

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

    Barbecue b;
    int res = b.elminate(N, voter, excluded);
    cout << "Returns: " << res << endl;

    return 0;
}
