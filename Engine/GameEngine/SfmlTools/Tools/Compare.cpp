/*
** EPITECH PROJECT, 2019
** Sfml
** File description:
** Compare
*/

#include "Compare.hpp"
#include <iostream>

float fullAngle(float a)
{
    int npi = abs(a) / (2 * M_PI);
    return (a - (2 * M_PI) * npi);
}

template <typename T>
bool Comparator::betwin(T value, T min, T max, bool inclusive)
{
    T tmp = min;

    if (min > max)
    {
        min = max;
        max = tmp;
    }
    if (inclusive)
    {
        if (value >= min && value <= max)
            return true;
    }
    else if (value > min && value < max)
        return true;
    return false;
}

bool Comparator::betwinAngle(float value, float min, float max, bool inclusive)
{
    value = fullAngle(value);
    min = fullAngle(min);
    max = fullAngle(max);
    if (max < min)
        max += 2 * M_PI;
    if (inclusive)
    {
        if (value >= min - 2 * M_PI && value <= max - 2 * M_PI)
            return true;
        if (value >= min && value <= max)
            return true;
        if (value >= min + 2 * M_PI && value <= max + 2 * M_PI)
            return true;
    }
    else
    {
        if (value > min - 2 * M_PI && value < max - 2 * M_PI)
            return true;
        if (value > min && value < max)
            return true;
        if (value > min + 2 * M_PI && value < max + 2 * M_PI)
            return true;
    }
    return false;
}

bool Comparator::within(sf::Vector2f point, sf::FloatRect rect)
{
    if (point.x >= rect.left && point.x < (rect.left + rect.width) && point.y >= rect.top && point.y < (rect.top + rect.height))
        return true;
    return false;
}
bool Comparator::within(sf::Vector2f point, sf::IntRect rect)
{
    if (point.x >= rect.left && point.x < (rect.left + rect.width) && point.y >= rect.top && point.y < (rect.top + rect.height))
        return true;
    return false;
}
/*
bool Compare::within(sf::Vector2f point, sf::CircleShape circle)
{
    return false;
}
*/
sf::FloatRect Comparator::overlapRect(const sf::FloatRect &r1, const sf::FloatRect &r2)
{
    sf::FloatRect result;
    float p1[2][2] = {{r1.left + ((r1.width < 0.0f) ? r1.width : 0.0f), r1.top + ((r1.height < 0.0f) ? r1.height : 0.0f)},
                      {r1.left + ((r1.width > 0.0f) ? r1.width : 0.0f), r1.top + ((r1.height > 0.0f) ? r1.height : 0.0f)}};
    float p2[2][2] = {{r2.left + ((r2.width < 0.0f) ? r2.width : 0.0f), r2.top + ((r2.height < 0.0f) ? r2.height : 0.0f)},
                      {r2.left + ((r2.width > 0.0f) ? r2.width : 0.0f), r2.top + ((r2.height > 0.0f) ? r2.height : 0.0f)}};
    (p2[0][0] < p1[0][0]) ? p2[0][0] = p1[0][0] : 0;
    (p2[0][1] < p1[0][1]) ? p2[0][1] = p1[0][1] : 0;
    (p2[1][0] > p1[1][0] - 1) ? p2[1][0] = p1[1][0] - 1 : 0;
    (p2[1][1] > p1[1][1] - 1) ? p2[1][1] = p1[1][1] - 1 : 0;
    (p2[1][0] < p2[0][0] - 1) ? p2[1][0] = p2[0][0] - 1 : 0;
    (p2[1][1] < p2[0][1] - 1) ? p2[1][1] = p2[0][1] - 1 : 0;
    if (r2.width < 0 && r2.height < 0)
        result = sf::FloatRect(p2[1][0], p2[1][1], p2[0][0] - p2[1][0], p2[0][1] - p2[1][1]);
    else if (r2.width < 0)
        result = sf::FloatRect(p2[1][0], p2[0][1], p2[0][0] - p2[1][0], p2[1][1] - p2[0][1]);
    else if (r2.height < 0)
        result = sf::FloatRect(p2[0][0], p2[1][1], p2[1][0] - p2[0][0], p2[0][1] - p2[1][1]);
    else
        result = sf::FloatRect(p2[0][0], p2[0][1], p2[1][0] - p2[0][0], p2[1][1] - p2[0][1]);
    return result;
}
