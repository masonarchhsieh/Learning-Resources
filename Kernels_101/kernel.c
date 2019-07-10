/*
 * =====================================================================================
 *
 *       Filename:  kernel.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/11/2019 02:36:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */

void kmain(void)
{
    const char *str = "my first kernel";
    char *vidptr = (char*) 0xb8000;     //video mem begins here
    unsigned int i = 0;
    unsigned int j = 0;

    /* The following code clears the screen
     * There are 25 lines each of 80 columns: each element takes 2 bytes *
     */
    while (j < 80 * 25 * 2) {
        /* blank character */
        vidptr[j] = ' ';
        /* attribute-byte - light grey on black screen */
        vidptr[j+1] = 0x07;
        j = j + 2;
    }

    j = 0;

    /* this loop writes the string to video memory */
    while(str[j] != '\0') {
        /* the character's acii */
        vidptr[i] = str[j];
        /*  attribute-byte: give character black bg and light grey fg */
        vidptr[i+1] = 0x07;
        ++j;
        i = i + 2;
    }
    return;
}

