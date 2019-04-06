/*
 * =====================================================================================
 *
 *       Filename:  ThrowTheBall.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/10/2019 03:49:25 PM
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
 *      There are N friends sitting in a circle, numbered clockwise in increasing order from 1 to N. At the beginning of the game, player 1 receives a ball. The players take turns passing the ball to each other. At the beginning of the game and before each next pass the following actions are performed. If the player with the ball has already received the ball M times, the game is over. Otherwise, if the player has received the ball p times, he'll pass the ball directly to the person L places to his left if p is even, or L places to his right if p is odd (see examples for clarification). Given N, M and L, return the number of times that the ball is passed.
 *       
 *       Definition
 *              
 *              Class:ClassThrowTheBallMethod:ClassThrowTheBallMethodtimesThrownParameters:ClassThrowTheBallMethodtimesThrownParametersint, int, int
 *              Returns:ReturnsintMethod signature:signatureint timesThrown(int N, int M, int L)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -ConstraintsN will be between 3 and 50, inclusive.
 *                   -inclusiveM will be between 1 and 50, inclusive.
 *                   -inclusiveL will be between 1 and N-1, inclusive.
 *                    
 *                    Examples
 *                    0)        
 *                    5
 *                    3
 *                    2
 *                    Returns: 10
 *                    First, player 1 gets the ball. Since he has held the ball 1 time, he passes the ball to player 4, who is two places to his right. This is player 4's first time holding the ball, so he gives it to player 2, who passes it to player 5. Player 5 then passes the ball to player 3, who passes it back to player 1. Since player 1 has now held the ball 2 times, he passes it to player 3, who passes it to player 5, who then passes the ball to player 2. Finally, player 2 passes the ball to player 4, who then passes it to player 1. Player 1 has now held the ball 3 times, and the game ends.
 *                    1)        
 *                    4
 *                    1
 *                    3
 *                    Returns: 0
 *                    Here, the ball is never passed.
 *                    2)        
 *                    10
 *                    3
 *                    5
 *                    Returns: 4
 *                    3)        
 *                    15
 *                    4
 *                    9
 *                    Returns: 15
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.
 */

#include <iostream>

using namespace std;

class ThrowTheBall
{
private:
    struct Node 
    {
        struct Node *left;
        struct Node *right;
        int count;
        int id;
    };

public:
    ThrowTheBall(){}
    int timesThrown (int N, int M, int L)
    {
        if (M <= 1)     return 0;
        else
        {
            Node* player = new Node();
            Node* head = player;
            Node* tail = player;
            
            for (int i=1; i<N; i++)
            {
                Node* temp = new Node();
                temp->id = i + 1;
                temp->count = 0;
                temp->left = tail;
                tail->right = temp;
                tail = temp;
            }
            {
                head->id = 1;
                head->count = 0;
                head->left = tail;
                tail->right = head;
            }

            int res = 0;
            while (1) 
            {
                player->count++;
                res++;
                if (player->count >= M)
                    break;
                else if (player->count < M)
                {
                    if (player->count % 2 == 1)
                    {
                        for (int i=0; i<L; i++)
                            player = player->left;
                    }
                    else
                    {
                        for (int i=0; i<L; i++)
                            player = player->right;
                    }
                }
            }

            while (head != tail) 
            {
                Node* temp = head;
                head = head->right;
                free(temp);
            }
            return res - 1;
        }    
    }
};


int main() 
{
    int N, M, L;
    printf ("Enter N, M, L for ThrowTheBall\n");
    scanf ("%d", &N);
    scanf ("%d", &M);
    scanf ("%d", &L);

    ThrowTheBall ttb;
    int res = ttb.timesThrown (N, M, L);

    printf("The result is: %d\n", res);

    return 0;
}
