/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** ClientInfo.hpp
*/

#ifndef _CLIENTINFO_
#define _CLIENTINFO_

#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <thread>

class ClientInfo
{
public:
    ClientInfo(int id, int fd);
    ~ClientInfo();
    int send_msg(std::string msg);
    std::string recv_msg();
    std::string get_addr();
    int get_id();
    float *get_pos();
    void set_pos(float x, float y);
    void set_action(int id);
    int get_action();

private:
    std::string addr;
    int fd;
    struct sockaddr_in client;
    int id;
    std::vector<float *> pos_player;
    int action;
};

#endif