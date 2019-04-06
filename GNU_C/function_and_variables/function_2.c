/*
 * =====================================================================================
 *
 *       Filename:  function_2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/03/2019 05:24:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void print_stuff (int foo, int bar);
int calc_value (int bas, int quux);


void print_stuff (int foo, int bar)
{
      int var_to_print;

      var_to_print = calc_value (foo, bar);
      printf ("var_to_print = %d\n", var_to_print);
}


int calc_value (int bas, int quux)
{
      return bas * quux;
}


int main()
{
      print_stuff (23, 5);
      exit (0);
}

