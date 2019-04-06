/*
 * =====================================================================================
 *
 *       Filename:  structure_sample.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/05/2019 04:17:21 PM
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

typedef struct
{
    char name[100];
    char address[200];
    int year_of_birth;
    int month_of_birth;
    int day_of_birth;  
} personal_data;


personal_data *my_struct_ptr;

personal_data person1;
my_struct_ptr = &person1;
(*my_struct_ptr).day_of_birth = 23;     /* the same as: my_struct_ptr->day_of_birth = 23 */

