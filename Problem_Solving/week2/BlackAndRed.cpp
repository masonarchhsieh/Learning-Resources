/*
 * =====================================================================================
 *
 *       Filename:  BlackAndRed.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/11/2019 05:23:19 PM
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
 *      You are playing a game with a deck of cards, half red and half black. After your friend thoroughly shuffles the cards, you cut the deck. Your friend then begins to turn the cards over one at a time, starting from the top of the deck. If, at any time, there are more red cards showing than black cards, you lose. If this never occurs by they time all the cards have been turned up, you win.
 *
 *      After losing several times in a row, you get frustrated and decide to cheat. After your friend shuffles the deck, you distract him and then secretly look at the cards, to figure out where you should cut the deck.
 *
 *      "Cutting the deck" means to take a stack of cards off the top of the deck, and place this stack on the bottom.
 *
 *      Given a String deck, representing the cards, return the number of cards you should remove from the top of the deck when you cut. A 'R' indicates a red card, and a 'B' indicates a black card. The first character of deck represents the top card, and the last character represents the bottom card. If there are multiple possibilities, return the smallest number.
 *
 *       
 *       Definition
 *              
 *              Class:ClassBlackAndRedMethod:ClassBlackAndRedMethodcutParameters:ClassBlackAndRedMethodcutParametersStringReturns:ClassBlackAndRedMethodcutParametersStringReturnsintMethod signature:signatureint cut(String deck)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintscards will contain between 2 and 50 characters, inclusive.
 *                   -inclusivecards will contain only the characters 'R' and 'B'.
 *                   -andcards will contain the same number of 'R' and 'B' characters.
 *                    
 *                    Examples
 *                    0)        
 *                    "BRBRBR"
 *                    Returns: 0
 *                    You could cut the deck at positions 0, 2, or 4 to win.
 *                    1)        
 *                    "RBRBRB"
 *                    Returns: 1
 *                    If you cut the deck at position 0, the first card dealt will be red and you will lose immediately. However, if you cut the deck at position 1, you will win.
 *                    2)        
 *                    "BBBRRRRB"
 *                    Returns: 7
 *                    The only way to win is to cut the deck at position 7. After this cut, the deck becomes: "BBBBRRRR".
 *                    3)        
 *                    "BR"
 *                    Returns: 0
 *                    4)        
 *                    "RBRBBRRRRBBBRBBRRBRBBRRRBRBBBRBRBRBRBRRB"
 *                    Returns: 9
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved. */

#include <iostream>
#include <string>

using namespace std;

class BlackAndRed
{
public:
    BlackAndRed () {}
    int cut (string deck)
    {
        int res = 0;
        int numB = 0;
        int numR = 0;
        bool check;

        for (int i=0; i<deck.length(); i++)
        {  
            check = true; 
            numB = 0;
            numR = 0;
            for (int j=i; j<deck.length(); j++)
            {
                if (deck[j] == 'B') { numB++; }
                else if (deck[j] == 'R') { numR++; }
            
                if (numR > numB) { check = false; }
            }

            if (check) { res = i; break; }
        }

        return res;
    }
};

int main ()
{
    printf("Enter the input:\n");
    char str [50];
    scanf ("%s", str);

    BlackAndRed br;
    int res = br.cut(str);
    printf("The result is: %d\n", res);

    return 0;
}
