/*
 * =====================================================================================
 *
 *       Filename:  buffered_IO_example.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/25/2019 07:47:07 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(int argc, char **argv)
{
    struct pirate {
        char name[100];
        unsigned long booty;
        unsigned int beard_len;
    } p, blackbeard = {"Mayank", 100, 50};

    FILE *file = fopen("/tmp/pirate", "w");
    if (!file) {
        perror("fopen");
        return 1;
    }
    if (!fwrite(&blackbeard, sizeof(struct pirate), 1, file)) {
        perror("fwrite");
        return 1;
    } 

    file = fopen("/tmp/pirate", "r");
    if (!file) {
        perror("fopen");
        return 1;
    }
    if (!fread(&p, sizeof(struct pirate), 1, file)) {
        perror("fread");
        return 1;
    }
    if (fclose(file)) {
        perror("fclose");
        return 1;
    } 

    printf("%s, %lu, %u", p.name, p.booty, p.beard_len);

    return 0;
}

