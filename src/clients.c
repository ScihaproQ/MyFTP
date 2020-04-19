/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "ftp.h"

static messages list = {&connected, &user, &pass, &quit, &noop};

int read_client(int fd)
{
    FILE *fp = fdopen(fd, "r");
    char buffer[512];
    char *b = buffer;
    size_t bufsize = 512;

    getline(&b, &bufsize, fp);
    if (strncasecmp(b, "user anonymous", 14) == 0)
        list[USER](fd);
    if (strncasecmp(b, "pass", 4) == 0)
        list[PASS](fd);
    if (strncasecmp(b, "noop", 4) == 0)
        list[NOOP](fd);
    if (strncasecmp(b, "quit", 4) == 0) {
        list[QUIT](fd);
        return -1;
    }
    return 0;
}

int handle_client(int server_fd)
{
    fd_set active;
    fd_set read;
    int i = 0;
    struct sockaddr_in address;
    size_t size;
    int client = 0;

    FD_ZERO(&active);
    FD_SET(server_fd, &active);
    while (1) {
        read = active;
        if (select(FD_SETSIZE, &read, NULL, NULL, NULL) < 0)
            return 84;
        for (i = 0; i < FD_SETSIZE; ++i) {
            if (FD_ISSET (i, &read)) {
                if (i == server_fd) {
                    size = sizeof(address);
                    client = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &size);
                    if (client < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                    }
                    list[CONNECTED](client);
                    FD_SET (client, &active);
                } else {
                    if (read_client(i) < 0) {
                        close(i);
                        FD_CLR(i, &active);
                    }
                }
            }
        }
    }
}