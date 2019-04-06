/*
 * =====================================================================================
 *
 *       Filename:  AzimuthMonitoring.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/10/2019 08:51:47 PM
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
 *      A robot is moving in a plane following a set of instructions.
 *
 *
 *
 *      The following instructions are possible (quotes for clarity only):
 *
 *      "LEFT" - turn left 90 degrees
 *
 *      "RIGHT" - turn right 90 degrees
 *
 *      "TURN AROUND" - turn aROUND (a 180 degree turn)
 *
 *      "LEFT X" - turn left X degrees, where X is a positive integer
 *
 *      "RIGHT X" - turn right X degrees, where X is a positive integer
 *
 *      "HALT" - stop executing instructions; further instructions are not executed
 *
 *
 *
 *      You are given a string[] containing the robot's instructions. initially, the robot is facing north. return the robot's final azimuth - the angle between north and the direction the robot is facing. azimuth is always measured clockwise, and is a number between 0, inclusive, and 360, exclusive. for example, west corresponds to azimuth 270.
 *       
 *       definition
 *              
 *              class:classazimuthmonitoringmethod:classazimuthmonitoringmethodgetazimuthparameters:classazimuthmonitoringmethodgetazimuthparametersstring[]
 *              returns:returnsintmethod signature:signatureint getazimuth(string[] instructions)
 *              (be sure your method is public)
 *                  
 *                   
 *                   notes
 *                   -notesturning right corresponds to turning clockwise, turning left corresponds to turning counterclockwise.
 *                    
 *                    constraints
 *                    -constraintsinstructions will contain between 1 and 50 elements, inclusive.
 *                    -inclusiveeach element of instructions will be a valid instruction, as listed in the problem statement.
 *                    -statementin an instruction of the form "left x" or "right x", x will be an integer between 1 and 179, inclusive, with no leading zeroes.
 *                     
 *                     examples
 *                     0)       
 *                     {"right"}
 *                     returns: 90
 *                     turning 90 degrees right changes the azimuth from 0 to 90.
 *                     1)       
 *                     {"left", "left", "turn aROUND"}
 *                     returns: 0
 *                     after turning left, the robot is facing west (azimuth 270). after turning left again, the robot is facing south (azimuth 180). finally, turning aROUND makes the robot face north, azimuth 0.
 *                     2)       
 *                     {"left 5", "right 10", "left 15", "right 20", "left 25", "right 30", "left 35", "right 40"}
 *                     returns: 20
 *                     there are four pairs of instructions, each pair making the robot turn right 5 degrees.
 *                     3)       
 *                     {"right 59", "right", "right", "halt", "left", "left", "left"}
 *                     returns: 239
 *                     the fourth instruction is "halt", thus none of the following "left" instructions are executed.
 *                     4)       
 *                     {"turn aROUND", "halt", "left 5", "halt", "left 5", "halt"}
 *                     returns: 180
 *                     note that there might be more then one "halt" instruction.
 *                     5)       
 *                     {"left", "left", "left", "left", "left", "halt"}
 *                     returns: 270
 *                     after the first 4 turns the robot is facing north again, and the fifth instruction turns him west. the last instruction doesn't change anything.
 *                     this problem statement is the exclusive and proprietary property of topcoder, inc. any unauthorized use or reproduction of this information without the prior written consent of topcoder, inc. is strictly prohibited. (c)2006, topcoder, inc. all rights reserved.
*/

#include <iostream>
#include <string>
#include <cstddef>  //std::size_t
#include <vector>

#define north 0
#define east 90
#define south 180
#define west 270
#define ROUND 360

using namespace std;


class AzimuthMonitoring
{
private:

public:
    AzimuthMonitoring () {}
    int getazimuth (vector<string> instructions)
    {
        int robot = north;
        for (int i=0; i<instructions.size(); i++)
        {
            if (instructions[i] == "HALT")
                break;
            else if (instructions[i].find("LEFT") != string::npos)
            {
                int turn;
                if (instructions[i].length() == 4)
                    turn = -90;
                else 
                {
                    string temp;
                    for (int j=5; j<instructions[i].length(); j++)
                        temp += instructions[i][j];
                     
                    turn = -(stoi(temp, 0, 10));
                }
                
                robot = (ROUND + robot + turn) % ROUND;
            }
            else if (instructions[i].find("RIGHT") != string::npos)
            {
                int turn;
                if (instructions[i].length() == 5)
                    turn = 90;
                else 
                {
                    string temp;
                    for (int j=6; j<instructions[i].length(); j++)
                        temp += instructions[i][j];
                    
                    turn = stoi(temp, 0, 10);
                }
                
                robot = (robot + turn) % ROUND; 
            }
            else if (instructions[i] == "TURN AROUND")
                robot = (robot + 180) % ROUND;            
        }
        
        return robot;
    }
};

int main ()
{
    printf("Enter the instructions:\n");
    vector<string> instructions;
    
    char s;
    string temp = "";
    bool check = false;

    while (s != '}')
    {
        if (check == false)
        {
            if (s == '\"')
                check = true;
        }
        else
        {
            if (check && s == '\"')
            {
                check = false;
                instructions.push_back(temp);
                temp = "";
            }
            else
                temp += s;
        }
        
        s = getchar();
    }

    AzimuthMonitoring am;

    int res = am.getazimuth(instructions);
    printf("The result is: %d\n", res);

    return 0;
}
