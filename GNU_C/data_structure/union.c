/*
 * =====================================================================================
 *
 *       Filename:  union.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/05/2019 05:08:55 PM
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

enum which_member
{
    INT,
    FLOAT
};

union int_or_float my_union1;
enum which_member my_union_status1;

switch (my_union_status1)
{
    case INT:
        my_union1.int_member += 5;
        break;
    case FLOAT:
        my_union1.float_member += 23.232323;
        break;
}

struct multitype
{
    union int_or_float number;
    enum which_member status;
};

struct multitype my_multi;

my_multi.int_member = 5;
my_multi.status = INT;
