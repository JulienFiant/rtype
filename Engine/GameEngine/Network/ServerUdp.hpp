/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** ServerUdp.hpp
*/

#ifndef _SERVER_UDP_
#define _SERVER_UDP_

#include "INetwork.hpp"
#include "ClientInfo.hpp"

class ServerUdp : virtual public INetwork
{
public:
    ServerUdp(const int port, int nbp);
    ~ServerUdp();
    void create_serv();
    void lobby();
    void show_player();
    int send_msg_all();
    virtual int send_msg(std::string msg);
    virtual std::string recv_msg();
    std::string get_string_pos();
    void start_game();
    void get_action();
    void send_pos();
    void send_end();
    void send_get_pos();
    std::vector<std::string> split(std::string phrase, std::string delimiter);

private:
    std::vector<ClientInfo *> list_player;
    int nbp;
};

#endif