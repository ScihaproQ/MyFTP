/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "ftp.h"

int init_server(int port)
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;

    if (server_fd == 0)
        return -1;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
        return -1;
    return server_fd;
}