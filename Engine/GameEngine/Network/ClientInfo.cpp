/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** ClientInfo.cpp
*/

#include "ClientInfo.hpp"

ClientInfo::ClientInfo(int id, int fd)
{
    this->id = id;
    this->fd = fd;
    this->addr = "";
    this->pos_player.push_back(new float());
    this->pos_player[0][0] = 100.1f;
    this->pos_player[0][1] = 100.1f;
    this->action = -1;
}

ClientInfo::~ClientInfo()
{
}

void ClientInfo::set_action(int id)
{
    this->action = id;
}

int ClientInfo::get_action()
{
    return (this->action);
}

int ClientInfo::send_msg(std::string msg)
{
    const char *buffer = msg.c_str();
    socklen_t l = sizeof(this->client);
    int rp= sendto(this->fd,buffer,msg.size(),0,(struct sockaddr *)&this->client,l);
    if(rp<0)
    {
        std::cout<<"ERROR writing to SOCKET";
        return (84);
    } 
    return (0);
}

std::string ClientInfo::recv_msg()
{
    char buffer[256];
    std::string ret = "";
    for (int p = 0; p < 256; p++)
        buffer[p] = '\0';
    socklen_t l = sizeof(this->client);
    int rc = recvfrom(this->fd,buffer,256,0,(struct sockaddr *)&this->client,&l);
    if (this->addr.empty())
        this->addr = inet_ntoa(client.sin_addr);
    if(rc < 0)
    {
        std::cout<<"ERROR READING FROM SOCKET";
        return (ret);
    }
    ret = buffer;
//    std::cout<<"the message received is : "<< buffer <<std::endl;
    return (ret);
}

std::string ClientInfo::get_addr()
{
    return (this->addr);
}

int ClientInfo::get_id()
{
    return (id);
}

float* ClientInfo::get_pos()
{
    return (this->pos_player[0]);
}

void ClientInfo::set_pos(float x, float y)
{
    this->pos_player[0][0] = x;
    this->pos_player[0][1] = y;
}