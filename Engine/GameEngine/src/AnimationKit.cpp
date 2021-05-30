/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AnimationKit
*/

#include "../include/Graphics/AnimationKit.h"

AnimationKit::AnimationKit()
{
    this->_inUse = this->_kit.end();
}

AnimationKit::~AnimationKit()
{
}

void AnimationKit::set(const Anim anim, AAnimation *animation, bool use)
{
    this->_kit[anim] = animation;
    if (use)
        this->use(anim);
}

void AnimationKit::use(const Anim anim)
{
    if (this->_inUse != this->_kit.end())
        this->_inUse->second->stop();
    this->_inUse = this->_kit.find(anim);
    this->_inUse->second->play();
}

AAnimation *AnimationKit::inUse()
{
    return (this->_inUse->second);
}

sf::FloatRect AnimationKit::get()
{
    if (this->_kit.size() > 0 && this->_inUse != this->_kit.end())
        return (this->_inUse->second->get());
    else
        return (sf::FloatRect(0, 0, 0, 0));
}
