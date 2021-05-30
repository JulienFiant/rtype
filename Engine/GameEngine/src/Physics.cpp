/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Physics
*/

#include "../include/Physics/Physics.hpp"

Physics::t_Tranform Physics::PhysicComponent::compute(std::list<Collider> colliders)
{
    t_Tranform transform;
    float t_elapsed = GameEngine::get().getTime() - this->_time;
    bool obstacle = false;

    this->_time = GameEngine::get().getTime();
    for (auto var : this->_translators)
    {
        transform.move.x += var.x;
        transform.move.y += var.y;
    }
    for (auto var : this->_scalers)
    {
        transform.scale.x += var.x;
        transform.scale.y += var.y;
    }
    for (auto var : this->_rotators)
    {
        transform.rotate += var;
    }
    transform.move *= t_elapsed;
    transform.scale *= t_elapsed;
    transform.rotate *= t_elapsed;

    for (auto var : this->_colliders)
    {
        var.move(transform.move);
        var.setScale(var.getScale() + transform.scale);
        if (var.isHard())
        {
            for (auto comp : colliders)
            {
                if (comp.isHard() && var.collide(comp))
                {
                    obstacle = true;
                    break;
                }
            }
            if (obstacle)
            {
                var.move(-transform.move);
                var.setScale(var.getScale() - transform.scale);
                transform.move = {0, 0};
                break;
            }
        }
    }

    return (transform);
}

bool Physics::PhysicComponent::collide(const Physics::PhysicComponent &component)
{
    for (auto var : this->_colliders)
    {
        for (auto comp : component._colliders)
        {
            if (var.collide(comp))
                return (true);
        }
    }
    return (false);
}
