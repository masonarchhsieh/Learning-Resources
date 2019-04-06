/*
 * =====================================================================================
 *
 *       Filename:  StreetParking.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/10/2019 04:28:45 PM
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
 *      You are looking for a place to park your car on a suburban street. You can park at any position that meets the following requirements:
 *
 *      1.requirementsIt is not directly in front of a private driveway.
 *      2.drivewayIt is not directly in front of a bus stop.
 *      3.stopIt is not 5 meters before a bus stop.
 *      4.stopIt is not 10 meters before a bus stop.
 *      5.stopIt is not directly in front of a side-street.
 *      6.streetIt is not 5 meters before a side-street.
 *      7.streetIt is not 5 meters after a side-street.
 *      The street will be represented as a string, where each character describes a section of the street 5 meters in length. So the first character describes the first 5 meters of the street, the second character describes the next 5 meters and so on. street will use 'D' for driveway, 'B' for bus stop, 'S' for side-street and '-' for all other sections of the street. A position is directly in front of an object if it has the same index as the object in street. A position is before an object if its index is lower than the index of the object in street. Finally, a position is after an object if its index is higher than the index of the object in street.
 *
 *      Given the street return the total number of possible parking spaces on that street.
 *
 *       
 *       Definition
 *              
 *              Class:ClassStreetParkingMethod:ClassStreetParkingMethodfreeParksParameters:ClassStreetParkingMethodfreeParksParametersstringReturns:ClassStreetParkingMethodfreeParksParametersstringReturnsintMethod signature:signatureint freeParks(string street)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintsstreet will have between 1 and 50 characters inclusive.
 *                   -inclusivestreet will only contain characters 'D', 'B', 'S' and '-'.
 *                    
 *                    Examples
 *                    0)        
 *                    "---B--S-D--S--"
 *                    Returns: 4
 *                    The street looks like this:
 *                    ---B--S-D--S--
 *                    ^   ^    ^   ^
 *                    |   |    |   |
 *                    The arrows indicate where you are allowed to park on this street. Thus the method should return 4.
 *                    1)        
 *                    "DDBDDBDDBDD"
 *                    Returns: 0
 *                    This street is full of private driveways and bus stops. You cannot park anywhere on this street. The method should return 0.
 *                    2)        
 *                    "--S--S--S--S--"
 *                    Returns: 2
 *                    You can only park at the first and last positions on this street. The method should return 2.
 *                    3)        
 *                    "SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D"
 *                    Returns: 14
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.  
 */

#include <iostream>
#include <string.h>

using namespace std;

class StreetParking
{
private:

public:
    StreetParking () {}
    int freeParks (string street)
    {
        int res = 0;
        int L = street.length();
        for (int i=0; i<L; i++) 
        {
            if (street[i] == '-')
            {
                if ((i + 2 < L && street[i+2] == 'B') || (i + 1 >= 0 && (street[i+1] == 'S' || street[i+1] == 'B')) || (i - 1 >= 0 && street[i-1] == 'S'))
                    ;
                else
                    res++;
            }
                        
        }
        
        return res;
    }
};

int main()
{
    printf("Please Enter Street's string: \n");
    string street;
    getline(cin, street);

    StreetParking sp;
    int res = sp.freeParks(street);

    printf("The result is: %d\n", res);

    return 0;
}
