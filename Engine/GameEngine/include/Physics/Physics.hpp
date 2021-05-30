/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Physics
*/

#ifndef PHYSICS_HPP_
#define PHYSICS_HPP_

#include "../../SfmlTools/Math/VectorCalc.hpp"
#include "../../SfmlTools/Math/Trigonometry.hpp"
#include "../GameEngine.hpp"
#include "./Collider.hpp"
#include <SFML/Graphics.hpp>
#include <list>

namespace Physics
{

typedef struct transform
{
    sf::Vector2f move;
    float rotate;
    sf::Vector2f scale;
} t_Tranform;

class PhysicComponent
{
public:
    PhysicComponent(){};
    ~PhysicComponent(){};

    enum PhysScales
    {
        POS,
        SIZE
    };

    void addVector(float angle)
    {
        _rotators.push_back(angle);
    };

    void addVector(PhysScales parameter, sf::Vector2f value)
    {
        if (parameter == PhysScales::POS)
            _translators.push_back(value);
        else if (parameter == PhysScales::SIZE)
            _scalers.push_back(value);
    };

    void addCollider(const Collider &collider)
    {
        this->_colliders.push_back(collider);
    };

    void clearTrans()
    {
        _translators.clear();
    };
    void clearRotate()
    {
        _rotators.clear();
    };
    void clearScale()
    {
        _scalers.clear();
    };

    void init()
    {
        this->_time = GameEngine::get().getTime();
    };

    t_Tranform compute(std::list<Collider> colliders);
    bool collide(const Physics::PhysicComponent &component);

protected:
    float _time;

    std::list<sf::Vector2f> _translators;
    std::list<float> _rotators;
    std::list<sf::Vector2f> _scalers;
    std::list<Collider> _colliders;
};
} // namespace Physics
#endif /* !PHYSICS_HPP_ */
