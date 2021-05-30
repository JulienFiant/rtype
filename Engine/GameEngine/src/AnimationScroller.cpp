/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AnimationScroller
*/

#include "../include/Graphics/AnimationScroller.h"

AnimationScroller::AnimationScroller(sf::FloatRect rect, Direction dir, float speed, bool pausable) : AAnimation()
{
    this->_dir = dir;
    this->_rect = rect;
    this->_pausable = pausable;
    this->_speed = speed;
    this->_time = GraphicEngine::get().getTime();
    this->_status = Status::STOP;
}

AnimationScroller::~AnimationScroller()
{
}

void AnimationScroller::stop()
{
    this->_time = GraphicEngine::get().getTime();
    this->_status = Status::STOP;
}

void AnimationScroller::pause()
{
    this->delta = GraphicEngine::get().getTime() - this->_time;
    this->_status = Status::PAUSE;
}

void AnimationScroller::play()
{
    if (this->_status == Status::STOP)
    {
        this->_time = GraphicEngine::get().getTime();
    }
    this->_status = Status::PLAY;
}

sf::FloatRect AnimationScroller::get()
{
    if (this->_status == Status::PLAY)
    {
        float dtime = (GraphicEngine::get().getTime() - this->_time);
        moveBy(dtime);
        this->_time = GraphicEngine::get().getTime();
    }
    else if (this->_status == Status::STOP)
        this->_time = GraphicEngine::get().getTime();
    else if (this->_status == Status::PAUSE)
        this->_time = GraphicEngine::get().getTime() - this->delta;
    return (this->_rect);
}

void AnimationScroller::moveBy(float count)
{
    switch (this->_dir)
    {
    case Direction::DOWN:
        this->_rect.top += count * (this->_speed);
        break;
    case Direction::LEFT:
        this->_rect.left -= count * (this->_speed);
        break;
    case Direction::RIGHT:
        this->_rect.left += count * (this->_speed);
        break;
    case Direction::UP:
        this->_rect.top -= count * (this->_speed);
        break;
    default:
        break;
    }
}