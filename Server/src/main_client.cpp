#include <GameEngine/Network/ClientUdp.hpp>

using namespace std;

void error( char *msg)
{
 perror(msg);
 exit(EXIT_FAILURE);
}

int main()
{
    ClientUdp* p = new ClientUdp();
    p->create_cli();
    // envoie au server salut je me co
    p->send_msg("salut");
    // confirmation et recup nombre id player
    p->recv_msg();
    // confirmation que le lobby est full
    p->recv_msg();

    //loop de jeu
    p->start_game();
}