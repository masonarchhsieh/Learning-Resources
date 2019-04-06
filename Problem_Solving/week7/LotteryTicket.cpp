/*
 * =====================================================================================
 *
 *       Filename:  LotteryTicket.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/21/2019 03:44:32 PM
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
 *      Nick likes to play the lotto. The cost of a single lotto ticket is price. Nick has exactly four banknotes with values b1, b2, b3 and b4 (some of the values may be equal). He wants to know if it's possible to buy a single lotto ticket without getting any change back. In other words, he wants to pay the exact price of a ticket using any subset of his banknotes. Return "POSSIBLE" if it is possible or "IMPOSSIBLE" if it is not (all quotes for clarity).
 *       
 *       Definition
 *              
 *              Class:ClassLotteryTicketMethod:ClassLotteryTicketMethodbuyParameters:ClassLotteryTicketMethodbuyParametersint, int, int, int, int
 *              Returns:ReturnsStringMethod signature:signatureString buy(int price, int b1, int b2, int b3, int b4)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintsprice will be between 1 and 4000, inclusive.
 *                   -inclusiveb1, b2, b3 and b4 will each be between 1 and 1000, inclusive.
 *                    
 *                    Examples
 *                    0)        
 *                    10
 *                    1
 *                    5
 *                    10
 *                    50
 *                    Returns: "POSSIBLE"
 *                    Nick can use the banknote with value b3.
 *                    1)        
 *                    15
 *                    1
 *                    5
 *                    10
 *                    50
 *                    Returns: "POSSIBLE"
 *                    Here he can use the banknotes with values b2 and b3.
 *                    2)        
 *                    65
 *                    1
 *                    5
 *                    10
 *                    50
 *                    Returns: "POSSIBLE"
 *                    b2 + b3 + b4 is 65.
 *                    3)        
 *                    66
 *                    1
 *                    5
 *                    10
 *                    50
 *                    Returns: "POSSIBLE"
 *                    All four banknotes must be used.
 *                    4)        
 *                    1000
 *                    999
 *                    998
 *                    997
 *                    996
 *                    Returns: "IMPOSSIBLE"
 *                    5)        
 *                    20
 *                    5
 *                    5
 *                    5
 *                    5
 *                    Returns: "POSSIBLE"
 *                    Some of the banknote values may be equal.
 *                    6)        
 *                    2
 *                    1
 *                    5
 *                    10
 *                    50
 *                    Returns: "IMPOSSIBLE"
*                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>


using namespace std;

class LotteryTicket
{
    string POSSIBLE = "POSSIBLE";
    string IMPOSSIBLE = "IMPOSSIBLE";

    public:
        string buy(int price, int b1, int b2, int b3, int b4)
        {
            string res = IMPOSSIBLE;
            vector<int> banknotes;
            
 
            banknotes.push_back(b1);    
            banknotes.push_back(b2);
            banknotes.push_back(b3);    
            banknotes.push_back(b4);

            sort(banknotes.begin(), banknotes.end());
            reverse(banknotes.begin(), banknotes.end());

            for (int i=0; i<banknotes.size(); i++)
            {
                if (price >= banknotes[i])
                    price -= banknotes[i];
            }
            
            if (price == 0)
               res = POSSIBLE; 

            return res;
        }
};

int main ()
{
    cout << "Enter input: " << endl;
    int price, b1, b2, b3, b4;
    scanf("%d", &price);  scanf("%d", &b1);  scanf("%d", &b2);  scanf("%d", &b3);  scanf("%d", &b4);

    LotteryTicket lt;
    string res = lt.buy(price, b1, b2, b3, b4);
    cout << "Returns: " << res << endl;

    return 0;
}
