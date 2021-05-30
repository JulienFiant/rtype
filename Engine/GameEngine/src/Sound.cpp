/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Sound
*/

#include "../include/Audio/Sound.h"

MySound::MySound()
{
    this->_type = IAudio::AudioType::Sound;
    this->_sound.setBuffer(this->_buffer);
}

MySound::~MySound()
{
}

void MySound::load(const std::string &file)
{
    this->_buffer.loadFromFile(file);
}

void MySound::play()
{
    this->_sound.play();
}

void MySound::pause()
{
    this->_sound.pause();
}

void MySound::stop()
{
    this->_sound.stop();
}

int MySound::getStatus()
{
    return (this->_sound.getStatus());
}