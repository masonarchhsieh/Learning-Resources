/*
 * =====================================================================================
 *
 *       Filename:  function_sample.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/03/2019 05:19:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>

void add_two_numbers (int a, int b)         /*  add a and b */
{
    printf ("%d\n", a + b);
}

int main()
{
    int var1, var2;
    var1 = 1;
    var2 = 53;

    add_two_numbers (var1, var2);
    add_two_numbers (1, 3);

    exit(0);
}
