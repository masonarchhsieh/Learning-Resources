/*
 * =====================================================================================
 *
 *       Filename:  poll_example.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/25/2019 07:31:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <poll.h>                           //http://pubs.opengroup.org/onlinepubs/7908799/xsh/poll.h.html
#include <unistd.h>

int main(int argc, char **argv) 
{
    struct pollfd fds[2];
    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;

    fds[1].fd = STDOUT_FILENO;
    fds[1].events = POLLOUT;

    int err = poll(fds, (nfds_t) 2, 0);      // nfds_t: all unsigned integral type used for the number of file descriptors
    if (err == -1) {
        perror("poll");
        return -1;
    }

    if (fds[0].revents & POLLIN) {
        printf("STDIN ready\n");
    }
     if (fds[1].revents & POLLOUT) {
        printf("STDOUT ready\n");
    }
   
    return 0; 
}
