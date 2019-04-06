/*
 * =====================================================================================
 *
 *       Filename:  ExerciseMachine.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/13/2019 08:25:59 PM
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
 *      You are writing firmware for an exercise machine. Each second, a routine in your firmware is called which decides whether it should display the percentage of the workout completed. The display does not have any ability to show decimal points, so the routine should only display a percentage if the second it is called results in a whole percentage of the total workout.
 *
 *      Given a String time representing how long the workout lasts, in the format "hours:minutes:seconds", return the number of times a percentage will be displayed by the routine. The machine should never display 0% or 100%.
 *
 *       
 *       Definition
 *              
 *              Class:ClassExerciseMachineMethod:ClassExerciseMachineMethodgetPercentagesParameters:ClassExerciseMachineMethodgetPercentagesParametersStringReturns:ClassExerciseMachineMethodgetPercentagesParametersStringReturnsintMethod signature:signatureint getPercentages(String time)
 *              (be sure your method is public)
 *                  
 *                   
 *                   Constraints
 *                   -Constraintstime will be a String formatted as "HH:MM:SS", HH = hours, MM = minutes, SS = seconds.
 *                   -secondsThe hours portion of time will be an integer with exactly two digits, with a value between 00 and 23, inclusive.
 *                   -inclusiveThe minutes portion of time will be an integer with exactly two digits, with a value between 00 and 59, inclusive.
 *                   -inclusiveThe seconds portion of time will be an integer with exactly two digits, with a value between 00 and 59, inclusive
 *                   -inclusivetime will not be "00:00:00".
 *                    
 *                    Examples
 *                    0)        
 *                    "00:30:00"
 *                    Returns: 99
 *                    The standard 30 minute workout. Each one percent increment can be displayed every 18 seconds.
 *                    1)        
 *                    "00:28:00"
 *                    Returns: 19
 *                    The 28 minute workout. The user completes 5 percent of the workout every 1 minute, 14 seconds.
 *                    2)        
 *                    "23:59:59"
 *                    Returns: 0
 *                    This is the longest workout possible, given the constraints. No percentages are ever displayed on the screen.
 *                    3)        
 *                    "00:14:10"
 *                    Returns: 49
 *                    4)        
 *                    "00:19:16"
 *                    Returns: 3
 *                    This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

class ExerciseMachine
{
    public:
        ExerciseMachine () {}
        int getPercentages (string time)
        {
            int giv_time[3];
            int itr = 0;
            string temp = "";
            for (int i=0; i<time.length(); i++)
            {
                if (time[i] == ':')
                {
                    giv_time[itr] = stoi(temp);
                    itr++;
                    temp = "";
                }
                else
                    temp += time[i];
            }
            giv_time[itr] = stoi(temp);


            double total = giv_time[2] + 60 * giv_time[1] + 60 * 60 * giv_time[0];
            double interval = total / 100;

            int res = 0;

            for (int i=1; i<100; i++)
            {
                if (trunc(interval * i) == interval * i)
                    res++;
            }   
            
            return res;
        }

};

int main ()
{
    cout << "Enter the workout time: " << endl;
    char time[50];
    scanf("%s", time);

    ExerciseMachine em;
    int res = em.getPercentages(time);

    cout << "The #percentage is: " << res << endl;
    return 0;
}
