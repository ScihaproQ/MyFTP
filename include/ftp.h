/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#ifndef NWP_MYFTP_2019_FTP_H
#define NWP_MYFTP_2019_FTP_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>

int init_server(int port);

int handle_client(int server_fd);

void connected(int fd);

void user(int fd);

void pass(int fd);

void quit(int fd);

void noop(int fd);

typedef void (*messages[])(int);

enum MESSAGES_CODES {
    CONNECTED,
    USER,
    PASS,
    QUIT,
    NOOP,
};
#endif //NWP_MYFTP_2019_FTP_H
