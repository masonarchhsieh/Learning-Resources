/*
 * =====================================================================================
 *
 *       Filename:  MonsterValley2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/17/2019 05:23:39 PM
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
 *      Manao is traversing a valley inhabited by monsters. During his journey, he will encounter several monsters one by one. The scariness of each monster is a positive integer. Some monsters may be scarier than others. The i-th (0-based index) monster Manao will meet has scariness equal to dread[i]. 
 *
 *      Manao is not going to fight the monsters. Instead, he will bribe some of them and make them join him. To bribe the i-th monster, Manao needs price[i] gold coins. The monsters are not too greedy, therefore each value in price will be either 1 or 2. 
 *
 *      At the beginning, Manao travels alone. Each time he meets a monster, he first has the option to bribe it, and then the monster may decide to attack him. A monster will attack Manao if and only if he did not bribe it and its scariness is strictly greater than the total scariness of all monsters in Manao's party. In other words, whenever Manao encounters a monster that would attack him, he has to bribe it. If he encounters a monster that would not attack him, he may either bribe it, or simply walk past the monster. 
 *
 *
 *
 *       
 *
 *
 *
 *       Consider this example: Manao is traversing the valley inhabited by the Dragon, the Hydra and the Killer Rabbit. When he encounters the Dragon, he has no choice but to bribe him, spending 1 gold coin (in each test case, Manao has to bribe the first monster he meets, because when he travels alone, the total scariness of monsters in his party is zero). When they come by the Hydra, Manao can either pass or bribe her. In the end, he needs to get past the Killer Rabbit. If Manao bribed the Hydra, the total scariness of his party exceeds the Rabbit's, so they will pass. Otherwise, the Rabbit has to be bribed for two gold coins. Therefore, the optimal choice is to bribe the Hydra and then to walk past the Killer Rabbit. The total cost of getting through the valley this way is 2 gold coins. 
 *
 *
 *
 *       You are given the int[]s dread and price. Compute the minimum price Manao will pay to safely pass the valley.
 *        
 *        Definition
 *              
 *              Class:ClassMonstersValley2Method:ClassMonstersValley2MethodminimumPriceParameters:ClassMonstersValley2MethodminimumPriceParametersint[], int[]
 *              Returns:ReturnsintMethod signature:signatureint minimumPrice(int[] dread, int[] price)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintsdread will contain between 1 and 20 elements, inclusive.
 *                   -inclusiveEach element of dread will be between 1 and 2,000,000,000, inclusive.
 *                   -inclusiveprice will contain between the same number of elements as dread.
 *                   -dreadEach element of price will be either 1 or 2.
 *                    
 *                    Examples
 *                    0)        
 *                    {8, 5, 10}
 *                    {1, 1, 2}
 *                    Returns: 2
 *                    The example from the problem statement.
 *                    1)        
 *                    {1, 2, 4, 1000000000}
 *                    {1, 1, 1, 2}
 *                    Returns: 5
 *                    Manao has to bribe all monsters in the valley.
 *                    2)        
 *                    {200, 107, 105, 206, 307, 400}
 *                    {1, 2, 1, 1, 1, 2}
 *                    Returns: 2
 *                    Manao can bribe monsters 0 and 3.
 *                    3)        
 *                    {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333}
 *                    {2, 2, 1, 1, 1, 1, 2, 1, 2, 1}
 *                    Returns: 5
 *                    Bribing monsters 0, 1 and 5 is sufficient to pass safely.
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class MonsterValley2
{
    public:
        MonsterValley2 () {}
        int minimumPrice (vector<int> dread, vector<int> price)
        {
            return checkMin(0, 0, dread, price);
        }

        int checkMin (int itr, long curD, vector<int> dread, vector<int> price)
        {
            if (itr == dread.size())
                return 0;

            if (curD < dread[itr])
                return price[itr] + checkMin(itr+1, curD+dread[itr], dread, price);
            else
                return min(price[itr] + checkMin(itr+1, curD+dread[itr], dread, price), checkMin(itr+1, curD, dread, price));
        }
};

int main ()
{
    cout << "Enter input:" << endl;

    char s;
    string temp = "";
    bool check = false;

    vector<int> dread;
    vector<int> price;
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
                    dread.push_back(stoi(temp));
                else if (type == 1)
                    price.push_back(stoi(temp));
                

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

    MonsterValley2 mv;
    int res = mv.minimumPrice(dread, price);
     
    cout << "Returns: " << res << endl;

    return 0;
}
