/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Animation
*/

#include "../include/Graphics/AnimationBasic.h"

AnimationBasic::AnimationBasic(sf::FloatRect rect, Direction dir, uint count, float duration, bool loop, int margin) : AAnimation()
{
    this->_count = count;
    this->_dir = dir;
    this->_fps = duration / (float)count;
    this->_loop = loop;
    this->_rect = rect;
    this->_margin = margin;
    this->i = 0;
    this->_time = GraphicEngine::get().getTime();
    this->_status = Status::STOP;
}

AnimationBasic::~AnimationBasic()
{
}

void AnimationBasic::stop()
{
    this->_time = GraphicEngine::get().getTime();
    this->_status = Status::STOP;
    moveBy(-i);
    this->i = 0;
}

void AnimationBasic::pause()
{
    this->delta = GraphicEngine::get().getTime() - this->_time;
    this->_status = Status::PAUSE;
}

void AnimationBasic::play()
{
    if (this->_status == Status::STOP)
    {
        this->_time = GraphicEngine::get().getTime();
        this->i = 0;
    }
    this->_status = Status::PLAY;
}

sf::FloatRect AnimationBasic::get()
{
    if (this->_status == Status::PLAY)
    {
        float time = ((GraphicEngine::get().getTime() - this->_time) - this->_fps) / this->_fps;
        if (this->i < _count - 1 && time >= 0.0f)
        {
            moveBy(int(time) + 1);
            this->i += int(time) + 1;
            if (_loop && this->i >= _count - 1)
            {
                moveBy(-_count + 1);
                this->i = 0;
            }
            this->_time = GraphicEngine::get().getTime();
        }
    }
    else if (this->_status == Status::STOP)
        this->_time = GraphicEngine::get().getTime();
    else if (this->_status == Status::PAUSE)
        this->_time = GraphicEngine::get().getTime() - this->delta;
    return (this->_rect);
}

void AnimationBasic::moveBy(int count)
{
    switch (this->_dir)
    {
    case Direction::DOWN:
        this->_rect.top += count * (_rect.height + _margin);
        break;
    case Direction::LEFT:
        this->_rect.left -= count * (_rect.width + _margin);
        break;
    case Direction::RIGHT:
        this->_rect.left += count * (_rect.width + _margin);
        break;
    case Direction::UP:
        this->_rect.top -= count * (_rect.height + _margin);
        break;
    default:
        break;
    }
}