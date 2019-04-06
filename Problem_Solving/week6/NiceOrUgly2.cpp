/*
 * =====================================================================================
 *
 *       Filename:  NiceOrUgly2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/18/2019 10:01:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int array[123][3][5];

int check_if_vows(char ch)
{
    return strchr("AEIOU", ch) != NULL;
}

class NiceOrUgly
{
    public:
        NiceOrUgly () {}
        string describe(string s)
        {
            memset(array, 0, sizeof(array));
            int len = s.length();
            int nice = 0, ugly = 0;
            array[0][0][0] = 1;

            for (int i=0; i<len; i++)
            {
                for (int a=0; a<3; a++)
                {
                    for (int b=0; b<5; b++)
                    {
                        if (array[i][a][b])
                        {
                            int vo = check_if_vows(s[i]) || s[i] == '?';
                            int co = !check_if_vows(s[i]) || s[i] == '?';

                            if (vo)
                            {
                                if (a >= 2)
                                    ugly = 1;
                                else
                                    array[i+1][a+1][0] = 1;
                            }

                            if (co)
                            {
                                if (b >= 4)
                                    ugly = 1;
                                else
                                    array[i+1][0][b+1] = 1;
                            }
                        }
                    }
                }
            }

            for (int i=0; i<3; i++)
                for (int j=0; j<5; j++)
                    nice |= array[len][i][j];

            if (nice)
                if (ugly)
                    return "42";
                else
                    return "NICE";
            else
                return "UGLY";
        }
};

int main ()
{
    cout << "ENTER INPUT: " << endl;
    char s[50];
    scanf ("%s", s);

    NiceOrUgly nou;
    string res = nou.describe(s);
    cout << "Returns: " << res << endl;

    return 0;
}
