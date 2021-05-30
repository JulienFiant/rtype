/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** NoAnimation
*/

#include "../include/Graphics/NoAnimation.h"

NoAnimation::NoAnimation(sf::FloatRect rect) : AAnimation()
{
    this->_rect = rect;
}

NoAnimation::~NoAnimation()
{
}

void NoAnimation::stop()
{
    this->_status = Status::STOP;
}

void NoAnimation::pause()
{
    this->_status = Status::PAUSE;
}

void NoAnimation::play()
{
    this->_status = Status::PLAY;
}

sf::FloatRect NoAnimation::get()
{
    return (this->_rect);
}