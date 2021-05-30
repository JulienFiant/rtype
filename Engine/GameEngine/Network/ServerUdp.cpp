/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** ServerUdp.cpp
*/

#include "ServerUdp.hpp"

ServerUdp::ServerUdp(const int port, int nbp)
{
    this->port = port;
    this->nbp = nbp;
}

ServerUdp::~ServerUdp()
{
    close(fd);
    for (auto it : this->list_player)
        delete it;
}

void ServerUdp::create_serv()
{
    this->fd = socket(AF_INET, SOCK_DGRAM, 17);
    this->serv.sin_family = AF_INET;
    this->serv.sin_port = htons(this->port);
    this->serv.sin_addr.s_addr = INADDR_ANY;
    bind(this->fd, (struct sockaddr *)&this->serv, sizeof(this->serv));
    std::cout << inet_ntoa(serv.sin_addr) << std::endl;
}

void ServerUdp::lobby()
{
    int i = 0;
    int nombre_player = this->nbp;

    std::cout << "Waiting for connection of " << nombre_player << " players" << std::endl;
    while (i < nombre_player)
    {
        ClientInfo *tmp = new ClientInfo(i, this->fd);
        std::thread t{[&] {
            this->list_player.push_back(tmp);
            this->list_player[i]->recv_msg();
            this->list_player[i]->send_msg(std::to_string(i));
        }};
        t.join();
        i += 1;
    }
}

void ServerUdp::show_player()
{
    for (auto it : this->list_player)
    {
        std::cout << "Player number : " << it->get_id() << std::endl;
        std::cout << "Ip address : " << it->get_addr() << std::endl;
        std::cout << std::endl;
    }
}

int ServerUdp::send_msg_all()
{
    for (auto it : this->list_player)
    {
        it->send_msg("Vous etes la !");
    }
    return (0);
}

int ServerUdp::send_msg(std::string msg)
{
    for (auto it : this->list_player)
        it->send_msg(msg);
    return (0);
}

std::vector<std::string> ServerUdp::split(std::string phrase, std::string delimiter)
{
    std::vector<std::string> list;
    std::string s = phrase;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);
    return (list);
}

std::string ServerUdp::recv_msg()
{
    return ("");
}

std::string ServerUdp::get_string_pos()
{
    std::string all_pos = "&";
    int cn = 0;

    // add pos player de la forme "&0[x-y&1[x1-y1..."
    int tot = this->list_player.size();
    for (auto m : this->list_player)
    {
        float *tmp = m->get_pos();
        // id
        all_pos += std::to_string(cn);
        all_pos += "[";
        // pos
        std::string tmp1 = std::to_string(tmp[0]);
        all_pos += tmp1.substr(0, tmp1.find(".") + 3);
        all_pos += "-";
        tmp1 = std::to_string(tmp[1]);
        all_pos += tmp1.substr(0, tmp1.find(".") + 3);
        if (cn + 1 < tot)
            all_pos += "&";
        cn += 1;
    }

    // add all other pos (ennemies, projectiles)
//    std::cout << all_pos << std::endl;
    return (all_pos);
}

void ServerUdp::start_game()
{
    while (1)
    {
        this->send_pos();
        this->send_get_pos();
        //this->get_action();
    }
    this->send_end();
}

void ServerUdp::get_action()
{
    for (auto it : this->list_player)
    {
        int action = std::stoi(it->recv_msg());
        it->set_action(action);
        // TODO calcul pos and set pos
    }
}

void ServerUdp::send_pos()
{
    std::string pos = this->get_string_pos();
    this->send_msg("Player_pos_set");
    this->send_msg(pos);
}

void ServerUdp::send_end()
{
    this->send_msg("end");
}

void ServerUdp::send_get_pos()
{
    this->send_msg("Player_pos_get");
    std::string tmp = "";
    std::vector<std::string> list_tmp;
    for (auto it : this->list_player)
    {
        tmp = it->recv_msg();
        list_tmp = split(tmp, "-");
        it->set_pos(std::stof(list_tmp[0]), std::stof(list_tmp[1]));
//        std::cout << it->get_pos()[0] << " " << it->get_pos()[1] << std::endl;
    }
}