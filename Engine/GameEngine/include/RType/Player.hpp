/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "../AEntity.hpp"

class Player : public virtual GameObject::AEntity
{
public:
    Player(const ulong id, const std::string &name, const std::string &texture)
    {
        this->_id = id;
        this->_name = name;
        this->_type = AEntity::Type::CREATURE;
        this->_pos = {0, 0};
        this->_texture = texture;
        this->_ms = 50;
        this->_dmg = 10;
        // TODO colliders;
        this->addCollider(Physics::Collider::createRect(true, {0, 0}, {32, 18}));
    };
    ~Player();

    virtual void act(std::list<Physics::Collider> colliders)
    {
        auto change = this->compute(colliders);
        this->_pos += change.move;
    };

    virtual void addMovement(sf::Vector2f dir, bool isglobalforce) = 0;
    {
        if (isglobalforce)
            this->addVector(PhysicComponent::POS, dir);
        else {
            auto force = VectorCalc::base_v2(dir);
            force.x *= _ms;
            force.y *= _ms;
            this->addVector(PhysicComponent::POS, force);
        }
    };

    void setDmg(const int dmg) { this->_dmg = dmg; };
    const int &getDmg() { return (this->_dmg); };

protected:
    int _dmg;
    int _ms;

private:
};

#endif /* !PLAYER_HPP_ */
