/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** CPhysic
*/

#ifndef CPHYSIC_HPP_
#define CPHYSIC_HPP_

#include "../Physics/Physics.hpp"
#include "./GCAnimated.h"

class CPhysicAnimated : public virtual Physics::PhysicComponent, public virtual GCAnimated
{
public:
    CPhysicAnimated(const std::string &name, const std::string &texture);
    ~CPhysicAnimated();

    virtual void setPos(float x, float y)
    {
        auto spos = this->_sprite.getPosition();
        for(auto var : _colliders)
        {
            auto tmp = var.getPos();
            var.setPos(x + tmp.x - spos.x, y + tmp.y - spos.y);
        }
        GCAnimated::setPos(x, y);
    };

    virtual void setPos(const sf::Vector2f &pos)
    {
        setPos(pos.x, pos.y);
    };

    virtual bool draw();
};

#endif /* !CPHYSIC_HPP_ */
