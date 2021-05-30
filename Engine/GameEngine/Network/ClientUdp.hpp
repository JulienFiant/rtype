/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** ClientUdp.hpp
*/

#ifndef _CLIENT_UDP_
#define _CLIENT_UDP_

#include "INetwork.hpp"

class ClientUdp : virtual public INetwork
{
public:
    ClientUdp(std::string addr = "10.20.85.141", int port = 9000);
    ~ClientUdp();
    void create_cli();
    virtual int send_msg(std::string msg);
    virtual std::string recv_msg();
    float *get_pos();
    std::vector<std::string> split(std::string phrase, std::string delimiter);
    void set_pos(std::string pos);
    void set_pos(int id, float x, float y);
    void start_game();
    std::vector<float *> get_all_pos();
    void set_action(int id);
    int get_action();

private:
    std::vector<float *> pos_player;
    int id;
    int action;
};

#endif