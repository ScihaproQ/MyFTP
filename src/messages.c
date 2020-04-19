/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "ftp.h"

void connected(int fd)
{
    write(fd, "220 | Welcome to my ftp server!\n", 32);
}

void user(int fd)
{
    write(fd, "331 | Now enter password...\n", 28);
}

void pass(int fd)
{
    write(fd, "230 | Logged in!\n", 17);
}

void quit(int fd)
{
    write(fd, "221 | Session closed!\n", 21);
}

void noop(int fd)
{
    write(fd, "200 | Noop noop\n", 16);
}