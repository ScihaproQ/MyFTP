/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "ftp.h"

int main(int ac, char **av)
{
    long port = 0;
    char *end = NULL;
    int server = 0;

    if (ac != 3)
        return 84;
    port = strtol(av[1], &end, 10);
    if (errno != ERANGE)
        server = init_server((int)port);
    if (listen(server, 3) < 0)
        return 84;
    handle_client(server);
}