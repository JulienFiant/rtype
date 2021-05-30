/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Music
*/

#include "../include/Audio/Music.h"

MyMusic::MyMusic()
{
    this->_type = IAudio::AudioType::Music;
    this->_music.setLoop(true);
}

MyMusic::~MyMusic()
{
}

void MyMusic::load(const std::string &file)
{
    this->_music.openFromFile(file);
}

void MyMusic::play()
{
    this->_music.play();
}

void MyMusic::pause()
{
    this->_music.pause();
}

void MyMusic::stop()
{
    this->_music.stop();
}

int	MyMusic::getStatus()
{
	return (this->_music.getStatus());
}