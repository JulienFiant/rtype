/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** INetwork.hpp
*/

#ifndef _INETWORK_
#define _INETWORK_

#include<iostream>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

class INetwork
{
public :
    virtual ~INetwork(){};

    virtual int send_msg(std::string msg) = 0;
    virtual std::string recv_msg() = 0;
protected :
    std::string addr;
    int port;
    int fd;
    struct sockaddr_in serv;
    struct sockaddr_in client;
};

#endif