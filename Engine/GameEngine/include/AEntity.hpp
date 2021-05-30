/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IEntity
*/

#ifndef IENTITY_H_
#define IENTITY_H_

#include <iostream>
#include <SFML/Graphics/Rect.hpp>
#include "./Physics.h"
#include "../SfmlTools/Math/VectorCalc.hpp"

namespace GameObject
{
enum Action
{
    IDLE,
    MOVE_U,
    MOVE_D,
    MOVE_L,
    MOVE_R,
    ATTACK,
    TAKE_DMG,
};

class AEntity : public virtual Physics::PhysicComponent
{
public:
    enum Type
    {
        BONUS,
        CREATURE,
        BULLET,
    };

    virtual ~AEntity(){};

    const ulong getId() const { return (this->_id); };
    const std::string &getName() const { return (this->_name); };
    const AEntity::Type getType() const { return (this->_type); };
    const sf::Vector2f getPos() const { return (this->_pos); };
    const std::string &getTexture() const { return (this->_texture); };

    virtual void act(std::list<Physics::Collider> colliders) = 0;

    void setPos(float x, float y)
    {
        auto spos = this->_pos;
        for (auto var : _colliders)
        {
            auto tmp = var.getPos();
            var.setPos(x + tmp.x - spos.x, y + tmp.y - spos.y);
        }
        this->_pos = {x, y};
    };
    void setPos(const sf::Vector2f &pos)
    {
        setPos(pos.x, pos.y);
    };
    void setTexture(const std::string &name) { this->_name = name; };

    void clearForces() { this->clearTrans(); };

    virtual void addMovement(sf::Vector2f dir, bool isglobalforce) = 0;

protected:
    ulong _id;
    std::string _name;
    Type _type;
    sf::Vector2f _pos;
    std::string _texture;
};
} // namespace GameObject

#endif /* !IENTITY_H_ */
