/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Colliders
*/

#ifndef COLLIDERS_HPP_
#define COLLIDERS_HPP_

#include "../../SfmlTools/Math/VectorCalc.hpp"
#include "../../SfmlTools/Math/Trigonometry.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace Physics
{
class Collider
{
public:
    ~Collider();

    enum ShapeType
    {
        Point,
        Circle,
        Rect,
    };

    typedef struct s_vector2f
    {
        float x, y;
    } vetor2f;

    typedef struct s_2dShape
    {
        ShapeType type;
        sf::Vector2f origin;
        sf::Vector2f scale;

        union {
            struct
            {
                float radius;
            };
            struct
            {
                float width;
                float height;
            };
        };
    } Shape2d;

    static Collider createPoint(bool hard, sf::Vector2f point);
    static Collider createCircle(bool hard, sf::Vector2f center, float radius);
    static Collider createRect(bool hard, sf::Vector2f origin, sf::Vector2f size);

    void setPos(float x, float y)
    {
        this->_shape.origin.x = x;
        this->_shape.origin.y = y;
    };
    void setPos(const sf::Vector2f &pos) { this->_shape.origin = pos; };
    void move(const sf::Vector2f &pos) { this->_shape.origin += pos; };
    void setScale(const sf::Vector2f &pos);

    const sf::Vector2f &getPos() { return (this->_shape.origin); };
    const sf::Vector2f &getScale() { return (this->_shape.scale); };

    const bool isHard()
    {
        return (_hard);
    };

    const bool collide(const Collider &collider);

    Shape2d _shape;

private:
    Collider();
    bool _hard;

    void baseScale();
    bool collidePto(const Collider &collider);
    bool collideCto(const Collider &collider);
    bool collideRto(const Collider &collider);
};
} // namespace Physics

#endif /* !COLLIDERS_HPP_ */
