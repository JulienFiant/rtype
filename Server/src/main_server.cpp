/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** main_server.cpp
*/

#include <GameEngine/Network/ServerUdp.hpp>
#include <GameEngine/include/Graphics/GraphicEngine.h>
#include <GameEngine/include/Graphics/GCBasic.h>
#include <GameEngine/include/Graphics/GCAnimated.h>
#include <GameEngine/include/Graphics/SceneSfml.h>
#include <GameEngine/include/Graphics/AnimationBasic.h>

using namespace std;

int main(int ac, char **av)
{
    if (ac != 2)
    {
        auto p = new ServerUdp(9000, 4);
        p->create_serv();
        p->lobby();
        p->show_player();
        p->send_msg_all();
        p->start_game();
    }
    else
    {
        auto p = new ServerUdp(9000, atoi(av[1]));
        p->create_serv();
        p->lobby();
        p->show_player();
        p->send_msg_all();
        p->start_game();
    }
}