/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** ClientUdp.cpp
*/

#include "ClientUdp.hpp"

ClientUdp::ClientUdp(std::string addr, int port)
{
	this->addr = addr;
	this->port = port;
	this->id = -1;
	this->action = -1;
}

ClientUdp::~ClientUdp()
{
	close(fd);
}

void ClientUdp::set_action(int id)
{
	this->action = id;
}

int ClientUdp::get_action()
{
	return (this->action);
}

void ClientUdp::create_cli()
{
	this->fd = socket(AF_INET, SOCK_DGRAM, 17);
	this->serv.sin_family = AF_INET;
	this->serv.sin_port = htons(this->port);
	this->serv.sin_addr.s_addr = inet_addr(this->addr.c_str());
}

int ClientUdp::send_msg(std::string msg)
{
	const char *buffer = msg.c_str();
	socklen_t m = sizeof(this->serv);

	sendto(this->fd, buffer, msg.size(), 0, (struct sockaddr *)&this->serv, m);
	return (0);
}

std::string ClientUdp::recv_msg()
{
	char buffer[256];
	std::string ret = "";
	for (int p = 0; p < 256; p++)
		buffer[p] = '\0';
	socklen_t l = sizeof(this->client);
	int rc = recvfrom(this->fd, buffer, 256, 0, (struct sockaddr *)&this->client, &l);
	if (rc < 0)
	{
		std::cout << "ERROR READING FROM SOCKET";
		return (ret);
	}
	if (this->id == -1)
		this->id = atoi(buffer);
	ret = buffer;
//	std::cout << "the message received is : " << buffer << std::endl;
	return (ret);
}

float *ClientUdp::get_pos()
{
	return (this->pos_player[this->id]);
}

std::vector<std::string> ClientUdp::split(std::string phrase, std::string delimiter)
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

void ClientUdp::set_pos(int id, float x, float y)
{
	this->pos_player[id][0] = x;
	this->pos_player[id][1] = y;
}

void ClientUdp::set_pos(std::string pos)
{
	int first = 0;

	// add pos player from network
	if (this->pos_player.empty())
		first = 1;

	std::vector<std::string> tmp = split(pos, "&");
	std::vector<std::string> tmp_2;
	std::vector<std::string> tmp_3;
	int index = 0;
	for (auto it_tmp : tmp)
	{
		if (!it_tmp.empty())
		{
			tmp_2 = split(it_tmp, "[");
			if (std::stoi(tmp_2[0]) < 4)
			{
				tmp_3 = split(tmp_2[1], "-");
				if (first == 1)
					this->pos_player.push_back(new float());
				this->pos_player[index][0] = std::stof(tmp_3[0]);
				this->pos_player[index][1] = std::stof(tmp_3[1]);
				//std::cout << this->pos_player[index][0] << " " << this->pos_player[index][1] << std::endl;
				index += 1;
			}
		}
	}
}

std::vector<float *> ClientUdp::get_all_pos()
{
	return (this->pos_player);
}

void ClientUdp::start_game()
{
	std::string cmd = "";
	cmd = this->recv_msg();
	//std::cout << cmd << std::endl;
	if (cmd.find("Player_pos_set") != std::string::npos)
	{
		cmd = this->recv_msg();
		this->set_pos(cmd);
	}
	else if (cmd.find("Player_pos_get") != std::string::npos)
	{
		cmd = std::to_string(this->get_pos()[0]) + "-" + std::to_string(this->get_pos()[1]);
		this->send_msg(cmd);
		// TODO envoie de l'action
	}
	else if (cmd.find("end") != std::string::npos)
		return;
}