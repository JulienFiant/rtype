//
// EPITECH PROJECT, 2018
// VectorCalc
// File description:
// process SFML vectors
//

#include "VectorCalc.hpp"

double VectorCalc::length_v2(sf::Vector2u v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}

double VectorCalc::length_v2(sf::Vector2u v1, sf::Vector2u v2)
{
    return sqrt(((v2.x - v1.x) * (v2.x - v1.x)) + ((v2.y - v1.y) * (v2.y - v1.y)));
}

double VectorCalc::length_v2(sf::Vector2f v1, sf::Vector2f v2)
{
    return sqrt(((v2.x - v1.x) * (v2.x - v1.x)) + ((v2.y - v1.y) * (v2.y - v1.y)));
}

sf::Vector2f VectorCalc::base_v2(sf::Vector2u v)
{
    sf::Vector2f ret(v.x, v.y);
    double len = length_v2(v);
    ret.x = ((double)ret.x) / len;
    ret.y = ((double)ret.y) / len;
    return ret;
}

sf::Vector2f VectorCalc::base_v2(sf::Vector2u v1, sf::Vector2u v2)
{
    sf::Vector2f ret((float)v2.x - (float)v1.x, (float)v2.y - (float)v1.y);
    double len = length_v2(v1, v2);
    ret.x = ((double)ret.x) / len;
    ret.y = ((double)ret.y) / len;
    return ret;
}
