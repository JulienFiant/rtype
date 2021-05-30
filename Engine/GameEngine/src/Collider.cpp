/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Collider
*/

#include "../include/Physics/Collider.hpp"

Physics::Collider::Collider() : _shape{ShapeType::Point, sf::Vector2f(0, 0)}
{
}

Physics::Collider::~Collider()
{
}

Physics::Collider Physics::Collider::createPoint(bool hard, sf::Vector2f point)
{
    Physics::Collider collider;

    collider._hard = hard;
    collider._shape.type = ShapeType::Point;
    collider._shape.origin = point;
    return (collider);
}

Physics::Collider Physics::Collider::createCircle(bool hard, sf::Vector2f center, float radius)
{
    Physics::Collider collider;

    collider._hard = hard;
    collider._shape.type = ShapeType::Circle;
    collider._shape.origin = center;
    collider._shape.radius = radius;
    return (collider);
}

Physics::Collider Physics::Collider::createRect(bool hard, sf::Vector2f origin, sf::Vector2f size)
{
    Physics::Collider collider;

    collider._hard = hard;
    collider._shape.type = ShapeType::Rect;
    collider._shape.origin = origin;
    collider._shape.width = size.x;
    collider._shape.height = size.y;
    return (collider);
}

void Physics::Collider::baseScale()
{
    switch (this->_shape.type)
    {
    case ShapeType::Point:
        break;
    case ShapeType::Circle:
        this->_shape.radius /= this->_shape.scale.x;
        break;
    case ShapeType::Rect:
        this->_shape.width /= this->_shape.scale.x;
        this->_shape.height /= this->_shape.scale.y;
        break;
    default:
        break;
    }
}
void Physics::Collider::setScale(const sf::Vector2f &scale)
{
    baseScale();
    this->_shape.scale = scale;
    switch (this->_shape.type)
    {
    case ShapeType::Point:
        break;
    case ShapeType::Circle:
        this->_shape.radius *= scale.x;
        break;
    case ShapeType::Rect:
        this->_shape.width *= scale.x;
        this->_shape.height *= scale.y;
        break;
    default:
        break;
    }
}

const bool Physics::Collider::collide(const Physics::Collider &collider)
{
    switch (this->_shape.type)
    {
    case ShapeType::Point:
        return (collidePto(collider));
        break;
    case ShapeType::Circle:
        return (collideCto(collider));
        break;
    case ShapeType::Rect:
        return (collideRto(collider));
        break;
    default:
        break;
    }
    return (false);
}

bool Physics::Collider::collidePto(const Physics::Collider &collider)
{
    switch (collider._shape.type)
    {
    case ShapeType::Point:
        return (this->_shape.origin == collider._shape.origin);
        break;
    case ShapeType::Circle:
        return (VectorCalc::length_v2(this->_shape.origin, collider._shape.origin) < collider._shape.radius);
        break;
    case ShapeType::Rect:
        return (this->_shape.origin.x >= collider._shape.origin.x &&
                this->_shape.origin.x <= collider._shape.origin.x + collider._shape.width &&
                this->_shape.origin.y >= collider._shape.origin.y &&
                this->_shape.origin.y <= collider._shape.origin.y + collider._shape.height);
        break;
    default:
        break;
    }
    return (false);
}
bool Physics::Collider::collideCto(const Physics::Collider &collider)
{
    switch (collider._shape.type)
    {
    case ShapeType::Point:
        return (VectorCalc::length_v2(this->_shape.origin, collider._shape.origin) < this->_shape.radius);
        break;
    case ShapeType::Circle:
        return (VectorCalc::length_v2(this->_shape.origin, collider._shape.origin) < this->_shape.radius + collider._shape.radius);
        break;
    case ShapeType::Rect:
        break;
    default:
        break;
    }
    return (false);
}
bool Physics::Collider::collideRto(const Physics::Collider &collider)
{
    switch (collider._shape.type)
    {
    case ShapeType::Point:
        return (collider._shape.origin.x >= this->_shape.origin.x &&
                collider._shape.origin.x <= this->_shape.origin.x + this->_shape.width &&
                collider._shape.origin.y >= this->_shape.origin.y &&
                collider._shape.origin.y <= this->_shape.origin.y + this->_shape.height);
        break;
    case ShapeType::Circle:
        return (false);
        break;
    case ShapeType::Rect:
        return (sf::FloatRect(this->_shape.origin, sf::Vector2f(this->_shape.width, this->_shape.height)).intersects(sf::FloatRect(collider._shape.origin, sf::Vector2f(collider._shape.width, collider._shape.height))));
        break;
    default:
        break;
    }
    return (false);
}
